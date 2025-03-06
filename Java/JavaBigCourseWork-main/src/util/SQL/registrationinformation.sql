/*
 Navicat Premium Dump SQL

 Source Server         : MySQL
 Source Server Type    : MySQL
 Source Server Version : 80040 (8.0.40)
 Source Host           : localhost:3306
 Source Schema         : registrationinformation

 Target Server Type    : MySQL
 Target Server Version : 80040 (8.0.40)
 File Encoding         : 65001

 Date: 01/01/2025 19:34:53
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for building
-- ----------------------------
DROP TABLE IF EXISTS `building`;
CREATE TABLE `building`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `楼宇名称` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `楼宇编号` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 22 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of building
-- ----------------------------
INSERT INTO `building` VALUES (1, '华庭大厦', '1001');
INSERT INTO `building` VALUES (2, '明月广场', '1002');
INSERT INTO `building` VALUES (3, '天汇大厦', '1003');
INSERT INTO `building` VALUES (4, '湖畔花园', '1004');
INSERT INTO `building` VALUES (5, '东风大厦', '1005');
INSERT INTO `building` VALUES (6, '世纪大楼', '1006');
INSERT INTO `building` VALUES (7, '锦绣豪庭', '1007');
INSERT INTO `building` VALUES (8, '星辰大厦', '1008');
INSERT INTO `building` VALUES (9, '江南大厦', '1009');
INSERT INTO `building` VALUES (10, '凤凰苑', '1010');
INSERT INTO `building` VALUES (11, '海岸大厦', '1011');
INSERT INTO `building` VALUES (12, '阳光花园', '1012');
INSERT INTO `building` VALUES (13, '白鹭岛大厦', '1013');
INSERT INTO `building` VALUES (14, '天一大厦', '1014');
INSERT INTO `building` VALUES (15, '恒星广场', '1015');
INSERT INTO `building` VALUES (16, '博雅大厦', '1016');
INSERT INTO `building` VALUES (17, '云中阁', '1017');
INSERT INTO `building` VALUES (18, '金鹰大厦', '1018');
INSERT INTO `building` VALUES (19, '新天地大厦', '1019');
INSERT INTO `building` VALUES (20, '未来之光', '1020');
INSERT INTO `building` VALUES (21, '恒大', '999');

-- ----------------------------
-- Table structure for people
-- ----------------------------
DROP TABLE IF EXISTS `people`;
CREATE TABLE `people`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `姓名` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `是否业主` tinyint(1) NOT NULL,
  `身份号` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `手机号` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `进入时间` datetime NOT NULL,
  `离开时间` datetime NULL DEFAULT NULL,
  `密码` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 11 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of people
-- ----------------------------
INSERT INTO `people` VALUES (4, '张三', 1, '0', '0', '2025-01-01 19:04:49', '2025-01-01 19:07:34', 'abc123');
INSERT INTO `people` VALUES (5, '翟俊杰', 0, '123', '123', '2025-01-01 19:08:28', NULL, '3z5zf6');
INSERT INTO `people` VALUES (6, 'Tom', 0, '123', '123', '2025-01-01 19:10:17', NULL, 'RK6OFp');
INSERT INTO `people` VALUES (7, '张三', 1, '0', '0', '2025-01-01 19:12:24', '2025-01-01 19:12:40', 'abc123');
INSERT INTO `people` VALUES (8, '123', 0, '123', '123', '2025-01-01 19:12:52', '2025-01-01 19:13:18', 'G87aB2');
INSERT INTO `people` VALUES (9, '李四', 1, '0', '0', '2025-01-01 19:14:23', '2025-01-01 19:14:37', 'abc123');
INSERT INTO `people` VALUES (10, '123', 0, '123', '123', '2025-01-01 19:14:46', '2025-01-01 19:15:05', 'XCWDdQ');

-- ----------------------------
-- Table structure for resident
-- ----------------------------
DROP TABLE IF EXISTS `resident`;
CREATE TABLE `resident`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `名称` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `所属楼宇` int NULL DEFAULT NULL,
  `门牌号` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `进入密码` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `所属楼宇`(`所属楼宇` ASC) USING BTREE,
  CONSTRAINT `resident_ibfk_1` FOREIGN KEY (`所属楼宇`) REFERENCES `building` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 23 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of resident
-- ----------------------------
INSERT INTO `resident` VALUES (1, '张三', 1, '0101', 'abc123');
INSERT INTO `resident` VALUES (2, '李四', 2, '0202', 'abc123');
INSERT INTO `resident` VALUES (3, '王五', 3, '0303', 'abc123');
INSERT INTO `resident` VALUES (4, '赵六', 4, '0404', 'abc123');
INSERT INTO `resident` VALUES (5, '孙七', 5, '0505', 'abc123');
INSERT INTO `resident` VALUES (6, '周八', 6, '0606', 'abc123');
INSERT INTO `resident` VALUES (7, '吴九', 7, '0707', 'abc123');
INSERT INTO `resident` VALUES (8, '郑十', 8, '0808', 'abc123');
INSERT INTO `resident` VALUES (9, '冯十一', 9, '0909', 'abc123');
INSERT INTO `resident` VALUES (10, '陈十二', 10, '1010', 'abc123');
INSERT INTO `resident` VALUES (11, '杨十三', 11, '1111', 'abc123');
INSERT INTO `resident` VALUES (12, '高十四', 12, '1212', 'abc123');
INSERT INTO `resident` VALUES (13, '马十五', 13, '1313', 'abc123');
INSERT INTO `resident` VALUES (14, '丁十六', 14, '1414', 'abc123');
INSERT INTO `resident` VALUES (15, '黎十七', 15, '1515', 'abc123');
INSERT INTO `resident` VALUES (16, '谭十八', 16, '1616', 'abc123');
INSERT INTO `resident` VALUES (17, '蒋十九', 17, '1717', 'abc123');
INSERT INTO `resident` VALUES (18, '邓二十', 18, '1818', 'abc123');
INSERT INTO `resident` VALUES (19, '何二十一', 19, '1919', 'abc123');
INSERT INTO `resident` VALUES (20, '潘二十二', 20, '2020', 'abc123');
INSERT INTO `resident` VALUES (21, '王子', 8, '1666', 'abc123');
INSERT INTO `resident` VALUES (22, 'Tom', 2, '2002', 'abc123');

SET FOREIGN_KEY_CHECKS = 1;
