package src.main.java;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.Scanner;
import src.util.SQL.DatabaseConnection;
import static src.util.Password.PasswordGenerator.generatePassword;


public class EntryManager {

private void recordEntry(String name, boolean isOwner, String idNumber, String phoneNumber, String password) throws SQLException {
    String sql = isOwner ?
        "INSERT INTO People (姓名, 是否业主, 身份号, 手机号, 密码, 进入时间) VALUES (?, ?, ?, ?, ?, ?)" :
        "INSERT INTO People (姓名, 是否业主, 身份号, 手机号, 密码, 进入时间) VALUES (?, ?, ?, ?, ?, ?)";
    try (Connection conn = DatabaseConnection.getConnection();
         PreparedStatement stmt = conn.prepareStatement(sql)) {
        stmt.setString(1, name);
        stmt.setBoolean(2, isOwner);
        if (isOwner) {
            stmt.setString(3, "0"); // 身份证号自动填0
            stmt.setString(4, "0"); // 手机号自动填0
            stmt.setString(5, password);
            stmt.setTimestamp(6, new Timestamp(System.currentTimeMillis()));
        } else {
            stmt.setString(3, idNumber);
            stmt.setString(4, phoneNumber);
            stmt.setString(5, password);
            stmt.setTimestamp(6, new Timestamp(System.currentTimeMillis()));
        }
        stmt.executeUpdate();
    }
}

public void ownerEntry(String name, String password) throws SQLException {
    // Validate owner credentials (not shown in the provided code)
    recordEntry(name, true, "0", "0", password);
    System.out.println("业主进入成功!");
}

public void visitorEntry(String name, String idNumber, String phoneNumber, String reason) throws SQLException {
    String password = generatePassword(); // 生成随机密码
    recordEntry(name, false, idNumber, phoneNumber, password);
    System.out.println("访客进入成功! 生成的密码是: " + password);
}

public void exit(String name, String password) throws SQLException {
    String sql = "UPDATE People p1 " +
                 "JOIN (SELECT MAX(进入时间) AS max_entry_time FROM People WHERE 姓名 = ? AND 离开时间 IS NULL) p2 " +
                 "ON p1.进入时间 = p2.max_entry_time " +
                 "SET p1.离开时间 = ? " +
                 "WHERE p1.姓名 = ? AND p1.密码 = ?";
    try (Connection conn = DatabaseConnection.getConnection();
         PreparedStatement stmt = conn.prepareStatement(sql)) {
        stmt.setString(1, name);
        stmt.setTimestamp(2, new Timestamp(System.currentTimeMillis()));
        stmt.setString(3, name);
        stmt.setString(4, password);
        int rowsUpdated = stmt.executeUpdate();
        if (rowsUpdated > 0) {
            System.out.println("离开登记成功!");
        } else {
            System.out.println("离开登记失败!");
        }
    }
}

    public void queryEntryStatus(Timestamp startTime, Timestamp endTime) throws SQLException {
        String sql = "SELECT * FROM People WHERE 进入时间 BETWEEN ? AND ? OR 离开时间 BETWEEN ? AND ?";
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setTimestamp(1, startTime);
            stmt.setTimestamp(2, endTime);
            stmt.setTimestamp(3, startTime);
            stmt.setTimestamp(4, endTime);
            try (ResultSet rs = stmt.executeQuery()) {
                while (rs.next()) {
                    String name = rs.getString("姓名");
                    boolean isOwner = rs.getBoolean("是否业主");
                    String idNumber = rs.getString("身份号");
                    String phoneNumber = rs.getString("手机号");
                    Timestamp entryTime = rs.getTimestamp("进入时间");
                    Timestamp exitTime = rs.getTimestamp("离开时间");
                    System.out.println("姓名: " + name + ", 是否业主: " + isOwner + ", 身份号: " + idNumber + ", 手机号: " + phoneNumber + ", 进入时间: " + entryTime + ", 离开时间: " + exitTime);
                }
            }
        }
    }
    public static void main(String[] args) {
        EntryManager manager = new EntryManager();
        Scanner scanner = new Scanner(System.in);

        System.out.println("请选择操作: 1-业主进入, 2-访客进入, 3-离开登记");
        int choice = scanner.nextInt();
        scanner.nextLine(); // consume newline

        try {
            if (choice == 1) {
                System.out.println("请输入业主姓名:");
                String name = scanner.nextLine();
                System.out.println("请输入密码:");
                String password = scanner.nextLine();
                manager.ownerEntry(name, password);
            } else if (choice == 2) {
                System.out.println("请输入访客姓名:");
                String name = scanner.nextLine();
                System.out.println("请输入身份证号:");
                String idNumber = scanner.nextLine();
                System.out.println("请输入手机号:");
                String phoneNumber = scanner.nextLine();
                System.out.println("请输入来访事由:");
                String reason = scanner.nextLine();
                manager.visitorEntry(name, idNumber, phoneNumber, reason);
            } else if (choice == 3) {
                System.out.println("请输入姓名:");
                String name = scanner.nextLine();
                System.out.println("请输入密码:");
                String password = scanner.nextLine();
                manager.exit(name, password);
            } else {
                System.out.println("无效的选择!");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("操作失败!");
        }
    }
}