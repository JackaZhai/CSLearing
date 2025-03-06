#include <iostream>
#include <string>
#include <vector>


class   Product {
    private:
        int ProductID;
        std::string ProductName;
        int Number;
        std::string Category;
        std::string Brand;
        double ImportPrice;
        double ExportPrice;
        double RealPrice;
        int Discount;
    public:
        Product(int ProductID, std::string ProductName, int Number, std::string Category, std::string Brand, double ImportPrice, double ExportPrice, double RealPrice, int Discount) {
            this->ProductID = ProductID;
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
                std::cout << "Import Price must be more than 0" << std::endl;
                return;
            }
            this->ImportPrice = ImportPrice;
        }
        double getImportPrice() {
            return ImportPrice;
        }
        void setExportPrice(double ExportPrice) {
            if (ExportPrice < 0) {
                std::cout << "Export Price must be more than 0" << std::endl;
                return;
            }
            this->ExportPrice = ExportPrice;
        }
        double getExportPrice() {
            return ExportPrice;
        }
        void setRealPrice(double RealPrice) {
            if (RealPrice < 0) {
                std::cout << "Real Price must be more than 0" << std::endl;
                return;
            }
            this->RealPrice = RealPrice;
        }
        double getRealPrice() {
            return RealPrice;
        }
        void setDiscount(int Discount) {
            if (Discount <= 0) {
                std::cout << "Discount must be more than 0" << std::endl;
                return;
            }else if(Discount > 1) {
                std::cout << "Discount must be less than 1" << std::endl;
                return;
            }else{
                this->Discount = Discount;
            }
        }
        int getDiscount() {
            return Discount;
        }
        
        void addNumber(int number) {
            if (number < 0) {
                std::cout << "Number must be more than 0" << std::endl;
                return;
            }
            this->Number += number;
        }

        
    };