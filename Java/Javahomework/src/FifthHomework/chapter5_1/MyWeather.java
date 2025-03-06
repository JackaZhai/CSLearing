package FifthHomework.chapter5_1;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.Scanner;

public class MyWeather {
    private final static String KEY = "5c2a96263aea4b2a9af0e47d48e2d154";
    Scanner reader = new Scanner(System.in);

    public void showWeather() {
        System.out.println("-----城市天气查询-----");
        System.out.println("请输入城市名称（中文） 0——退出");
        while (true) {

            String city = reader.next();
            if (city.equals("0")) {
                break;
            }
            try {
                city = URLEncoder.encode(city, "utf-8");
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
            }
            String uri = "https://geoapi.qweather.com/v2/city/lookup?location=" + city + "&key=" + KEY;//获取城市代码
            NetDataAccess.getHttpResult(uri, new BackForResult() {
                @Override
                public void backResult(String result) {
                    String cityCode = getCityCode(result);
                    String uril = "https://devapi.qweather.com/v7/weather/now?location=" + cityCode + "&key=" + KEY;
                    NetDataAccess.getHttpResult(uril, new BackForResult() {
                        @Override
                        public void backResult(String result) {
                            printWeather(result);
                            System.out.println();
                            System.out.println("-----城市天气查询-----");
                            System.out.println("请输入入城市名称（中文）：0——退出");
                        }
                    });
                }
            });
        }
    }

    private String getCityCode(String result) {
        JSONObject json = JSON.parseObject(result);
        JSONArray locations = (JSONArray) json.get("location");
        JSONObject location = locations.getJSONObject(0);
        return location.getString("id");
    }

    private void printWeather(String result) {
        JSONObject json = JSON.parseObject(result);
        JSONObject now = (JSONObject) json.get("now");
//        String temp = (String) now.get("temp");
//        System.out.println("当前温度 ：" + temp + "°C");
//        String text = now.getString("text");
//        System.out.println("当前天气:" + text);
        System.out.println("观测时间：" + now.getString("obsTime"));
        System.out.println("温度：" + now.getString("temp") + "°C");
        System.out.println("体感温度：" + now.getString("feelsLike") + "°C");
        System.out.println("天气状况：" + now.getString("text"));
        System.out.println("风向：" + now.getString("windDir"));
        System.out.println("风力等级：" + now.getString("windScale"));
        System.out.println("风速：" + now.getString("windSpeed") + "公里/小时");
        System.out.println("相对湿度：" + now.getString("humidity") + "%");
        System.out.println("降水量：" + now.getString("precip") + "毫米");
        System.out.println("大气压强：" + now.getString("pressure") + "百帕");
        System.out.println("能见度：" + now.getString("vis") + "公里");
        System.out.println("露点温度：" + now.getString("dew") + "°C");
        System.out.println("云量：" + now.getString("cloud") + "%");
    }
}