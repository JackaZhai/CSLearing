
package FourthHomework;

import SecondHomework.Grade;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.util.Date;
import java.util.Random;
import java.util.Calendar;

@Getter
@Setter
public class Student extends Grade implements Serializable {
    private static final long serialVersionUID = 1L;

    private int id; // 学生ID
    private String major; // 学生专业
    private Date enrollmentDate; // 入学日期

    // 构造方法，根据ID初始化学生信息
    public Student(int id) {
        this.id = id;
        this.major = getRandomMajor(); // 随机生成专业
        this.enrollmentDate = getRandomEnrollmentDate(); // 随机生成入学日期
        this.setJavaScore(getRandomScore()); // 随机生成Java成绩
        this.setHtmlScore(getRandomScore()); // 随机生成HTML成绩
        this.setSqlScore(getRandomScore()); // 随机生成SQL成绩
        this.setTotalScore(this.getJavaScore() + this.getHtmlScore() + this.getSqlScore()); // 计算总成绩
        this.setAverageScore(this.getTotalScore() / 3.0); // 计算平均成绩
    }

    // 随机生成专业
    private String getRandomMajor() {
        String[] majors = {"AI", "大数据", "计算机", "物联网"};
        Random random = new Random();
        return majors[random.nextInt(majors.length)];
    }

    // 随机生成入学日期
    private Date getRandomEnrollmentDate() {
        Random random = new Random();
        Calendar calendar = Calendar.getInstance();
        int year = random.nextInt(10) + 2015; // 随机生成2015-2024年
        int month = random.nextBoolean() ? Calendar.SEPTEMBER : Calendar.MARCH; // 随机生成3月或9月
        calendar.set(year, month, 1);
        return calendar.getTime();
    }

    // 随机生成成绩
    private int getRandomScore() {
        Random random = new Random();
        return random.nextInt(101); // 生成0-100之间的随机数
    }

    // 获取学生ID
    public int getId() {
        return id;
    }

    // 获取学生专业
    public String getMajor() {
        return major;
    }

    // 获取入学日期
    public Date getEnrollmentDate() {
        return enrollmentDate;
    }

    // 重写toString方法，返回学生信息
    @Override
    public String toString() {
        return "ID: " + id + ", Major: " + major + ", Enrollment Date: " + enrollmentDate + ", " + super.toString();
    }
}