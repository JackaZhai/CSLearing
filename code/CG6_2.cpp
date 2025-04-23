#include <iostream>
using namespace std;
class vehicle
{   protected:
    double speed;    //速度,公里/小时
    int wheels;     //轮子数
    double weight; //重量
public:
    vehicle(double speed=80,int wheels=4,double weight=1000);
        virtual void show(void)=0; 
};

vehicle::vehicle(double speed, int wheels, double weight)
{
    this->speed = speed;
    this->wheels = wheels;
    this->weight = weight;
}

class car : public vehicle
{  int passenger_load;
public:
    car(double speed=80,int wheels=4,double weight=1000,int passenger_load=4);
        virtual void show(void);
};

car::car(double speed, int wheels, double weight, int passenger_load)
    : vehicle(speed, wheels, weight)
{
    this->passenger_load = passenger_load;
}

void car::show(void) 
{cout << "Car message\n";
cout<<speed<<" "<<wheels<<" "<<weight<<" "<<passenger_load<<endl;
}
class truck : public vehicle
{ double rated_load;   //额定载重
  public:
      truck(double speed=80,int wheels=4,double weight=2500,double rated_load=3000);
          virtual  void show(void);
};

truck::truck(double speed, int wheels, double weight, double rated_load)
    : vehicle(speed, wheels, weight)
{
    this->rated_load = rated_load;
}

void truck::show(void)
{
    cout << "Truck message\n";
    cout<<speed<<" "<<wheels<<" "<<weight<<" "<<rated_load<<endl;
}

class boat : public vehicle
{ char kind;       //轮船类别，如客轮为'k'
  public:
     boat(double speed=30,int wheels=0,double weight=12000,char kind='k');
        virtual  void show(void);
};

boat::boat(double speed, int wheels, double weight, char kind)
    : vehicle(speed, wheels, weight)
{
    this->kind = kind;
}

void boat::show(void)
{
    cout << "Boat message\n";
    cout<<speed<<" "<<wheels<<" "<<weight<<" "<<kind<<endl;
}

int main()
{  vehicle *unicycle;  car *BMW;
   unicycle = new car;   unicycle ->show(); 
   BMW= (car *) unicycle;   BMW ->show(); 
   delete unicycle;
   unicycle = new truck;   unicycle ->show(); 
   delete unicycle;
   unicycle = new boat;   unicycle ->show(); 
   delete unicycle;
   return 0;
} 
