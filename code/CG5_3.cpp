#include <iostream>

using namespace std;

// Point 类定义
class Point {
private:
    int _x;
    int _y;

public:
    Point(int x = 0, int y = 0) : _x(x), _y(y) {}

    int getX() { return _x; }

    int getY() { return _y; }

    void display() {
        cout << "(" << _x << ", " << _y << ")" << endl;
    }

    Point& operator++() {
        ++_x;
        ++_y;
        return *this;
    }

    Point operator++(int) {
        Point temp = *this; 
        ++(*this);  
        return temp;   
    }

    Point& operator--() {
        --_x;
        --_y;
        return *this; 
    }

    Point operator--(int) {
        Point temp = *this; 
        --(*this);         
        return temp;       
    }
};

int main() {
    int x, y;
    cin >> x >> y;

    Point p(x, y);
    
    Point a1 = p;
    

    a1.display();
    
    Point a2 = p++; 
    a2.display();
    
    Point a3 = ++p;  
    a3.display();
    
    Point a4 = p--;  
    a4.display();
    
    Point a5 = --p; 
    a5.display();
    
    return 0;
}