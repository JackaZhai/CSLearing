package FifthHomework;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;

public class weather {
    private static final String API_KEY = "YOUR_API_KEY"; // 替换为你的API密钥
    private static final String GEO_API_URL = "https://geoapi.qweather.com/v2/city/lookup?location=%s&key=%s";
    private static final String WEATHER_API_URL = "https://devapi.qweather.com/v7/weather/now?location=%s&key=%s";

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入城市名称：");
        String cityName = scanner.nextLine();
        scanner.close();

        try {
            // 对城市名称进行URL编码
            String encodedCityName = URLEncoder.encode(cityName, StandardCharsets.UTF_8.toString());

            // 获取城市的Location ID
            String geoUrlString = String.format(GEO_API_URL, encodedCityName, API_KEY);
            URL geoUrl = new URL(geoUrlString);
            HttpURLConnection geoConnection = (HttpURLConnection) geoUrl.openConnection();
            geoConnection.setRequestMethod("GET");

            BufferedReader geoIn = new BufferedReader(new InputStreamReader(geoConnection.getInputStream()));
            String geoInputLine;
            StringBuilder geoContent = new StringBuilder();
            while ((geoInputLine = geoIn.readLine()) != null) {
                geoContent.append(geoInputLine);
            }
            geoIn.close();
            geoConnection.disconnect();

            JSONObject geoJson = JSON.parseObject(geoContent.toString());
            if (!geoJson.getString("code").equals("200")) {
                System.out.println("获取城市数据失败，错误代码：" + geoJson.getString("code"));
                return;
            }

            JSONArray locationArray = geoJson.getJSONArray("location");
            if (locationArray.size() == 0) {
                System.out.println("未找到相关城市");
                return;
            }

            String locationId = locationArray.getJSONObject(0).getString("id");

            // 获取天气信息
            String weatherUrlString = String.format(WEATHER_API_URL, locationId, API_KEY);
            URL weatherUrl = new URL(weatherUrlString);
            HttpURLConnection weatherConnection = (HttpURLConnection) weatherUrl.openConnection();
            weatherConnection.setRequestMethod("GET");

            BufferedReader weatherIn = new BufferedReader(new InputStreamReader(weatherConnection.getInputStream()));
            String weatherInputLine;
            StringBuilder weatherContent = new StringBuilder();
            while ((weatherInputLine = weatherIn.readLine()) != null) {
                weatherContent.append(weatherInputLine);
            }
            weatherIn.close();
            weatherConnection.disconnect();

            JSONObject weatherJson = JSON.parseObject(weatherContent.toString());
            if (!weatherJson.getString("code").equals("200")) {
                System.out.println("获取天气数据失败，错误代码：" + weatherJson.getString("code"));
                return;
            }

            JSONObject now = weatherJson.getJSONObject("now");
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
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}