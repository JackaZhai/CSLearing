#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <clocale>
#include <cstdlib>

// Ʒ�ƽṹ�壨����Ʒ�Ʊ��롢Ʒ�����ơ�Ʒ����ַ��Ʒ��ͼƬ��ַ��
struct Brand {
    std::string brandCode;
    std::string brandName;
    std::string brandUrl;
    std::string brandPic;
};

// ��Ʒ����ṹ�壨����������롢�������ơ�ͼƬ��ַ��
struct Category {
    std::string categoryCode;
    std::string categoryName;
    std::string image;
};

// ��Ӧ�̽ṹ��
struct Supplier {
    std::string supplierCode;
    std::string supplierName;
    std::string contact;
    std::string phone;
    std::string description;
};

// ��Ʒ�ṹ��
struct Product {
    std::string productCode;
    std::string productName;
    std::string specification;
    std::string model;
    std::string unit;
    double marketPrice;
    std::string brandCode;    // �������ƷƷ��
    std::string categoryCode; // �������Ʒ����
    std::string supplierCode; // �������Ӧ��
};

// ͨ��CSV��ȡ������������"//"��ͷ��ע���м���ͷ
std::vector<std::vector<std::string>> readCSV(const std::string &filename) {
    std::vector<std::vector<std::string>> rows;
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "�޷����ļ���" << filename << std::endl;
        return rows;
    }
    std::string line;
    bool headerSkipped = false;
    while (std::getline(infile, line)) {
        // ����ע���У���"//"��ͷ��
        if (line.size() >= 2 && line.substr(0,2) == "//")
            continue;
        // ������һ�б�ͷ
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

// ��ȡ��ƷƷ������
std::vector<Brand> loadBrands(const std::string &filename) {
    std::vector<Brand> brands;
    auto rows = readCSV(filename);
    for (const auto &tokens : rows) {
        if (tokens.size() >= 3) {
            // ������ĸ��ֶβ����ڣ����ÿ��ַ������
            std::string pic = (tokens.size() >= 4 ? tokens[3] : "");
            Brand b { tokens[0], tokens[1], tokens[2], pic };
            brands.push_back(b);
        }
    }
    return brands;
}

// ��ȡ��Ʒ��������
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

// ��ȡ��Ӧ������
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

    // �ȶ�ȡƷ�ơ�����͹�Ӧ������
    auto brands = loadBrands("��ƷƷ��.csv");
    auto categories = loadCategories("��Ʒ����.csv");
    auto suppliers = loadSuppliers("��Ӧ��.csv");

    // �ٶ�ȡ��Ʒ����
    std::ifstream infile("��Ʒ.csv");
    if (!infile) {
        std::cerr << "�޷����ļ�����Ʒ.csv" << std::endl;
        return 1;
    }
    std::string line;
    std::getline(infile, line); // ������ͷ

    std::vector<Product> products;
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        Product p;
        std::string token;
        // ���ζ�ȡ��Ʒ���ֶΣ������ŷָ���
        std::getline(ss, p.productCode, ',');    // ��Ʒ����
        std::getline(ss, p.productName, ',');      // ��Ʒ����
        std::getline(ss, p.specification, ',');    // ���
        std::getline(ss, p.model, ',');            // �ͺ�
        std::getline(ss, p.unit, ',');             // ������λ
        std::getline(ss, token, ',');              // �г���
        try {
            p.marketPrice = std::stod(token);
        } catch (...) {
            p.marketPrice = 0.0;
        }
        // Ʒ����Ϣ����Ʒ��ֻ������룩
        std::getline(ss, p.brandCode, ',');
        std::string dummy;
        std::getline(ss, dummy, ',');   // ���� CSV �е�Ʒ������

        // ������Ϣ
        std::getline(ss, p.categoryCode, ',');
        std::getline(ss, dummy, ',');   // ���� CSV �еķ�������

        // ��Ӧ����Ϣ
        std::getline(ss, p.supplierCode, ',');
        std::getline(ss, dummy, ',');   // ���� CSV �еĹ�Ӧ������
        
        products.push_back(p);
    }

    // ���¼��ͳ��
    std::cout << "��¼�� " << products.size() << " ����Ʒ��Ϣ." << std::endl;
    std::cout << "��¼�� " << brands.size() << " ��Ʒ����Ϣ." << std::endl;
    std::cout << "��¼�� " << categories.size() << " ��������Ϣ." << std::endl;
    std::cout << "��¼�� " << suppliers.size() << " ����Ӧ����Ϣ." << std::endl;
    
    // ʾ������ʾÿ����Ʒ��������ϸƷ�ơ�����͹�Ӧ����Ϣ
    for (const auto &p : products) {
        std::cout << "��Ʒ " << p.productCode << " ��Ӧ: ";
        auto itB = std::find_if(brands.begin(), brands.end(),
            [&](const Brand &b) { return b.brandCode == p.brandCode; });
        if (itB != brands.end()) {
            std::cout << "Ʒ�ƣ�" << itB->brandName 
                      << " (��ַ��" << itB->brandUrl 
                      << ", ͼƬ��" << itB->brandPic << ") ";
        }
        auto itC = std::find_if(categories.begin(), categories.end(),
            [&](const Category &c) { return c.categoryCode == p.categoryCode; });
        if (itC != categories.end()) {
            std::cout << "���ࣺ" << itC->categoryName 
                      << " (ͼƬ��" << itC->image << ") ";
        }
        auto itS = std::find_if(suppliers.begin(), suppliers.end(),
            [&](const Supplier &s) { return s.supplierCode == p.supplierCode; });
        if (itS != suppliers.end()) {
            std::cout << "��Ӧ�̣�" << itS->supplierName 
                      << " (��ϵ�ˣ�" << itS->contact 
                      << ", �绰��" << itS->phone 
                      << ", ��飺" << itS->description << ")";
        }
        std::cout << std::endl;
    }

    return 0;
}