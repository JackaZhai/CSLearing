#include <iostream>
#include <cmath>
using namespace std;
class Shape {
public:
    virtual double GetArea() = 0; 
    virtual ~Shape() {} 
};
class Circle : public Shape {
private:
    double R;
public:
    Circle(double r) : R(r) {}
    double GetArea() {
        return 3.14 * R * R; 
    }
};
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double GetArea() {
        return length * width;
    }
};
class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {} 
};
int main() {
    Shape* circle = new Circle(5);
    cout << "The area of the Cirele is:" << circle->GetArea() << endl;
    Shape* rectangle = new Rectangle(4, 6); 
    cout << "The area of the Recanale is:" << rectangle->GetArea() << endl;
    Shape* square = new Square(5); 
    cout << "The area of the Recanale is:" << square->GetArea() << endl;
    delete circle; 
    delete rectangle; 
    delete square;
    return 0;
}

