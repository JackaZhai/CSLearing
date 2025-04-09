#include <iostream>
#include <cstring>

const double pi = 3.14159;
using namespace std;

class Point {
    protected:
        double x, y;
    public:
        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }
        void setPoint(double x, double y) {
            this->x = x;
            this->y = y;
        }
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
        void print() {
            cout << "(" << x << ", " << y << ")";
        }
};

class Circle : public Point {
    protected:
        double r;
    public:
        Circle(double x, double y, double r) : Point(x, y) {
            this->r = r;
        }
        void setCircleCenter(double x, double y) {
            setPoint(x, y);
        }
        void setCircle(double x, double y, double r) {
            setCircleCenter(x, y);
            this->r = r;
        }
        double getPerimeter() {
            return 2 * pi * r;
        }
        double getArea() {
            return pi * r * r;
        }
        void print() {
            cout << "圆心坐标："<< "(" << x << ", " << y << ")" << endl;
            cout << "半径：" << r << endl;
            cout << "周长：" << getPerimeter() << endl;
            cout << "面积：" << getArea() << endl;
        }
};

class Rectangle : public Point {
    protected:
        double length, width;
    public:
        Rectangle(double x, double y, double length, double width) : Point(x, y) {
            this->length = length;
            this->width = width;
        }
       
        void setRectangle(double x, double y, double length, double width) {
            setPoint(x, y);
            this->length = length;
            this->width = width;
        }
        double getLength() {
            return length;
        }
        double getWidth() {
            return width;
        }
        double getPerimeter() {
            return 2 * (length + width);
        }
        double getArea() {
            return length * width;
        }
        void print() {
            cout << "矩形中心坐标："<< "(" << x << ", " << y << ")" << endl;
            cout << "长：" << getLength() << endl;
            cout << "宽：" << getWidth() << endl;
            cout << "周长：" << getPerimeter() << endl;
            cout << "面积：" << getArea() << endl;
        }
};

int main() {
    Circle c(0, 0, 5);
    c.print();
    cout << endl;
    c.setCircle(1, 1, 10);
    c.print();
    cout << endl;

    Rectangle r(0, 0, 5.1, 10.5);
    r.print();
    cout << endl;
    r.setRectangle(1, 1, 10, 20);
    r.print();
    cout << endl;

    return 0;
}