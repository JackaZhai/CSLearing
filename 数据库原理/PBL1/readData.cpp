#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>
#include <cstdlib>

// 品牌结构体（包含品牌编码、品牌名称、品牌网址、品牌图片地址）
struct Brand {
    std::string brandCode;
    std::string brandName;
    std::string brandUrl;
    std::string brandPic;
};

// 商品分类结构体（包含分类编码、分类名称、图片地址）
struct Category {
    std::string categoryCode;
    std::string categoryName;
    std::string image;
};

// 供应商结构体
struct Supplier {
    std::string supplierCode;
    std::string supplierName;
    std::string contact;
    std::string phone;
    std::string description;
};

// 商品结构体
struct Product {
    std::string productCode;
    std::string productName;
    std::string specification;
    std::string model;
    std::string unit;
    double marketPrice;
    std::string brandCode;    // 外键：商品品牌
    std::string categoryCode; // 外键：商品分类
    std::string supplierCode; // 外键：供应商
};

// 通用CSV读取函数，跳过以"//"开头的注释行及表头
std::vector<std::vector<std::string>> readCSV(const std::string &filename) {
    std::vector<std::vector<std::string>> rows;
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "无法打开文件：" << filename << std::endl;
        return rows;
    }
    std::string line;
    bool headerSkipped = false;
    while (std::getline(infile, line)) {
        // 跳过注释行（以"//"开头）
        if (line.size() >= 2 && line.substr(0,2) == "//")
            continue;
        // 跳过第一行表头
        if (!headerSkipped) {
            headerSkipped = true;
            continue;
        }
        std::istringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (!tokens.empty())
            rows.push_back(tokens);
    }
    return rows;
}

// 读取商品品牌数据
std::vector<Brand> loadBrands(const std::string &filename) {
    std::vector<Brand> brands;
    auto rows = readCSV(filename);
    for (const auto &tokens : rows) {
        if (tokens.size() >= 3) {
            // 如果第四个字段不存在，则用空字符串填充
            std::string pic = (tokens.size() >= 4 ? tokens[3] : "");
            Brand b { tokens[0], tokens[1], tokens[2], pic };
            brands.push_back(b);
        }
    }
    return brands;
}

// 读取商品分类数据
std::vector<Category> loadCategories(const std::string &filename) {
    std::vector<Category> categories;
    auto rows = readCSV(filename);
    for (const auto &tokens : rows) {
        if (tokens.size() >= 3) {
            Category c { tokens[0], tokens[1], tokens[2] };
            categories.push_back(c);
        }
    }
    return categories;
}

// 读取供应商数据
std::vector<Supplier> loadSuppliers(const std::string &filename) {
    std::vector<Supplier> suppliers;
    auto rows = readCSV(filename);
    for (const auto &tokens : rows) {
        if (tokens.size() >= 5) {
            Supplier s { tokens[0], tokens[1], tokens[2], tokens[3], tokens[4] };
            suppliers.push_back(s);
        }
    }
    return suppliers;
}

int main() {

    // 先读取品牌、分类和供应商数据
    auto brands = loadBrands("商品品牌.csv");
    auto categories = loadCategories("商品分类.csv");
    auto suppliers = loadSuppliers("供应商.csv");

    // 再读取商品数据
    std::ifstream infile("商品.csv");
    if (!infile) {
        std::cerr << "无法打开文件：商品.csv" << std::endl;
        return 1;
    }
    std::string line;
    std::getline(infile, line); // 跳过表头

    std::vector<Product> products;
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        Product p;
        std::string token;
        // 依次读取商品各字段（按逗号分隔）
        std::getline(ss, p.productCode, ',');    // 商品代码
        std::getline(ss, p.productName, ',');      // 商品名称
        std::getline(ss, p.specification, ',');    // 规格
        std::getline(ss, p.model, ',');            // 型号
        std::getline(ss, p.unit, ',');             // 计量单位
        std::getline(ss, token, ',');              // 市场价
        try {
            p.marketPrice = std::stod(token);
        } catch (...) {
            p.marketPrice = 0.0;
        }
        // 品牌信息（商品中只保存编码）
        std::getline(ss, p.brandCode, ',');
        std::string dummy;
        std::getline(ss, dummy, ',');   // 跳过 CSV 中的品牌名称

        // 分类信息
        std::getline(ss, p.categoryCode, ',');
        std::getline(ss, dummy, ',');   // 跳过 CSV 中的分类名称

        // 供应商信息
        std::getline(ss, p.supplierCode, ',');
        std::getline(ss, dummy, ',');   // 跳过 CSV 中的供应商名称
        
        products.push_back(p);
    }

    // 输出录入统计
    std::cout << "共录入 " << products.size() << " 个商品信息." << std::endl;
    std::cout << "共录入 " << brands.size() << " 个品牌信息." << std::endl;
    std::cout << "共录入 " << categories.size() << " 个分类信息." << std::endl;
    std::cout << "共录入 " << suppliers.size() << " 个供应商信息." << std::endl;
    
    // 示例：显示每个商品关联的详细品牌、分类和供应商信息
    for (const auto &p : products) {
        std::cout << "商品 " << p.productCode << " 对应: ";
        auto itB = std::find_if(brands.begin(), brands.end(),
            [&](const Brand &b) { return b.brandCode == p.brandCode; });
        if (itB != brands.end()) {
            std::cout << "品牌：" << itB->brandName 
                      << " (网址：" << itB->brandUrl 
                      << ", 图片：" << itB->brandPic << ") ";
        }
        auto itC = std::find_if(categories.begin(), categories.end(),
            [&](const Category &c) { return c.categoryCode == p.categoryCode; });
        if (itC != categories.end()) {
            std::cout << "分类：" << itC->categoryName 
                      << " (图片：" << itC->image << ") ";
        }
        auto itS = std::find_if(suppliers.begin(), suppliers.end(),
            [&](const Supplier &s) { return s.supplierCode == p.supplierCode; });
        if (itS != suppliers.end()) {
            std::cout << "供应商：" << itS->supplierName 
                      << " (联系人：" << itS->contact 
                      << ", 电话：" << itS->phone 
                      << ", 简介：" << itS->description << ")";
        }
        std::cout << std::endl;
    }

    return 0;
}