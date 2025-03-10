#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
class Product {
    private:
        int ProductID;
        std::string ProductName;
        int Number;
        std::string Category;
        std::string Brand;
        double ImportPrice;
        double ExportPrice;
        double RealPrice;
        double Discount;
        static int nextID;
    public:
        Product(std::string ProductName, int Number, std::string Category, std::string Brand, double ImportPrice, double ExportPrice, double RealPrice, double Discount) {
            this->ProductID = nextID++;
            this->ProductName = ProductName;
            this->Number = Number;
            this->Category = Category;
            this->Brand = Brand;
            this->ImportPrice = ImportPrice;
            this->ExportPrice = ExportPrice;
            this->RealPrice = RealPrice;
            this->Discount = Discount;
        }

        void setProductID(int ProductID) {
            this->ProductID = ProductID;
        }
        int getProductID() {
            return ProductID;
        }
        void setProductName(std::string ProductName) {
            this->ProductName = ProductName;
        }
        std::string getProductName() {
            return ProductName;
        }
        void setNumber(int Number) {
            this->Number = Number;
        }
        int getNumber() {
            return Number;
        }
        void setCategory(std::string Category) {
            this->Category = Category;
        }
        std::string getCategory() {
            return Category;
        }
        void setBrand(std::string Brand) {
            this->Brand = Brand;
        }
        std::string getBrand() {
            return Brand;
        }
        void setImportPrice(double ImportPrice) {
            if (ImportPrice < 0) {
                std::cout << "进货价格必须大于0" << std::endl;
                return;
            }
            this->ImportPrice = ImportPrice;
        }
        double getImportPrice() {
            return ImportPrice;
        }
        void setExportPrice(double ExportPrice) {
            if (ExportPrice < 0) {
                std::cout << "出售价格必须大于0" << std::endl;
                return;
            }
            this->ExportPrice = ExportPrice;
        }
        double getExportPrice() {
            return ExportPrice;
        }
        void setRealPrice(double RealPrice) {
            if (RealPrice < 0) {
                std::cout << "实际价格必须大于0" << std::endl;
                return;
            }
            this->RealPrice = RealPrice;
        }
        double getRealPrice() {
            return RealPrice;
        }
        void setDiscount(int Discount) {
            if (Discount <= 0) {
                std::cout << "折扣必须大于0" << std::endl;
                return;
            }else if(Discount > 1) {
                std::cout << "折扣必须小于1" << std::endl;
                return;
            }else{
                this->Discount = Discount;
            }
        }
        double getDiscount() {
            return Discount;
        }
        
        void addNumber(int amount) {
            if (amount < 0) {
                std::cout << "数量必须大于0" << std::endl;
                return;
            }
            this->Number += amount;
        }

        void deleteNumber(int amount) {
            if (amount < 0) {
                std::cout << "数量必须大于0" << std::endl;
                return;
            }else if (amount > this->Number) {
                std::cout << "数量必须小于" << this->Number << std::endl;
                return;
            }
            this->Number -= amount;
            if (this->Number < 5){
                std::cout << "警告：产品数量少于5个，请补充库存" << std::endl;
            }
        }

        double computeDiscount(){
            this->Discount = this->RealPrice / this->ExportPrice;
            std::cout << "折扣为: " <<this->Discount << std::endl;
            return this->Discount;
        }

        void display() {
            std::cout << "商品编号: " << this->ProductID << std::endl;
            std::cout << "商品名称: " << this->ProductName << std::endl;
            std::cout << "数量: " << this->Number << std::endl;
            std::cout << "类别: " << this->Category << std::endl;
            std::cout << "品牌: " << this->Brand << std::endl;
            std::cout << "标价: " << this->ExportPrice << std::endl;
            std::cout << "折后价: " << this->RealPrice << std::endl;
        }
    };

int Product::nextID = 1;

int main(){
    std::cout << "创建商品：苹果" << std::endl;
    Product apple("苹果", 10, "水果", "农夫果园", 8, 12.8, 10.0, 0);
    apple.display();
    std::cout << "----------------" << std::endl;
    std::cout << "增加商品数量5个" << std::endl;
    std::cout << "----------------" << std::endl;
    apple.addNumber(5);
    apple.display();
    std::cout << "----------------" << std::endl;
    std::cout << "减少商品数量3个" << std::endl;
    std::cout << "----------------" << std::endl;
    apple.deleteNumber(3);
    apple.display();
    std::cout << "----------------" << std::endl;
    std::cout << "计算苹果折扣" << std::endl;
    apple.computeDiscount();
    std::cout << "----------------" << std::endl;
    std::cout << "创建商品：香蕉" << std::endl;
    Product banana("香蕉", 10, "水果", "农夫果园", 5, 8.8, 7.0, 0);
    banana.display();
    std::cout << "----------------" << std::endl;
    return 0;
}