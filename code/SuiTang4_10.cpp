#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <windows.h> 
using namespace std;

class Point {
public:
    double x, y;
    Point(double a = 0, double b = 0) : x(a), y(b) {}
    
    double d() const {
        return sqrt(x * x + y * y);
    }
};

template <typename T>
void s(T a[], int n) {
    sort(a, a + n);
}

template <>
void s<Point>(Point a[], int n) {
    sort(a, a + n, [](const Point& p, const Point& q) {
        return p.d() < q.d();
    });
}

template <typename T>
void p(T a[], int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

void pp(Point a[], int n) {
    for (int i = 0; i < n; ++i)
        cout << "(" << a[i].x << ", " << a[i].y << ") ";
    cout << endl;
}

int main() {

    
    int a[] = {5, 2, 8, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);
    s(a, n);
    cout << "排序整型数组: "; 
    p(a, n);

    float b[] = {4.4f, 1.1f, 3.3f, 2.2f};
    int m = sizeof(b)/sizeof(b[0]);
    s(b, m);
    cout << "排序浮点数组: ";
    p(b, m);

    double c[] = {3.14, 1.618, 2.718, 0.577};
    int k = sizeof(c)/sizeof(c[0]);
    s(c, k);
    cout << "排序双精度数组: ";
    p(c, k);

    Point d[] = {Point(3,4), Point(1,1), Point(0,5), Point(2,2)};
    int l = sizeof(d)/sizeof(d[0]);
    s(d, l);
    cout << "按距离排序的点: ";
    pp(d, l);

    return 0;
}