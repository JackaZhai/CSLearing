from flask import Flask, render_template, request, jsonify
import requests
from collections import defaultdict
import math
import heapq
import logging
import traceback
import json
import os
from logging.handlers import RotatingFileHandler

class Logger:
    """配置和管理日志记录的类"""

    def __init__(self, log_dir='logs', log_file='transit.log', max_bytes=10 * 1024 * 1024, backup_count=5):
        if not os.path.exists(log_dir):
            os.makedirs(log_dir)

        formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')

        # 文件处理器
        file_handler = RotatingFileHandler(
            os.path.join(log_dir, log_file),
            maxBytes=max_bytes,
            backupCount=backup_count,
            encoding='utf-8'
        )
        file_handler.setFormatter(formatter)
        file_handler.setLevel(logging.DEBUG)

        # 控制台处理器
        console_handler = logging.StreamHandler()
        console_handler.setFormatter(formatter)
        console_handler.setLevel(logging.DEBUG)

        # 配置根日志记录器
        logging.root.setLevel(logging.DEBUG)
        logging.root.addHandler(file_handler)
        logging.root.addHandler(console_handler)


class TransitGraph:
    """管理公交图数据结构的类"""

    def __init__(self):
        self.clear()
        logging.info("创建新的TransitGraph实例")

    def clear(self):
        self.stations = {}  # {station_id: {'name': name, 'location': (lat, lng)}}
        self.routes = defaultdict(list)  # {station_id: [(next_station_id, line_number, distance)]}
        self.lines = defaultdict(set)  # {line_number: set(station_ids)}
        logging.info("清空图数据")

    def add_station(self, station_id, name, location):
        try:
            station_id = str(station_id)
            if station_id not in self.stations:
                self.stations[station_id] = {'name': name, 'location': location}
                logging.info(f"添加站点成功: ID={station_id}, 名称={name}, 位置={location}")
            else:
                logging.debug(f"站点已存在: ID={station_id}, 名称={name}")
        except Exception as e:
            logging.error(f"添加站点失败: {str(e)}\n{traceback.format_exc()}")

    def add_connection(self, station1_id, station2_id, line_number):
        try:
            station1_id = str(station1_id)
            station2_id = str(station2_id)

            if station1_id not in self.stations:
                logging.error(f"起始站点不存在: {station1_id}")
                return
            if station2_id not in self.stations:
                logging.error(f"终点站点不存在: {station2_id}")
                return

            loc1 = self.stations[station1_id]['location']
            loc2 = self.stations[station2_id]['location']
            distance = self.calculate_distance(loc1, loc2)

            self.routes[station1_id].append((station2_id, line_number, distance))
            self.routes[station2_id].append((station1_id, line_number, distance))
            self.lines[line_number].add(station1_id)
            self.lines[line_number].add(station2_id)
            logging.info(
                f"添加连接成功: {station1_id}({self.stations[station1_id]['name']}) <-> {station2_id}({self.stations[station2_id]['name']}), 线路={line_number}, 距离={distance:.2f}米")
        except Exception as e:
            logging.error(f"添加连接失败: {str(e)}\n{traceback.format_exc()}")

    def calculate_distance(self, loc1, loc2):
        """计算两个坐标点之间的距离（米）"""
        try:
            lat1, lng1 = map(float, loc1)
            lat2, lng2 = map(float, loc2)

            R = 6371000  # 地球半径（米）
            lat1_rad = math.radians(lat1)
            lat2_rad = math.radians(lat2)
            delta_lat = math.radians(lat2 - lat1)
            delta_lng = math.radians(lng2 - lng1)

            a = math.sin(delta_lat / 2) ** 2 + math.cos(lat1_rad) * math.cos(lat2_rad) * math.sin(delta_lng / 2) ** 2
            c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))

            return R * c
        except Exception as e:
            logging.error(f"计算距离失败: {str(e)}\n{traceback.format_exc()}")
            return float('infinity')

    def save_stations_to_file(self, file_path):
        """将站点信息写入到txt文件中"""
        try:
            with open(file_path, 'w', encoding='utf-8') as file:
                for station_id, info in self.stations.items():
                    line = f"ID: {station_id}, Name: {info['name']}, Location: {info['location']}\n"
                    file.write(line)
            logging.info(f"站点信息已写入到文件: {file_path}")
        except Exception as e:
            logging.error(f"写入站点信息到文件失败: {str(e)}\n{traceback.format_exc()}")

    def find_shortest_path(self, start_id, end_id):
        """使用Dijkstra算法寻找最短路径"""
        try:
            logging.debug(f"开始寻找从 {start_id} 到 {end_id} 的最短路径")
            logging.debug(f"图中共有 {len(self.stations)} 个站点")

            if start_id not in self.stations:
                logging.error(f"起点站点ID {start_id} 不在图中")
                raise ValueError(f"起点站点ID {start_id} 不在图中")

            if end_id not in self.stations:
                logging.error(f"终点站点ID {end_id} 不在图中")
                raise ValueError(f"终点站点ID {end_id} 不在图中")

            distances = {station_id: float('infinity') for station_id in self.stations}
            distances[start_id] = 0
            previous = {station_id: None for station_id in self.stations}
            pq = [(0, start_id)]
            path_lines = {station_id: [] for station_id in self.stations}

            logging.debug("初始化完成，开始寻路")

            visited = set()
            while pq:
                current_distance, current_station = heapq.heappop(pq)

                if current_station in visited:
                    continue

                visited.add(current_station)
                logging.debug(f"访问站点: {current_station}, 当前距离: {current_distance}")

                if current_station == end_id:
                    logging.debug("到达终点站")
                    break

                if current_distance > distances[current_station]:
                    continue

                for next_station, line_number, distance in self.routes.get(current_station, []):
                    if next_station in visited:
                        continue

                    new_distance = distances[current_station] + distance
                    logging.debug(
                        f"检查相邻站点: {next_station}, 线路: {line_number}, 新距离: {new_distance}, 原距离: {distances[next_station]}")

                    if new_distance < distances[next_station]:
                        distances[next_station] = new_distance
                        previous[next_station] = current_station
                        path_lines[next_station] = path_lines[current_station] + [line_number]
                        heapq.heappush(pq, (new_distance, next_station))
                        logging.debug(f"更新站点 {next_station} 的最短距离为 {new_distance}")

            # 构建路径
            path = []
            current = end_id

            if distances[end_id] == float('infinity'):
                logging.error(f"未找到从 {start_id} 到 {end_id} 的路径")
                raise ValueError(f"未找到从 {start_id} 到 {end_id} 的路径")

            while current is not None:
                path.append(current)
                current = previous[current]
            path = path[::-1]

            logging.debug(f"找到路径: {path}")
            logging.debug(f"使用线路: {path_lines[end_id]}")
            logging.debug(f"总距离: {distances[end_id]}")

            return path, path_lines[end_id], distances[end_id]

        except Exception as e:
            logging.error(f"寻路算法失败: {str(e)}\n{traceback.format_exc()}")
            raise

    def get_debug_info(self):
        return {
            'stations_count': len(self.stations),
            'routes_count': sum(len(routes) for routes in self.routes.values()) // 2,  # 除以2因为是双向连接
            'lines_count': len(self.lines),
            'stations': {k: {'name': v['name'], 'location': v['location']} for k, v in self.stations.items()},
            'routes': {k: [(next_id, line, f"{dist:.2f}m") for next_id, line, dist in v] for k, v in
                       self.routes.items()}
        }


class AmapAPI:
    """处理与高德地图API交互的类"""

    def __init__(self, api_key):
        self.api_key = api_key

    def search_poi(self, keyword, city, offset=10, page=1, extensions='all'):
        """使用关键词搜索POI"""
        try:
            url = f'https://restapi.amap.com/v3/place/text'
            params = {
                'key': self.api_key,
                'keywords': keyword,
                'city': city,
                'offset': offset,
                'page': page,
                'extensions': extensions
            }
            response = requests.get(url, params=params)
            response.raise_for_status()
            data = response.json()
            if data.get('status') != '1':
                logging.error(f"POI搜索失败: {data.get('info')}")
                return None
            return data
        except Exception as e:
            logging.error(f"POI搜索异常: {str(e)}\n{traceback.format_exc()}")
            return None

    def search_around_poi(self, location, keywords, types, radius=1000, extensions='all'):
        """搜索周边POI"""
        try:
            url = f'https://restapi.amap.com/v3/place/around'
            params = {
                'key': self.api_key,
                'location': location,  # 格式: "lng,lat"
                'keywords': keywords,
                'types': types,
                'radius': radius,
                'extensions': extensions
            }
            response = requests.get(url, params=params)
            response.raise_for_status()
            data = response.json()
            if data.get('status') != '1':
                logging.error(f"周边POI搜索失败: {data.get('info')}")
                return None
            return data
        except Exception as e:
            logging.error(f"周边POI搜索异常: {str(e)}\n{traceback.format_exc()}")
            return None

    def get_transit_directions(self, origin, destination, city, strategy='0', extensions='all'):
        """获取公交换乘路线"""
        try:
            url = f'https://restapi.amap.com/v3/direction/transit/integrated'
            params = {
                'key': self.api_key,
                'origin': origin,
                'destination': destination,
                'city': city,
                'strategy': strategy,
                'extensions': extensions
            }
            response = requests.get(url, params=params)
            response.raise_for_status()
            data = response.json()
            if data.get('status') != '1':
                logging.error(f"公交换乘路线获取失败: {data.get('info')}")
                return None
            return data
        except Exception as e:
            logging.error(f"公交换乘路线获取异常: {str(e)}\n{traceback.format_exc()}")
            return None

class AMapApp:
    def __init__(self, amap_key):
        self.app = Flask(__name__)
        self.amap_key = amap_key
        self.setup_routes()

    def setup_routes(self):
        @self.app.route('/')
        def index():
            return render_template('index.html')

        @self.app.route('/search')
        def search():
            keyword = request.args.get('keyword')
            city = '重庆'
            url = f'https://restapi.amap.com/v3/place/text?key={self.amap_key}&keywords={keyword}&city={city}&offset=10&page=1&extensions=all'
            response = requests.get(url)
            return jsonify(response.json())

        @self.app.route('/route')
        def get_route():
            origin = request.args.get('origin')
            destination = request.args.get('destination')
            strategy = request.args.get('strategy', '0')
            transit_url = f'https://restapi.amap.com/v3/direction/transit/integrated?key={self.amap_key}&origin={origin}&destination={destination}&city=重庆&strategy={strategy}&extensions=all'
            transit_response = requests.get(transit_url)
            driving_url = f'https://restapi.amap.com/v3/direction/driving?key={self.amap_key}&origin={origin}&destination={destination}&extensions=all'
            driving_response = requests.get(driving_url)
            return jsonify({
                'transit': transit_response.json(),
                'driving': driving_response.json()
            })

    def run(self, debug=True):
        self.app.run(debug=debug)

class TransitApp:
    """封装Flask应用及其路由的类"""
    def __init__(self, amap_key, city='重庆'):
        self.app = Flask(__name__)
        self.amap_api = AmapAPI(amap_key)
        self.transit_graph = TransitGraph()
        self.city = city
        self.setup_routes()

    def setup_routes(self):
        """配置Flask路由"""

        @self.app.route('/')
        def index():
            """主页路由"""
            return render_template('index.html')

        @self.app.route('/search')
        def search():
            """POI搜索路由"""
            keyword = request.args.get('keyword')
            if not keyword:
                return jsonify({'status': '0', 'info': '缺少关键词参数'})

            logging.info(f"进行POI搜索: 关键词={keyword}, 城市={self.city}")
            poi_result = self.amap_api.search_poi(keyword, self.city)
            if poi_result:
                return jsonify(poi_result)
            else:
                return jsonify({'status': '0', 'info': 'POI搜索失败'})

        @self.app.route('/route')
        def get_route():
            """路线规划路由"""
            try:
                origin = request.args.get('origin')
                destination = request.args.get('destination')
                strategy = request.args.get('strategy', '0')

                logging.info(f"收到路线规划请求: 起点={origin}, 终点={destination}, 策略={strategy}")

                # 解析位置信息
                origin_loc = self.parse_location(origin)
                dest_loc = self.parse_location(destination)

                if not origin_loc or not dest_loc:
                    return jsonify({'status': '0', 'info': '位置信息格式错误'})

                logging.info(f"位置解析成功: 起点={origin_loc}, 终点={dest_loc}")

                # 获取附近站点
                origin_stations = self.get_nearby_stations(origin_loc, "起点")
                dest_stations = self.get_nearby_stations(dest_loc, "终点")

                if not origin_stations or not dest_stations:
                    return jsonify({'status': '0', 'info': '未找到附近站点'})

                # 清空图并添加起点和终点附近站点
                self.transit_graph.clear()
                self.add_stations_to_graph(origin_stations + dest_stations)

                # 获取公交线路信息
                transit_data = self.amap_api.get_transit_directions(
                    origin=origin,
                    destination=destination,
                    city=self.city,
                    strategy=strategy,
                    extensions='all'
                )

                if not transit_data:
                    return jsonify({
                        'status': '0',
                        'info': '获取公交线路失败',
                        'route': {
                            'origin': origin,
                            'destination': destination,
                            'transits': []
                        }
                    })

                logging.info(f"获取到公交线路信息: {json.dumps(transit_data, ensure_ascii=False, indent=2)}")

                # 处理公交线路数据
                if transit_data.get('status') == '1' and transit_data.get('route'):
                    transits = transit_data.get('route', {}).get('transits', [])
                    logging.info(f"找到 {len(transits)} 条公交线路方案")

                    # 连接起点和终点附近站点
                    self.connect_nearby_stations(origin_stations, 'nearby_connection')
                    self.connect_nearby_stations(dest_stations, 'nearby_connection')

                    for i, transit in enumerate(transits):
                        logging.info(f"处理第{i+1}条公交线路方案")
                        segments = transit.get('segments', [])
                        logging.info(f"该方案包含 {len(segments)} 个路段")
                        logging.debug(f"路段详细信息: {json.dumps(segments, ensure_ascii=False, indent=2)}")

                        last_station_id = None
                        metro_stations = {}

                        for segment in segments:
                            # 处理步行段
                            walking = segment.get('walking', {})
                            steps = walking.get('steps', []) if isinstance(walking, dict) else []

                            logging.info(f"处理步行段，包含 {len(steps)} 个步骤")

                            walk_origin = walking.get('origin') if isinstance(walking, dict) else None
                            walk_dest = walking.get('destination') if isinstance(walking, dict) else None

                            if walk_origin and walk_dest:
                                walk_origin_loc = self.parse_location(walk_origin)['location']
                                walk_dest_loc = self.parse_location(walk_dest)['location']

                                # 为步行段创建虚拟站点
                                walk_origin_id = f"walk_{walk_origin}"
                                walk_dest_id = f"walk_{walk_dest}"

                                self.transit_graph.add_station(walk_origin_id, "步行起点", walk_origin_loc)
                                self.transit_graph.add_station(walk_dest_id, "步行终点", walk_dest_loc)

                                # 连接步行段的起点和终点
                                distance = self.transit_graph.calculate_distance(walk_origin_loc, walk_dest_loc)
                                self.transit_graph.add_connection(walk_origin_id, walk_dest_id, 'walking')
                                logging.info(f"添加步行连接: {walk_origin_id} -> {walk_dest_id}, 距离={distance:.2f}米")

                                # 连接步行段与附近的公交站点
                                self.connect_walk_connections(walk_origin_id, walk_dest_id)

                                # 更新最后访问的站点
                                last_station_id = walk_dest_id

                            # 处理公交段
                            bus = segment.get('bus', {})
                            buslines = bus.get('buslines', []) if isinstance(bus, dict) else []

                            logging.info(f"处理公交段，包含 {len(buslines)} 条线路")

                            for busline in buslines:
                                try:
                                    # 获取该线路的所有站点
                                    via_stops = busline.get('via_stops', [])
                                    departure_stop = busline.get('departure_stop')
                                    arrival_stop = busline.get('arrival_stop')
                                    line_id = busline.get('id', 'unknown_line')
                                    line_name = busline.get('name', 'unknown_line')

                                    logging.info(f"处理公交线路: {line_name}")

                                    # 将所有站点按顺序加入列表
                                    all_stops = []
                                    if departure_stop:
                                        all_stops.append(departure_stop)
                                    all_stops.extend(via_stops)
                                    if arrival_stop:
                                        all_stops.append(arrival_stop)

                                    logging.info(f"处理公交线路 {line_name}, 包含 {len(all_stops)} 个站点")

                                    # 添加所有站点
                                    for stop in all_stops:
                                        if not stop or not stop.get('location'):
                                            logging.warning(f"站点数据不完整: {json.dumps(stop, ensure_ascii=False)}")
                                            continue

                                        # 使用完整的站点ID
                                        stop_id = stop.get('id') or f"stop_{stop.get('name')}_{stop.get('location')}"
                                        stop_name = stop.get('name', '未知站点')
                                        stop_location = self.parse_location(stop['location'])['location']

                                        # 添加站点
                                        self.transit_graph.add_station(stop_id, stop_name, stop_location)
                                        logging.info(f"添加站点: ID={stop_id}, 名称={stop_name}, 位置={stop_location}")

                                        # 记录地铁站点信息
                                        if busline.get('type') == '地铁线路':
                                            if stop_name not in metro_stations:
                                                metro_stations[stop_name] = {}
                                            metro_stations[stop_name][line_id] = stop_id

                                        # 检查是否是换乘站点（通过名称和位置判断）
                                        self.connect_transfer_stations(stop_id, stop_name)

                                        # 如果有上一个步行终点，检查是否需要连接
                                        if last_station_id and last_station_id.startswith('walk_'):
                                            last_location = self.transit_graph.stations[last_station_id]['location']
                                            distance = self.transit_graph.calculate_distance(stop_location, last_location)
                                            if distance <= 100:
                                                self.transit_graph.add_connection(last_station_id, stop_id, 'walking_connection')
                                                logging.info(f"添加步行-公交连接: {last_station_id} -> {stop_id}, 距离={distance:.2f}米")

                                    # 连接相邻站点
                                    for i in range(len(all_stops) - 1):
                                        current_stop = all_stops[i]
                                        next_stop = all_stops[i + 1]

                                        if not current_stop or not next_stop:
                                            continue

                                        # 使用完整的站点ID
                                        current_id = current_stop.get('id') or f"stop_{current_stop.get('name')}_{current_stop.get('location')}"
                                        next_id = next_stop.get('id') or f"stop_{next_stop.get('name')}_{next_stop.get('location')}"

                                        if current_id in self.transit_graph.stations and next_id in self.transit_graph.stations:
                                            current_loc = self.transit_graph.stations[current_id]['location']
                                            next_loc = self.transit_graph.stations[next_id]['location']
                                            distance = self.transit_graph.calculate_distance(current_loc, next_loc)

                                            self.transit_graph.add_connection(
                                                current_id,
                                                next_id,
                                                line_name
                                            )
                                            logging.info(f"添加连接: {current_id} -> {next_id} via {line_name}, 距离={distance:.2f}米")

                                    # 更新最后访问的站点为当前线路的终点站
                                    if arrival_stop:
                                        last_station_id = arrival_stop.get('id') or f"stop_{arrival_stop.get('name')}_{arrival_stop.get('location')}"
                                except Exception as e:
                                    logging.error(f"处理公交线路失败: {str(e)}")
                                    logging.error(f"公交线路数据: {json.dumps(busline, ensure_ascii=False, indent=2)}")

                            # 处理地铁换乘站点
                            for station_name, line_stations in metro_stations.items():
                                if len(line_stations) > 1:  # 如果一个站点出现在多条线路上
                                    logging.info(f"处理地铁换乘站点: {station_name}, 涉及 {len(line_stations)} 条线路")
                                    # 将同一站点在不同线路上的站点ID相互连接
                                    station_ids = list(line_stations.values())
                                    for i in range(len(station_ids)):
                                        for j in range(i + 1, len(station_ids)):
                                            self.transit_graph.add_connection(station_ids[i], station_ids[j], 'metro_transfer')
                                            logging.info(f"添加地铁换乘连接: {station_ids[i]} <-> {station_ids[j]}")

                    # 输出连接信息
                    self.log_connections()

                    # 输出图的调试信息
                    debug_info = self.transit_graph.get_debug_info()
                    logging.info(f"图构建完成: {json.dumps(debug_info, ensure_ascii=False, indent=2)}")

                    # 寻找最佳路线
                    best_path = self.find_best_route(origin_stations, dest_stations)

                    if best_path:
                        result = {
                            'status': '1',
                            'info': 'OK',
                            'route': {
                                'origin': origin,
                                'destination': destination,
                                'transits': [{
                                    'cost': best_path['distance'],
                                    'duration': int(best_path['distance'] / 1.2),  # 估算时间，假设平均速度1.2m/s
                                    'walking_distance': sum(1 for line in best_path['lines'] if line in ['walking', 'walking_connection']) * 500,  # 估算步行距离
                                    'path': {
                                        'path': best_path['path'],
                                        'lines': best_path['lines'],
                                        'distance': best_path['distance'],
                                        'stations': [self.transit_graph.stations[station_id] for station_id in best_path['path']]
                                    }
                                }]
                            }
                        }
                        logging.info(f"返回成功结果: {json.dumps(result, ensure_ascii=False)}")
                    else:
                        result = {
                            'status': '0',
                            'info': '未找到合适的路线',
                            'route': {
                                'origin': origin,
                                'destination': destination,
                                'transits': []
                            }
                        }
                        logging.warning("未找到合适的路线")

                    return jsonify(result)

                else:
                    logging.error(f"获取公交线路失败: {transit_data.get('info')}")
                    return jsonify({
                        'status': '0',
                        'info': '获取公交线路失败',
                        'route': {
                            'origin': origin,
                            'destination': destination,
                            'transits': []
                        }
                    })

            except Exception as e:
                error_msg = f"路线规划失败: {str(e)}"
                logging.error(f"{error_msg}\n{traceback.format_exc()}")
                return jsonify({'status': '0', 'info': error_msg})

    def parse_location(self, location_str):
        """解析位置信息字符串为坐标元组"""
        try:
            lng, lat = map(float, location_str.split(','))
            return {'location': (lat, lng)}
        except Exception as e:
            logging.error(f"解析位置信息失败: {str(e)}")
            return None

    def get_nearby_stations(self, location, location_type=""):
        """获取附近的公交站点"""
        try:
            loc_str = f"{location['location'][1]},{location['location'][0]}"
            data = self.amap_api.search_around_poi(
                location=loc_str,
                keywords='公交站',
                types='150700',
                radius=1000,
                extensions='all'
            )
            if not data:
                return []
            stations = data.get('pois', [])
            logging.info(f"获取{location_type}附近站点成功: 找到{len(stations)}个站点")
            for station in stations:
                logging.debug(f"{location_type}附近站点: ID={station['id']}, 名称={station['name']}, 位置={station['location']}")
            return stations
        except Exception as e:
            logging.error(f"获取{location_type}附近站点异常: {str(e)}")
            return []

    def add_stations_to_graph(self, stations):
        """将站点添加到TransitGraph中"""
        for station in stations:
            station_id = station['id']
            station_name = station['name']
            station_location = tuple(map(float, station['location'].split(',')))[::-1]  # (lat, lng)
            self.transit_graph.add_station(station_id, station_name, station_location)

    def connect_nearby_stations(self, stations, connection_type):
        """连接附近站点"""
        try:
            for i in range(len(stations)):
                for j in range(i + 1, len(stations)):
                    station1 = stations[i]
                    station2 = stations[j]
                    self.transit_graph.add_connection(station1['id'], station2['id'], connection_type)
        except Exception as e:
            logging.error(f"连接附近站点失败: {str(e)}\n{traceback.format_exc()}")

    def connect_walk_connections(self, walk_origin_id, walk_dest_id):
        """连接步行段与附近的公交站点"""
        try:
            for station_id, station_info in self.transit_graph.stations.items():
                if 'walk_' not in station_id:  # 只考虑实际的公交站点
                    station_loc = station_info['location']

                    # 检查与步行起点的距离
                    origin_distance = self.transit_graph.calculate_distance(
                        self.transit_graph.stations[walk_origin_id]['location'],
                        station_loc
                    )
                    if origin_distance <= 100:  # 100米以内的站点
                        self.transit_graph.add_connection(station_id, walk_origin_id, 'walking_connection')
                        logging.info(f"添加步行起点连接: {station_id} -> {walk_origin_id}, 距离={origin_distance:.2f}米")

                    # 检查与步行终点的距离
                    dest_distance = self.transit_graph.calculate_distance(
                        self.transit_graph.stations[walk_dest_id]['location'],
                        station_loc
                    )
                    if dest_distance <= 100:  # 100米以内的站点
                        self.transit_graph.add_connection(walk_dest_id, station_id, 'walking_connection')
                        logging.info(f"添加步行终点连接: {walk_dest_id} -> {station_id}, 距离={dest_distance:.2f}米")
        except Exception as e:
            logging.error(f"连接步行段失败: {str(e)}\n{traceback.format_exc()}")

    def connect_transfer_stations(self, stop_id, stop_name):
        """连接换乘站点"""
        try:
            for existing_id, existing_info in self.transit_graph.stations.items():
                if existing_id == stop_id:
                    continue
                distance = self.transit_graph.calculate_distance(
                    self.transit_graph.stations[stop_id]['location'],
                    existing_info['location']
                )
                if existing_info['name'] == stop_name or distance <= 100:
                    self.transit_graph.add_connection(stop_id, existing_id, 'transfer')
                    logging.info(f"添加换乘连接: {stop_id}({stop_name}) <-> {existing_id}({existing_info['name']})")
        except Exception as e:
            logging.error(f"连接换乘站点失败: {str(e)}\n{traceback.format_exc()}")

    def log_connections(self):
        """记录所有站点的连接信息"""
        try:
            logging.info("站点连接情况:")
            for station_id, routes in self.transit_graph.routes.items():
                station_name = self.transit_graph.stations[station_id]['name']
                connections = [f"{self.transit_graph.stations[next_id]['name']}(via {line})" for next_id, line, _ in routes]
                logging.info(f"{station_name} 连接到: {', '.join(connections)}")
        except Exception as e:
            logging.error(f"记录连接信息失败: {str(e)}\n{traceback.format_exc()}")

    def find_best_route(self, origin_stations, dest_stations):
        """寻找最佳路线"""
        try:
            best_path = None
            min_distance = float('infinity')

            for start_station in origin_stations:
                for end_station in dest_stations:
                    try:
                        path, lines, distance = self.transit_graph.find_shortest_path(start_station['id'], end_station['id'])
                        if distance < min_distance:
                            min_distance = distance
                            best_path = {
                                'path': path,
                                'lines': lines,
                                'distance': distance,
                                'stations': [self.transit_graph.stations[station_id] for station_id in path]
                            }
                            logging.info(f"找到更好的路径: 从 {start_station['name']} 到 {end_station['name']}, 距离: {distance}米")
                    except Exception as e:
                        logging.error(f"路径规划失败: {str(e)}")

            return best_path
        except Exception as e:
            logging.error(f"寻找最佳路线失败: {str(e)}\n{traceback.format_exc()}")
            return None

    def run(self, debug=True):
        """运行Flask应用"""
        self.app.run(debug=debug)


if __name__ == '__main__':
    # 初始化日志
    Logger()

    # 替换为你的高德地图API密钥
    AMAP_KEY = "c882add126d5a692e9898b425e8d41b3"

    # 创建并运行应用
    transit_app = TransitApp(amap_key=AMAP_KEY)
    transit_app.run(debug=True)
