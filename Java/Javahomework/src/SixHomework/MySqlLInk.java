package SixHomework;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class MySqlLInk {
    public static Connection getConn(){
        String url="jdbc:mysql://localhost:3306/score_sys?serverTimezone=UTC";
        String user="root";
        String password="welcome123";
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn= DriverManager.getConnection(url,user,password);
            if (conn != null) {
                System.out.println("数据库连接成功");
                return conn;
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}
