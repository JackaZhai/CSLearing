package src.util.SQL;

import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;

public class SQLDelete {

    public void resetDatabase() throws SQLException {
        try (Connection conn = DatabaseConnection.getConnection();
             Statement stmt = conn.createStatement()) {
            // 删除所有表中的数据
            stmt.executeUpdate("DELETE FROM People");
            stmt.executeUpdate("DELETE FROM Resident");
            stmt.executeUpdate("DELETE FROM building");
            System.out.println("数据库已重置到初始状态");
        }
    }

    public static void main(String[] args) {
        SQLDelete sqlDelete = new SQLDelete();
        try {
            sqlDelete.resetDatabase();
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("数据库重置失败!");
        }
    }
}