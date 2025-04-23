#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double val) { x = val; }
    void setY(double val) { y = val; }
    
    double distanceToOrigin() const {
        return sqrt(x * x + y * y);
    }
    
    bool operator<(const Point& p) const {
        return distanceToOrigin() < p.distanceToOrigin();
    }
    
    bool operator>(const Point& p) const {
        return distanceToOrigin() > p.distanceToOrigin();
    }
    
    bool operator==(const Point& p) const {
        return (x == p.x) && (y == p.y);
    }
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

istream& operator>>(istream& is, Point& p) {
    double x, y;
    cout << "输入x坐标: ";
    is >> x;
    cout << "输入y坐标: ";
    is >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

class PointCompare {
public:
    bool operator()(Point& p1, Point& p2) {
        if (p1.getX() == p2.getX()) {
            return p1.getY() < p2.getY();
        }
        return p1.getX() < p2.getX();
    }
};

int main() {
    vector<Point> points;
    points.push_back(Point(3, 4));
    cout << "添加点: (3, 4)" << endl;
    points.push_back(Point(1, 2));
    cout << "添加点: (1, 2)" << endl;
    points.push_back(Point(5, 0));
    cout << "添加点: (5, 0)" << endl;
    points.push_back(Point(2, 2));
    cout << "添加点: (2, 2)" << endl;
    
    // 顺向输出所有点
    cout << "\n===== 顺向输出所有点 =====" << endl;
    for (Point& p : points) {
        cout << p << " ";
    }
    cout << endl;
    cout << "\n逆向输出所有点" << endl;
    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "\n修改指定点的横坐标(+1)" << endl;
    cout << "修改前点1: " << points[0] << endl;
    points[0].setX(points[0].getX() + 1);
    cout << "修改后点1: " << points[0] << endl;
    cout << "\n删除指定点" << endl;
    cout << "删除前点列表: ";
    for (Point& p : points) {
        cout << p << " ";
    }
    cout << endl;
    cout << "删除点: " << points[1] << endl;
    points.erase(points.begin() + 1);
    cout << "删除后点列表: ";
    for (Point& p : points) {
        cout << p << " ";
    }
    cout << endl;
    cout << "\n按到原点距离从小到大排序" << endl;
    vector<Point> sortedPoints1 = points;
    sort(sortedPoints1.begin(), sortedPoints1.end());
    for (Point& p : sortedPoints1) {
        cout << p << " (距离: " << p.distanceToOrigin() << ") " << endl;
    }
    cout << "\n按横纵坐标从小到大排序" << endl;
    vector<Point> sortedPoints2 = points;
    sort(sortedPoints2.begin(), sortedPoints2.end(), PointCompare());
    for (Point& p : sortedPoints2) {
        cout << p << endl;
    }
    return 0;
}
