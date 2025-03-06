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

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class GradeAdmin {
    Grade[] grades;
    Scanner scanner = new Scanner(System.in);

    public GradeAdmin() {
        // 初始设置为0，使用菜单选择进入录入流程
        this.grades = new Grade[0];
    }

    // 添加功能入口
    public void run() {
        while (true) {
            System.out.println("学生成绩系统选项:");
            System.out.println("1---学生成绩录入");
            System.out.println("2---学生成绩查询打印");
            System.out.println("3---学生成绩排序");
            System.out.println("0---退出");
            System.out.print("请选择操作: ");
            int choice = scanner.nextInt();
            scanner.nextLine();  // 吞掉换行符

            switch (choice) {
                case 1:
                    inputGrades();
                    break;
                case 2:
                    printAllGrades();
                    break;
                case 3:
                    sortAndPrintGrades();
                    break;
                case 0:
                    System.out.println("退出系统");
                    return;
                default:
                    System.out.println("无效选择，请重新输入");
            }
        }
    }

    // 成绩录入
    public void inputGrades() {
        System.out.print("请输入学生人数: ");
        int num = scanner.nextInt();
        this.grades = new Grade[num];
        scanner.nextLine();  // 吞掉换行符
        for (int i = 0; i < num; i++) {
            grades[i] = new Grade();
        }
    }

    // 成绩查询和打印
    public void printAllGrades() {
        if (grades.length == 0) {
            System.out.println("无任何学生成绩记录，请先进行成绩录入。");
            return;
        }
        System.out.print("输入要查询的学生姓名关键词: ");
        String keyword = scanner.nextLine();
        boolean found = false;
        for (Grade grade : grades) {
            if (grade.getStudentName().contains(keyword)) {
                System.out.println(grade);
                found = true;
            }
        }
        if (!found) {
            System.out.println("未找到匹配的学生记录。");
        }
    }

    // 输出所有学生成绩和排序
    public void sortAndPrintGrades() {
        if (grades.length == 0) {
            System.out.println("无任何学生成绩记录，请先进行成绩录入。");
            return;
        }
        Arrays.sort(grades, Comparator.comparingInt(grade -> grade.getTotalScore()));
        System.out.printf("%-10s %-10s %-10s %-10s %-10s %-10s%n", "姓名", "Java", "HTML", "SQL", "总分", "平均分");
        for (Grade grade : grades) {
            System.out.printf("%-10s %-10d %-10d %-10d %-10d %-10.2f%n", grade.getStudentName(), grade.getJavaScore(),
                    grade.getHtmlScore(), grade.getSqlScore(), grade.getTotalScore(), grade.getAverageScore());
        }
    }

}