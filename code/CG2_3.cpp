#include <iostream>
using namespace std;

class Cat {
private:
    int itsAge;                   // 记录猫的年龄
    static int HowManyCats;       // 静态数据成员，记录猫的总数

public:
    Cat(int age) {
        itsAge = age;
        HowManyCats++;            // 创建猫对象时，猫数量加1
    }

    ~Cat() {
        HowManyCats--;            // 销毁猫对象时，猫数量减1
        cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl;
    }

    int GetAge() { 
        return itsAge; 
    }

    static int GetHowMany() { 
        return HowManyCats; 
    }
};

int Cat::HowManyCats = 0;

int main() {
    Cat cat1(1);
    cout << "Cat1age=" << cat1.GetAge() << endl ;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl ;
    
    Cat cat2(2);
    cout << "Cat2age=" << cat2.GetAge() << endl ;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl ;
    
    Cat cat3(3);
    cout << "Cat3age=" << cat3.GetAge() << endl;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl;
    
    Cat cat4(4);
    cout << "Cat4age=" << cat4.GetAge() << endl ;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl ;
    
    Cat cat5(5);
    cout << "Cat5age=" << cat5.GetAge() << endl ;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl;
 
    return 0;
}