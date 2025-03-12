#include <iostream>

using namespace std;

class Cuboid {
private:
    double length, width, height;
public:
    // 默认
    Cuboid() {
        length = 0;
        width = 0;
        height = 0;
    }
    
    // 带参
    Cuboid(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }
    
    void setDimensions(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    double surfaceArea() {
        return 2 * (length * width + length * height + width * height);
    }
    
    double v() {
        return length * width * height;
    }
};

double main() {
    Cuboid cuboid1;
    
    double l1, w1, h1;
    double l2, w2, h2;
    
    cout << "第一个长方体的长、宽、高：";
    cin >> l1 >> w1 >> h1;
    
    cuboid1.setDimensions(l1, w1, h1);
    
    cout << "第二个长方体的长、宽、高：";
    cin >> l2 >> w2 >> h2;
    
    Cuboid cuboid2(l2, w2, h2);
    

    cout << "第一个长方体的表面积为：" << cuboid1.surfaceArea() << endl;
    cout << "第一个长方体的体积为：" << cuboid1.v() << endl;
    cout << "第二个长方体的表面积为：" << cuboid2.surfaceArea() << endl;
    cout << "第二个长方体的体积为：" << cuboid2.v() << endl;
    
    return 0;
}