package SixHomework;
import java.util.List;
import java.util.Scanner;

public class GradeOperation {
    static Scanner reader = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        gradeMenu();
    }
    /**
     * 学生选课方法
     */
    public static void studentSelectCourse() throws Exception{
        System.out.println("输入学号：");
        int stuNo = reader.nextInt();
        Student s = StudentDao.getOneByNo(stuNo);
        if (s != null) {
            while (true) {
                System.out.println(s);
                System.out.println("--------已选课程------------");
                List<Course> selectCourses = GradeDAO.findCoursesSelectBystudent(s, true);
                CourseOperation.printCourses(selectCourses);
                System.out.println("-----------------------------");
                System.out.println("--------未选课程------------");
                List<Course> noSelectCourses = GradeDAO.findCoursesSelectBystudent(s, false);
                CourseOperation.printCourses(noSelectCourses);
                System.out.println("-----------------------------");
                System.out.println("输入课程编号：-1——退出");
                int courseNo = reader.nextInt();
                if (courseNo == -1) {
                    break;
                }
                Course c = CourseDao.getOneByNo(courseNo);
                if (c != null) {
                    Grade g = GradeDAO.getOneByStuAndCourse(s, c);
                    if (g != null) {
                        System.out.println("该课程已经被选择");
                    } else {
                        Grade grade = new Grade();
                        grade.setStudent(s);
                        grade.setCourse(c);
                        GradeDAO.insert(grade);
                    }
                } else {
                    System.out.println("没有这门课！");
                }
            }
        } else {
            System.out.println("没有这个学生！");
        }
    }
    /**
     * 成绩录入
     */
    public static void inputGrade() throws Exception {
        //打印所有课程
        CourseOperation.printCourses(CourseDao.findCourse(""));
        System.out.println("输入课程编号");
        int courseNo = reader.nextInt();
        Course c = CourseDao.getOneByNo(courseNo);
        if (c != null) {
            // 显示课程的所有成绩记录
            while (true) {
                List<Grade> grades = GradeDAO.findGradesByCourse(c);
                printCourseGrade(c, grades);
                System.out.println("请输入学生编号:，-1退出");
                int stuNo = reader.nextInt();
                if (stuNo==-1) {
                    break;
                } else {
                    Student stu = StudentDao.getOneByNo(stuNo);
                    if (stu != null) {
                        Grade g = GradeDAO.getOneByStuAndCourse(stu, c);
                        if (g != null) {
                            System.out.println("输入" + stu.getName() + "的成绩：");
                            double m = reader.nextDouble();
                            GradeDAO.updateGrade(m, g.getNo());
                        } else {
                            System.out.println(stu.getName() + "没有选这门课！");
                        }
                    } else {
                        System.out.println("没有这个学生！");
                    }
                }
            }
        } else {
            System.out.println("没有这门课程");
        }
    }
    /**
     * 打印课程成绩表
     * @param c
     * @param results
     */

    public static void printCourseGrade(Course c, List<Grade> results) {
        System.out.println("课程：" + c.getName());
        System.out.println("学号\t\t学生名字\t\t成绩");
        System.out.println("----------------------------------------");
        for (Grade g : results) {
            System.out.println(g.getStudent().getNo() + "\t\t" + g.getStudent().getName() + "\t\t" + g.getGrade());
        }
        System.out.println("----------------------------------------");
    }

    /**
     * 打印学生成绩表
     * @param s
     * @param results
     */
    public static void printStudentGrade(Student s, List<Grade> results) {
        System.out.println("学生：" + s.getName());
        System.out.println("课程编号\t\t课程名字\t\t成绩");
        System.out.println("----------------------------------------");
        double sum=0;
        for (Grade g : results) {
            System.out.println(g.getCourse().getNo() + "\t\t" + g.getCourse().getName() + "\t\t" + g.getGrade());
            if(g.getGrade()>=60) {
                sum=sum+g.getCourse().getScore();
            }
        }
        System.out.println("已修学分："+sum);
        System.out.println("----------------------------------------");
    }
    public static void queryGradeByStudent() throws Exception{
        System.out.println("请输入学号：");
        int stuNo=reader.nextInt();
        Student s=StudentDao.getOneByNo(stuNo);
        if(s!=null) {
            List<Grade> grades=GradeDAO.findGradesByStudent(s);
            printStudentGrade(s,grades);
        }else {
            System.out.println("没有这个学生！！");
        }
    }
    public static void gradeMenu() {
        while (true) {
            try {
                System.out.println("成绩管理");
                System.out.println("-------------------------");
                System.out.println("1————学生选课");
                System.out.println("2————老师录入成绩");
                System.out.println("3————成绩查询");
                System.out.println("0————退出");
                int s = reader.nextInt();
                if (s == 1) {
                    studentSelectCourse();
                } else if (s == 0) {
                    break;
                }else if(s==2) {
                    inputGrade();
                }else if(s==3) {
                    queryGradeByStudent();
                }
            }catch (Exception e) {
                // TODO: handle exception
                System.out.println("输入有误，请重新输入！！");
            }
        }
    }
    public static void show() {
        try {
            main(new String[]{});
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}


