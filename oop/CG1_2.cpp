#include <iostream>
using namespace std;

int totalCats = 0;

class Cat {
private:
    int itsAge;        
    int HowManyCats;   
    
public:
    Cat(int age) {
        itsAge = age;
        totalCats++;        
        HowManyCats = totalCats; 
    }

    ~Cat() {
        totalCats--;          
        HowManyCats = totalCats; 
        cout << "There are " << HowManyCats << " cats alive!" << endl << endl;
    }

    int GetAge() { 
        return itsAge; 
    }

    int GetHowMany() { 
        return HowManyCats; 
    }
};

int main() {
    Cat cat1(1);
    cout << "Cat1age=" << cat1.GetAge() << endl << endl;
    cout << "There are " << cat1.GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat2(2);
    cout << "Cat2age=" << cat2.GetAge() << endl << endl;
    cout << "There are " << cat2.GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat3(3);
    cout << "Cat3age=" << cat3.GetAge() << endl << endl;
    cout << "There are " << cat3.GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat4(4);
    cout << "Cat4age=" << cat4.GetAge() << endl << endl;
    cout << "There are " << cat4.GetHowMany() << " cats alive!" << endl << endl;
    
    Cat cat5(5);
    cout << "Cat5age=" << cat5.GetAge() << endl << endl;
    cout << "There are " << cat5.GetHowMany() << " cats alive!" << endl << endl;

    return 0;
}