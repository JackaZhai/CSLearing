package FifthHomework.chapter5_2;

import java.awt.*;
import java.io.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class FileLoadDown {
    public void openNetFile(String url, String fileName, String savePath) {
        try {
            URL fileUrl = new URL(url);
            HttpURLConnection connection = (HttpURLConnection) fileUrl.openConnection();//打开连接
            connection.setConnectTimeout(3 * 1000);
            try (InputStream is = connection.getInputStream();
                 OutputStream os = new FileOutputStream(new File(savePath, fileName))) {//下载文件
                byte[] buffer = new byte[10 * 1024];
                int len;
                while ((len = is.read(buffer)) != -1) {
                    os.write(buffer, 0, len);
                }
                System.out.println("下载成功！");
                Desktop.getDesktop().open(new File(savePath, fileName));//打开文件
            }
        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}