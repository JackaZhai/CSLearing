package SixHomework;
import java.util.Scanner;
public class Course {

    static int count=0;
    private int no;
    private String name;
    Scanner reader=new Scanner(System.in);
    // 课程学分
    private double score;

    public Course() throws Exception{

        System.out.println("输入课程名称：");
        String name=reader.next();
        System.out.println("输入课程学分：");
        double score=reader.nextDouble();
        count=count+1;
        this.name = name;
        this.no = count;
        this.score = score;

    }

    public Course(int no,String name,double score) {
        this.no=no;
        this.name=name;
        this.score=score;

    }

    public int getNo() {
        return no;
    }

    public void setNo(int no) {
        this.no = no;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getScore() {
        return score;
    }

    public void setScore(double score) {
        this.score = score;
    }
    public String toString() {
        return this.no + "\t\t" + this.name + "\t\t" +this.score;
    }

}
