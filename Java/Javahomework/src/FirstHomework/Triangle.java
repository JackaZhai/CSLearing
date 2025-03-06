package FirstHomework;//在Javahomework项目中完成以下类
//
//三角形类的设计
//
//1、定义一个三角形的类，并定义三条边长属性，注意属性的封装。
//
//2、定义一个无参的构造法，利用键盘输入三个边长属性，构造三角形对象。如果输入不能构造三角形则抛异常。
//
//3、重写toString的方法，实现打印三角形对象，能显示三角形类型（等边、等腰、直角等等）和三角形的面积（保留两位小数））


import java.util.InputMismatchException;
import java.util.Scanner;

public class Triangle {
    private double A;
    private double B;
    private double C;

    // getter和setter方法
    public double getC() {
        return C;
    }

    public void setC(double c) {
        C = c;
    }

    public double getA() {
        return A;
    }

    public void setA(double a) {
        A = a;
    }

    public double getB() {
        return B;
    }

    public void setB(double b) {
        B = b;
    }

    public Triangle() {
        Scanner scanner = new Scanner(System.in);
        this.A = getInput("输入边长A：", scanner);
        this.B = getInput("输入边长B：", scanner);
        this.C = getInput("输入边长C：", scanner);

        if (!goodTriangle()) {
            throw new IllegalArgumentException("输入的边长不能构成三角形");
        }
    }

    private double getInput(String prompt, Scanner scanner) {
        double value;
        while (true) {
            System.out.print(prompt);
            try {
                value = scanner.nextDouble();
                break;
            } catch (InputMismatchException e) {
                System.out.println("输入无效，请输入一个数字。");
                scanner.next(); // 清除无效输入
            }
        }
        return value;
    }

    //判断是不是正常的三角形
    private boolean goodTriangle() {
        return (A + B > C) && (A + C > B) && (B + C > A);
    }

    //计算面积，使用海伦公式
    private double calculateMianji() {
        double s = (A + B + C) / 2;
        return Math.sqrt(s * (s - A) * (s - B) * (s - C));
    }

    private String getTriangleType() {
        if (A == B && B == C) {
            return "等边三角形";
        } else if (A == B || A == C || B == C) {
            return "等腰三角形";
        } else if (isRightTriangle()) {
            return "直角三角形";
        } else {
            return "普通三角形";
        }
    }

    //判断是不是直角三角形
    private boolean isRightTriangle() {
        double a2 = A * A;
        double b2 = B * B;
        double c2 = C * C;
        return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
    }

    @Override//重写toString方法
    public String toString() {
        return "三角形类型：" + getTriangleType() + "\n" +
               "面积：" + String.format("%.2f", calculateMianji());
    }
}