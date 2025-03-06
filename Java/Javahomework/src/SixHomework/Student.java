package SixHomework;
import java.util.Scanner;

public class Student {

    static int count=0;
    private String name;
    private int no;
    private String major;

    Scanner reader=new Scanner(System.in);

    public Student(int no,String name,String major) {
        this.no=no;
        this.name=name;
        this.major=major;
    }

    public Student() throws Exception{
        // TODO Auto-generated constructor stub
        System.out.println("输入学生姓名：");
        String name=reader.next();
        System.out.println("输入学生专业：");
        String major=reader.next();
        count=count+1;
        this.no=count;
        this.major=major;
        this.name=name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNo() {
        return no;
    }

    public void setNo(int no) {
        this.no = no;

    }

    public String getMajor() {
        return major;

    }

    public void setMajor(String major) {
        this.major = major;

    }
    public String toString() {
        return this.no+"\t\t"+this.name+"\t\t"+this.major;
    }

}
