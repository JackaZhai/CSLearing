package src.main.java;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import src.util.SQL.DatabaseConnection;

public class BuildingManager {

    public void addBuilding(String name, String code) throws SQLException {
        String sql = "INSERT INTO building (楼宇名称, 楼宇编号) VALUES (?, ?)";
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, name);
            stmt.setString(2, code);
            stmt.executeUpdate();
        }
    }

    public void updateBuilding(int id, String name, String code) throws SQLException {
        String sql = "UPDATE building SET 楼宇名称 = ?, 楼宇编号 = ? WHERE id = ?";
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, name);
            stmt.setString(2, code);
            stmt.setInt(3, id);
            stmt.executeUpdate();
        }
    }

    public void deleteBuilding(int id) throws SQLException {
        String sql = "DELETE FROM building WHERE id = ?";
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.executeUpdate();
        }
    }

    public void queryBuildings() throws SQLException {
        String sql = "SELECT * FROM building";
        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("楼宇名称");
                String code = rs.getString("楼宇编号");
                System.out.println("ID: " + id + ", 名称: " + name + ", 编号: " + code);
            }
        }
    }
}