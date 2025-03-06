package FifthHomework.chapter5_1;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.zip.GZIPInputStream;

public class NetDataAccess {

    public static void getHttpResult(String uri, BackForResult back) {
        new Thread() {
            public void run() {
                try {
                    URL url = new URL(uri);
                    HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                    InputStream is = new GZIPInputStream(connection.getInputStream());
                    StringBuilder result = new StringBuilder();
                    byte[] buffer = new byte[10 * 1024];
                    int len;
                    while ((len = is.read(buffer)) != -1) {
                        result.append(new String(buffer, 0, len, "utf-8"));
                    }
                    is.close();
                    back.backResult(result.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
}

interface BackForResult {
    void backResult(String result);
}