package src.main.java;

import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BuildingManager buildingManager = new BuildingManager();
        ResidentManager residentManager = new ResidentManager();
        EntryManager entryManager = new EntryManager();

        while (true) {
            System.out.println("请选择操作: 1-楼宇信息管理, 2-住户注册, 3-小区进入登记, 4-查询进出状态, 5-退出");
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            try {
                switch (choice) {
                    case 1:
                        manageBuildings(scanner, buildingManager);
                        break;
                    case 2:
                        registerResident(scanner, residentManager);
                        break;
                    case 3:
                        manageEntry(scanner, entryManager);
                        break;
                    case 4:
                        queryEntryStatus(scanner, entryManager);
                        break;
                    case 5:
                        System.out.println("退出系统");
                        return;
                    default:
                        System.out.println("无效的选择!");
                }
            } catch (SQLException e) {
                e.printStackTrace();
                System.out.println("操作失败!");
            }
        }
    }

    private static void manageBuildings(Scanner scanner, BuildingManager buildingManager) throws SQLException {
        System.out.println("请选择操作: 1-新增楼宇, 2-修改楼宇, 3-删除楼宇, 4-查询楼宇");
        int choice = scanner.nextInt();
        scanner.nextLine(); // consume newline

        switch (choice) {
            case 1:
                System.out.println("请输入楼宇名称:");
                String name = scanner.nextLine();
                System.out.println("请输入楼宇编号:");
                String code = scanner.nextLine();
                buildingManager.addBuilding(name, code);
                System.out.println("楼宇新增成功!");
                break;
            case 2:
                System.out.println("请输入楼宇ID:");
                int id = scanner.nextInt();
                scanner.nextLine(); // consume newline
                System.out.println("请输入楼宇名称:");
                name = scanner.nextLine();
                System.out.println("请输入楼宇编号:");
                code = scanner.nextLine();
                buildingManager.updateBuilding(id, name, code);
                System.out.println("楼宇修改成功!");
                break;
            case 3:
                System.out.println("请输入楼宇ID:");
                id = scanner.nextInt();
                scanner.nextLine(); // consume newline
                buildingManager.deleteBuilding(id);
                System.out.println("楼宇删除成功!");
                break;
            case 4:
                buildingManager.queryBuildings();
                break;
            default:
                System.out.println("无效的选择!");
        }
    }

    private static void registerResident(Scanner scanner, ResidentManager residentManager) throws SQLException {
        System.out.println("请输入业主姓名:");
        String name = scanner.nextLine();
        System.out.println("请输入居住楼宇ID:");
        int buildingId = scanner.nextInt();
        scanner.nextLine(); // consume newline
        System.out.println("请输入房间号:");
        String roomNumber = scanner.nextLine();
        System.out.println("请输入进入小区的密码:");
        String password = scanner.nextLine();
        residentManager.registerResident(name, buildingId, roomNumber, password);
        System.out.println("住户注册成功!");
    }

private static void manageEntry(Scanner scanner, EntryManager entryManager) throws SQLException {
    System.out.println("请选择操作: 1-业主进入, 2-访客进入, 3-离开登记");
    int choice = scanner.nextInt();
    scanner.nextLine(); // consume newline

    switch (choice) {
        case 1:
            System.out.println("请输入业主姓名:");
            String name = scanner.nextLine();
            System.out.println("请输入密码:");
            String password = scanner.nextLine();
            entryManager.ownerEntry(name, password);
            break;
        case 2:
            System.out.println("请输入访客姓名:");
            name = scanner.nextLine();
            System.out.println("请输入身份证号:");
            String idNumber = scanner.nextLine();
            System.out.println("请输入手机号:");
            String phoneNumber = scanner.nextLine();
            System.out.println("请输入来访事由:");
            String reason = scanner.nextLine();
            entryManager.visitorEntry(name, idNumber, phoneNumber, reason);
            break;
        case 3:
            System.out.println("请输入姓名:");
            name = scanner.nextLine();
            System.out.println("请输入密码:");
            password = scanner.nextLine();
            entryManager.exit(name, password);
            break;
        default:
            System.out.println("无效的选择!");
    }
}

    private static void queryEntryStatus(Scanner scanner, EntryManager entryManager) throws SQLException {
        System.out.println("请输入查询开始时间 (格式: yyyy-MM-dd HH:mm:ss):");
        String startTimeStr = scanner.nextLine();
        System.out.println("请输入查询结束时间 (格式: yyyy-MM-dd HH:mm:ss):");
        String endTimeStr = scanner.nextLine();
        Timestamp startTime = Timestamp.valueOf(startTimeStr);
        Timestamp endTime = Timestamp.valueOf(endTimeStr);
        entryManager.queryEntryStatus(startTime, endTime);
    }
}