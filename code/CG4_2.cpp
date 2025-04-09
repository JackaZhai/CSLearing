#include <iostream>
#include <cstring>
using namespace std;
class Mammal {
public:
    Mammal() {
        cout << "Mammal constructor" << endl;
    }
    ~Mammal() {
        cout << "Mammal destructor" << endl;
    }
    void speak() {
        cout << "wang wang" << endl;
    }
};
class Dog : public Mammal {
public:
    Dog() {
        cout << "Dog constructor" << endl;
    }
    ~Dog() {
        cout << "Dog destructor" << endl;
    }
};
void creating() {
    Dog dog;
    dog.speak();
}
int main() {
    creating();
    return 0;
}