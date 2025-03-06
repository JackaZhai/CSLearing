package SixHomework;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class StudentDao {

    //数据库学生表插入学生对象
    public static void insert(Student s) {
        Connection conn=DatabaseLink.getConn();
        String sql="insert into student (name,major) "
                + "values ('"+s.getName()+"','"+s.getMajor()+"')";
        DatabaseLink.executeSql(conn, sql);

    }

    //数据库学生表删除学生对象

    public static void delete(int no) {

        Connection conn=DatabaseLink.getConn();
        String sql="delete from student where no=?";
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

    //数据库学生表中获得一个学生对象

    public static Student getOneByNo(int no) {
        Connection conn=DatabaseLink.getConn();
        String sql="select * from student where no=?";
        PreparedStatement p;
        try {
            p = conn.prepareStatement(sql);
            p.setInt(1, no);
            ResultSet result=p.executeQuery();
            while(result.next()) {
                int stuNo=result.getInt("no");
                String name=result.getString("name");
                String major=result.getString("major");
                Student s=new Student(stuNo,name,major);
                p.close();
                conn.close();
                return s;
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return null;

    }

    //数据库学生表更新一个学生对象
    public static void update(Student s) {
        Connection conn=DatabaseLink.getConn();
        String sql="update student set name=?,major=? where no=?";
        PreparedStatement p;
        try {
            p = conn.prepareStatement(sql);
            p.setString(1, s.getName());
            p.setString(2, s.getMajor());
            p.setInt(3, s.getNo());
            p.executeUpdate();
            p.close();
            conn.close();

        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();

        }

    }

    //数据库学生表中查询学生对象，采用模糊查询

    public static List<Student> findStudent(String key){
        List<Student> students=new ArrayList<Student>();
        Connection conn=DatabaseLink.getConn();
        String sql="select * from student where name like ? or major like ? or no like ?";
        PreparedStatement p;

        try {
            p = conn.prepareStatement(sql);
            p.setString(1, "%"+key+"%");
            p.setString(2, "%"+key+"%");
            p.setString(3, "%"+key+"%");

            ResultSet row=p.executeQuery();

            while(row.next()) {
                int stuNo=row.getInt("no");
                String name=row.getString("name");
                String major=row.getString("major");
                Student s=new Student(stuNo,name,major);
                students.add(s);

            }

        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        return students;

    }

}


