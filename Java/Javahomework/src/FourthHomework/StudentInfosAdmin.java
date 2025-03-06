package FourthHomework;

import java.io.*;
import java.util.*;

public class StudentInfosAdmin {
    private List<Student> students;
    private int nextId;

    // 构造方法，初始化学生列表和下一个学生ID，并从文件加载学生信息
    public StudentInfosAdmin() {
        this.students = new ArrayList<>();
        this.nextId = 0;
        loadStudentsFromFile();
    }

    // 添加学生方法，默认添加50个学生
    public void addStudents() {
    for (int i = 0; i < 50; i++) {
        String firstName = "Student" + (i + 1);
        String lastName = "";
        Student student = new Student(nextId++);
        students.add(student);
    }
    saveStudentsToFile();
}

    // 更新学生成绩方法，根据学生ID更新Java、HTML和SQL成绩
    public void updateStudentScores(int id, int javaScore, int htmlScore, int sqlScore) {
        for (Student student : students) {
            if (student.getId() == id) {
                student.setJavaScore(javaScore);
                student.setHtmlScore(htmlScore);
                student.setSqlScore(sqlScore);
                student.setTotalScore(javaScore + htmlScore + sqlScore);
                student.setAverageScore(student.getTotalScore() / 3.0);
                saveStudentsToFile();
                return;
            }
        }
        System.out.println("未找到ID为 " + id + " 的学生。");
    }

    // 删除学生方法，根据学生ID删除学生
    public void deleteStudent(int id) {
        students.removeIf(student -> student.getId() == id);
        saveStudentsToFile();
    }

    // 搜索学生方法，根据关键词搜索学生专业
    public void searchStudents(String keyword) {
        for (Student student : students) {
            if (keyword.isEmpty() || student.getMajor().contains(keyword)) {
                System.out.println(student);
            }
        }
    }

    // 按入学日期打印学生信息
    public void printStudentsByEnrollmentDate() {
        students.stream()
                .sorted((s1, s2) -> s1.getEnrollmentDate().compareTo(s2.getEnrollmentDate()))
                .forEach(System.out::println);
    }

    // 将学生信息保存到文件
    private void saveStudentsToFile() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("students.txt"))) {
            oos.writeObject(students);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 从文件加载学生信息
    private void loadStudentsFromFile() {
        File file = new File("students.txt");
        if (!file.exists()) {
            saveStudentsToFile(); // 如果文件不存在，创建一个新的文件
        } else {
            try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
                students = (List<Student>) ois.readObject();
                nextId = students.size();
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    // 打印学生成绩统计信息
    public void printStatistics() {
        Optional<Student> maxTotalScoreStudent = students.stream().max(Comparator.comparingInt(Student::getTotalScore));
        Optional<Student> minTotalScoreStudent = students.stream().min(Comparator.comparingInt(Student::getTotalScore));
        Optional<Student> maxJavaScoreStudent = students.stream().max(Comparator.comparingInt(Student::getJavaScore));
        Optional<Student> minJavaScoreStudent = students.stream().min(Comparator.comparingInt(Student::getJavaScore));
        Optional<Student> maxHtmlScoreStudent = students.stream().max(Comparator.comparingInt(Student::getHtmlScore));
        Optional<Student> minHtmlScoreStudent = students.stream().min(Comparator.comparingInt(Student::getHtmlScore));
        Optional<Student> maxSqlScoreStudent = students.stream().max(Comparator.comparingInt(Student::getSqlScore));
        Optional<Student> minSqlScoreStudent = students.stream().min(Comparator.comparingInt(Student::getSqlScore));

        System.out.println("总分最高的学生: " + maxTotalScoreStudent.orElse(null));
        System.out.println("总分最低的学生: " + minTotalScoreStudent.orElse(null));
        System.out.println("Java成绩最高的学生: " + maxJavaScoreStudent.orElse(null));
        System.out.println("Java成绩最低的学生: " + minJavaScoreStudent.orElse(null));
        System.out.println("HTML成绩最高的学生: " + maxHtmlScoreStudent.orElse(null));
        System.out.println("HTML成绩最低的学生: " + minHtmlScoreStudent.orElse(null));
        System.out.println("SQL成绩最高的学生: " + maxSqlScoreStudent.orElse(null));
        System.out.println("SQL成绩最低的学生: " + minSqlScoreStudent.orElse(null));
    }
}