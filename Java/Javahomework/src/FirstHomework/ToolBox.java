package FirstHomework;//没有用
import java.util.Scanner;

public class ToolBox {
    //println
    public static void println(Object obj) {    //Object: 任意类型
        System.out.println(obj);
    }

    //reader
    public static Scanner reader() {
        return new Scanner(System.in);
    }
}
