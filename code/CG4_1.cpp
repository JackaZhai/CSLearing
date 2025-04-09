
#include <iostream>
using namespace std;
class BaseClass {
public:
    void fn1() {
        cout << "the fn1 founction of the baseclass" << endl;
    }
    void fn2() {
        cout << "the fn2 founction of the baseclass" << endl;
    }
};
class DerivedClass : public BaseClass {
public:
    void fn1() {
        cout << "the fn1 founction of the DerivedClass" << endl;
    }
    void fn2() {
        cout << "the fn2 founction of the DerivedClass" << endl;
    }
};
int main() {
    DerivedClass d;
    BaseClass* p1 = &d;
    DerivedClass* p2 = &d;

    d.fn1();
    d.fn2();
    p1->fn1();
    p1->fn2();
    p2->fn1();
    p2->fn2();

    return 0;
}
