package src.main.java;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;
import src.util.SQL.DatabaseConnection;

public class ResidentManager {

    public void registerResident(String name, int buildingId, String roomNumber, String password) throws SQLException {
        String sql = "INSERT INTO Resident (名称, 所属楼宇, 门牌号, 进入密码) VALUES (?, ?, ?, ?)";
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, name);
            stmt.setInt(2, buildingId);
            stmt.setString(3, roomNumber);
            stmt.setString(4, password);
            stmt.executeUpdate();
        }
    }

    public static void main(String[] args) {
        ResidentManager manager = new ResidentManager();
        Scanner scanner = new Scanner(System.in);

        System.out.println("请输入业主姓名:");
        String name = scanner.nextLine();

        System.out.println("请输入居住楼宇ID:");
        int buildingId = scanner.nextInt();
        scanner.nextLine();

        System.out.println("请输入房间号:");
        String roomNumber = scanner.nextLine();

        System.out.println("请输入进入小区的密码:");
        String password = scanner.nextLine();

        try {
            manager.registerResident(name, buildingId, roomNumber, password);
            System.out.println("住户注册成功!");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("住户注册失败!");
        }
    }
}