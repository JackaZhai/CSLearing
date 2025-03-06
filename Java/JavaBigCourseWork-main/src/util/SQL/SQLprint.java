package src.util.SQL;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class SQLprint {

    public void printAllTables() throws SQLException {
        printTable("People");
        printTable("Resident");
        printTable("building");
    }

    private void printTable(String tableName) throws SQLException {
        String sql = "SELECT * FROM " + tableName;
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
            System.out.println("Table: " + tableName);
            int columnCount = rs.getMetaData().getColumnCount();
            while (rs.next()) {
                for (int i = 1; i <= columnCount; i++) {
                    System.out.print(rs.getString(i) + "\t");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        SQLprint sqlPrint = new SQLprint();
        try {
            sqlPrint.printAllTables();
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("打印表内容失败!");
        }
    }
}