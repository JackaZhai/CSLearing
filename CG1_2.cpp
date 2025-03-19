#include <iostream>
using namespace std;

class Cat {
private:
    int itsAge;        
    int HowManyCats;   
    static int totalCats;
    
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

int Cat::totalCats = 0;

int main() {

    Cat cat1(1);
    cout << "Cat1age=" << cat1.GetAge() << endl ;
    cout << "There are " << cat1.GetHowMany() << " cats alive!" << endl ;
    
    Cat cat2(2);
    cout << "Cat2age=" << cat2.GetAge() << endl ;
    cout << "There are " << cat2.GetHowMany() << " cats alive!" << endl ;
    
    Cat cat3(3);
    cout << "Cat3age=" << cat3.GetAge() << endl;
    cout << "There are " << cat3.GetHowMany() << " cats alive!" << endl;
    
    Cat cat4(4);
    cout << "Cat4age=" << cat4.GetAge() << endl;
    cout << "There are " << cat4.GetHowMany() << " cats alive!" << endl ;
    
    Cat cat5(5);
    cout << "Cat5age=" << cat5.GetAge() << endl ;
    cout << "There are " << cat5.GetHowMany() << " cats alive!" << endl;

    return 0;
}