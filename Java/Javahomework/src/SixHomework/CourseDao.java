package SixHomework;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
public class CourseDao {

//课程表插入一个课程对象
    public static void insert(Course c) {
        Connection conn = null;
        conn = DatabaseLink.getConn();
        String sql = "insert into course (name,score) values (?,?)";
        try {
            PreparedStatement p = conn.prepareStatement(sql);
            p.setString(1, c.getName());
            p.setDouble(2, c.getScore());
            p.executeUpdate();
            p.close();
            conn.close();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.out.println("数据插入失败！！");
        }

    }

//课程表删除一个课程对象
    public static void delete(int no) {
        Connection conn= null;
        conn = DatabaseLink.getConn();
        String sql="delete from course where no=?";
        PreparedStatement p;
        try {
            p = conn.prepareStatement(sql);
            p.setInt(1, no);
            p.executeUpdate();
            p.close();
            conn.close();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();

        }

    }

    //课程表获得一个课程对象
    public static Course getOneByNo(int no) {
        Connection conn= null;
        conn = DatabaseLink.getConn();
        String sql="select * from course where no=?";
        PreparedStatement p;
        try {
            p = conn.prepareStatement(sql);
            p.setInt(1, no);
            ResultSet result=p.executeQuery();
            while(result.next()) {
                int courseNo=result.getInt("no");
                String name=result.getString("name");
                double score=result.getDouble("score");
                Course c=new Course(courseNo,name,score);
                p.close();
                conn.close();
                return c;

            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return null;
    }

//课程表更新一个课程对象

    public static void update(Course s) {
        Connection conn= null;
        conn = DatabaseLink.getConn();
        String sql="update course set name=?,score=? where no=?";
        PreparedStatement p;

        try {
            p = conn.prepareStatement(sql);
            p.setString(1, s.getName());
            p.setDouble(2, s.getScore());
            p.setInt(3, s.getNo());
            p.executeUpdate();
            p.close();
            conn.close();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    //课程表查询课程

    public static List<Course> findCourse(String key){
        List<Course> courses=new ArrayList<Course>();
        Connection conn= null;
        conn = DatabaseLink.getConn();
        String sql="select * from course where name like ? or no like ?";
        PreparedStatement p;
        try {
            p = conn.prepareStatement(sql);
            p.setString(1, "%"+key+"%");
            p.setString(2, "%"+key+"%");
            ResultSet result=p.executeQuery();
            courses=coursesResults(result);
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return courses;
    }

    public static List<Course> coursesResults(ResultSet result){
        List<Course> courses=new ArrayList<Course>();
        try {
            while(result.next()) {
                int no=result.getInt("no");
                String name=result.getString("name");
                double score=result.getDouble("score");
                Course c=new Course(no,name,score);
                courses.add(c);
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return courses;
    }
}


