package ThirdHomework.io;
import jdk.dynalink.beans.StaticClass;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class FileReadWrite {
    public static String readerFile(String filePath) throws IOException {
        File file=new File(filePath);
        StringBuffer stringBuffer=new StringBuffer();
        try {
            FileInputStream fis = new FileInputStream(file);
            byte[] buffer=new byte[1024];
            int len;
            while ((len=fis.read(buffer))!=-1){
                stringBuffer.append(new String(buffer,0,len));
            }
            return stringBuffer.toString();
        }catch (FileNotFoundException e){
            e.printStackTrace();
        }
        return null;
    }
}
