#include <iostream>

using namespace std;

class point {
    private:
        int x, y;
    public:
        void setxy(int a, int b) {
            x = a;
            y = b;
        }
        void displayxy() {
            cout << "(" << x << ","<<y<<")"<<endl;
        }
};

int main() {
    point p1, p2;
    p1.setxy(3, 4);
    p2.setxy(5, 6);
    cout<<"The first point is:";
    p1.displayxy();
    cout<<"The second point is:";
    p2.displayxy();
    return 0;
}