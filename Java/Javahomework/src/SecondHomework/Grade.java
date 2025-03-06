//在JavaHomework项目中定义一个学生成绩类Grade
//1、Grade中包括学生姓名，java，html，sql三个门课的成绩属性、总分、平均分的属性
//2、Grade定义一个无参的构造法，在构造法中通过Scanner录入信息属性构造成绩对象。
//3、成绩管理类GradeAdmin来实现，以下功能：
//  1）GradeAdmin类中定一个Grade[] grades数组来报错成绩对象。
//  2）能通过输入关键字实现对学生姓名的模糊查询，可以返回多个学生成绩信息，并打印输出。如输入李，能显示所有学生姓名包含“李”的学生成绩信息。
//  3）能通过表格形式显示输出全部学生成绩，并统计出平均分，总分，排名。并能按排名顺序（升序或降序）打印显示
// 4）定义一个方法如下图所示，组合功能
//-------学生成绩系统-------
//1---学生成绩录入
//2---学生成绩查询打印
//3---学生成绩排序
//0---退出

package SecondHomework;

import java.util.Scanner;

 public class Grade {
    private String studentName;

     public String getStudentName() {
         return studentName;
     }

     public void setStudentName(String studentName) {
         this.studentName = studentName;
     }

     public int getJavaScore() {
         return javaScore;
     }

     public void setJavaScore(int javaScore) {
         this.javaScore = javaScore;
     }

     public int getHtmlScore() {
         return htmlScore;
     }

     public void setHtmlScore(int htmlScore) {
         this.htmlScore = htmlScore;
     }

     public int getSqlScore() {
         return sqlScore;
     }

     public void setSqlScore(int sqlScore) {
         this.sqlScore = sqlScore;
     }

     public int getTotalScore() {
         return totalScore;
     }

     public void setTotalScore(int totalScore) {
         this.totalScore = totalScore;
     }

     public double getAverageScore() {
         return averageScore;
     }

     public void setAverageScore(double averageScore) {
         this.averageScore = averageScore;
     }

     private int javaScore;
    private int htmlScore;
    private int sqlScore;
    private int totalScore;
    private double averageScore;

    // 无参构造方法，通过Scanner录入信息
    public Grade() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入学生姓名: ");
        this.studentName = scanner.nextLine();
        System.out.print("请输入Java成绩: ");
        this.javaScore = scanner.nextInt();
        System.out.print("请输入HTML成绩: ");
        this.htmlScore = scanner.nextInt();
        System.out.print("请输入SQL成绩: ");
        this.sqlScore = scanner.nextInt();
        this.totalScore = javaScore + htmlScore + sqlScore;
        this.averageScore = totalScore / 3.0;
    }

    @Override
    public String toString() {
        return "姓名: " + studentName + ", Java: " + javaScore + ", HTML: " + htmlScore + ", SQL: " + sqlScore
                + ", 总分: " + totalScore + ", 平均分: " + averageScore;
    }
}