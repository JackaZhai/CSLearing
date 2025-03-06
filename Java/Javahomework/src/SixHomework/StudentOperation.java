package SixHomework;

import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class StudentOperation {
    static Scanner reader = new Scanner(System.in);
    //学生信息操作的交互方法
    public static void main(String[] args) throws Exception {
        while (true) {
            System.out.println("学生信息管理");
            System.out.println("--------------------------------");
            System.out.println("学生信息添加————1");
            System.out.println("学生信息修改————2");
            System.out.println("学生信息删除————3");
            System.out.println("学生信息查询————4");
            System.out.println("退出————0");
            int s = reader.nextInt();
            if (s == 1) {
                addStudent();
            } else if (s == 3) {
                delete();
            } else if (s == 2) {
                edit();
            } else if (s == 4) {
                search();
            }else if(s==0) {
                break;
            }
        }
    }

//学生信息的新增

    public static void addStudent() throws Exception {
        System.out.println("请输入学生姓名, 专业（,号隔开）");
        String input = reader.next();  // 获取输入
        String[] s = input.split(",");

        // 检查输入格式是否正确，确保分割后至少有两个元素
        if (s.length < 2) {
            System.out.println("输入格式不正确，请输入姓名和专业，中间用逗号隔开。");
            return;  // 结束方法执行
        }
        String name = s[0];
        String major = s[1];
        Student student = new Student(0, name, major);
        StudentDao.insert(student);
        printStudents(StudentDao.findStudent(""));
    }

//学生信息的删除

    public static void delete() {
        System.out.println("请输入学生编号：");
        int no = reader.nextInt();
        Student s=StudentDao.getOneByNo(no);
        if (s == null) {
            System.out.println("没有这个学生！");
        } else {
            StudentDao.delete(no);
        }
        printStudents(StudentDao.findStudent(""));
    }

//一个学生信息的编辑

    public static void edit() {
        System.out.println("请输入学生编号：");
        int no = reader.nextInt();
        Student s=StudentDao.getOneByNo(no);

        if (s == null) {
            System.out.println("没有这个学生！");
        } else {
            System.out.println("请输入学生姓名，专业（，号隔开）");
            String[] s1 = (reader.next()).split(",");
            s.setName(s1[0]);
            s.setMajor(s1[1]);
            StudentDao.update(s);
            printStudents(StudentDao.findStudent(""));
        }
    }

//学生信息的查询显示

    public static void search() {
        System.out.println("请输入查询条件:（编号/姓名/专业）");
        //输入空格查询所有
        reader.nextLine(); //用一个nextLine消除前一个输入后面的回车
        String key = reader.nextLine();
        printStudents(StudentDao.findStudent(key));
    }
//学生信息的打印显示

    public static void printStudents(List<Student> results) {
        System.out.println("编号\t\t姓名\t\t专业");
        System.out.println("--------------------------------");
        if (results.size() > 0) {

            Iterator<Student> iterator=results.iterator();

            while(iterator.hasNext()) {
                Student s=iterator.next();
                System.out.println(s);
            }
        } else {
            System.out.println("没有学生信息！！");
        }
        System.out.println("--------------------------------");

    }
    public static void show() {
        try {
            main(new String[]{});
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

}
