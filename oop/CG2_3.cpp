#include <iostream>
using namespace std;

class Cat {
private:
    int itsAge;                   // 记录猫的年龄
    static int HowManyCats;       // 静态数据成员，记录猫的总数

public:
    // 构造函数
    Cat(int age) {
        itsAge = age;
        HowManyCats++;            // 创建猫对象时，猫数量加1
    }

    // 析构函数
    ~Cat() {
        HowManyCats--;            // 销毁猫对象时，猫数量减1
    }

    // 获取猫的年龄
    int GetAge() const { 
        return itsAge; 
    }

    // 静态成员函数，用于获取猫的总数
    static int GetHowMany() { 
        return HowManyCats; 
    }
};

// 静态数据成员在类外初始化
int Cat::HowManyCats = 0;

int main() {
    // 创建五只猫，年龄从1到5
    Cat cat1(1);
    cout << "Cat1age=" << cat1.GetAge() << endl << endl;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat2(2);
    cout << "Cat2age=" << cat2.GetAge() << endl << endl;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat3(3);
    cout << "Cat3age=" << cat3.GetAge() << endl << endl;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat4(4);
    cout << "Cat4age=" << cat4.GetAge() << endl << endl;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat5(5);
    cout << "Cat5age=" << cat5.GetAge() << endl << endl;
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;

    // 通过局部作用域使cat5先被销毁
    {
        // cat5在这个作用域结束时被销毁
    }
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;

    // cat4被销毁
    {
        // cat4在这个作用域结束时被销毁
    }
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;

    // cat3被销毁
    {
        // cat3在这个作用域结束时被销毁
    }
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;

    // cat2被销毁
    {
        // cat2在这个作用域结束时被销毁
    }
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;

    // cat1被销毁
    {
        // cat1在这个作用域结束时被销毁
    }
    cout << "There are " << Cat::GetHowMany() << " cats alive!" << endl << endl;
    
    return 0;
}