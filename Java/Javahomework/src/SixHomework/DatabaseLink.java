package SixHomework;

import java.sql.*;
public class DatabaseLink {

//实现对MySQL中一个数据库的连接访问
    public static Connection getConn() {
        String driverName = "com.mysql.cj.jdbc.Driver";
        String dbUrl = "jdbc:mysql://localhost:3306/studentadmin?serverTimezone=UTC";
        String userName = "root";//用自己数据库的用户名
        String password = "123456789"; //用自己数据库的密码

        try {
            Class.forName(driverName);
            Connection conn;
            conn = DriverManager.getConnection(dbUrl, userName, password);
            if (conn != null) {
                return conn;
            }
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.out.println("数据库连接失败！");
        }
        return null;
    }

    //封装一个数据库SQL操作方法

    public static void executeSql(Connection c,String sql) {
        try {
            PreparedStatement p=c.prepareStatement(sql);
            p.executeUpdate();
            p.close();
            c.close();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
            System.out.println("数据库操作异常！");
        }
    }

}

