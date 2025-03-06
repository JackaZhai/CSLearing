package FirstHomework;
//在Javahomework项目中完成以下类
//1、定义一个手机类（FirstHomework.Phone），包括品牌、型号、CPU个数、内存、操作系统、价格、编号七个属性。
//2、定义一个构造法，在构造法中，使用Scanner类的对象实现键盘输入，对（品牌、型号、CPU个数、内存、价格）五个属性赋值。
//3、定义一个方法，方法中有一个操作系统名称的数组，String[] osNames={"Android","IOS","Harmary（HarmonyOS）"}，能随机返回一个操作系统名称。并在构造法中调用这个方法实现对操作系统属性赋值。
//4、定义一个方法，方法中通过Calendar类获得创建手机对象的当前时间，并按时间生成一个编号，编号格式如yyyy-MM-dd-hh-mm-ss，方法返回这个编号。并在构造法中调用这个方法实现对编号属性赋值。
//5、重写toString（）方法，能按以下格式输出手机对象。

//---编号为2024-05-07-19-55-36的手机参数--
//品牌：华为
//型号：mate60
//cpu个数：2
//内存：16.0
//操作系统：Harmary
//价格：6999.0
//-------------------------------------

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.InputMismatchException;
import java.util.Scanner;


public class Phone {
    private String brand;    // 品牌
    private String type;     // 型号
    private int cpuNum;      // CPU个数
    private double memory;   // 内存
    private String OS;       // 操作系统
    private double price;    // 价格
    private String serialNumber; // 编号

    // getter和setter方法
    public String getBrand() {
        return brand;
    }

    public String getType() {
        return type;
    }

    public int getCpuNum() {
        return cpuNum;
    }

    public double getMemory() {
        return memory;
    }

    public double getPrice() {
        return price;
    }

    public String getSerialNumber() {
        return serialNumber;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setCpuNum(int cpuNum) {
        this.cpuNum = cpuNum;
    }

    public void setMemory(double memory) {
        this.memory = memory;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setSerialNumber(String serialNumber) {
        this.serialNumber = serialNumber;
    }


    // 构造方法
public Phone() {
    Scanner reader = new Scanner(System.in);
    try {
        System.out.print("输入品牌：");
        this.brand = reader.nextLine();
        System.out.print("输入型号：");
        this.type = reader.nextLine();
        System.out.print("输入CPU个数：");
        this.cpuNum = reader.nextInt();
        System.out.print("输入内存大小：");
        this.memory = reader.nextDouble();
        System.out.print("输入价格：");
        this.price = reader.nextDouble();
        this.OS = getOS();
        this.serialNumber = getDateTime();
    } catch (InputMismatchException e) {
        throw new IllegalArgumentException("输入无效，请输入正确的值。", e);
    }
}

    // 返回随机操作系统名称的方法
    private String getOS() {
        String[] osNames = {"Android", "IOS", "HarmonyOS"};
        int index = (int) (Math.random() * 3);
        return osNames[index];
    }

    // 生成编号的方法
    private String getDateTime() {
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss");
        return df.format(calendar.getTime());
    }

    // 重写toString方法
    @Override
    public String toString() {
        return "---编号为" + serialNumber + "的手机参数--\n" +
               "品牌：" + brand + "\n" +
               "型号：" + type + "\n" +
               "cpu个数：" + cpuNum + "\n" +
               "内存：" + memory + "\n" +
               "操作系统：" + OS + "\n" +
               "价格：" + price + "\n" +
               "--------------------------------------";
    }

//    public static void main(String[] args) {
//        FirstHomework.Phone phone = new FirstHomework.Phone();
//        System.out.println(phone);
//    }
}