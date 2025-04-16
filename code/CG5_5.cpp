#include <iostream>
using namespace std;
class Clock    //时钟类声明
{
public:    //外部接口
    Clock(int NewH=0, int NewM=0, int NewS=0);
    void ShowTime();
     Clock operator ++();        //前置单目运算符重载
 //后置单目运算符重载
     
Clock operator ++(int);
   
 //+运算符重载
         
Clock operator +(Clock &c);
  
private:    //私有数据成员
    int Hour, Minute, Second;
};
Clock::Clock(int NewH, int NewM, int NewS)
{
    Hour = NewH;
    Minute = NewM;
    Second = NewS;
}

Clock Clock::operator++()
{
    Second++;
    if(Second >= 60)
    {
        Second = 0;
        Minute++;
        if(Minute >= 60)
        {
            Minute = 0;
            Hour++;
            if(Hour >= 24)
                Hour = 0;
        }
    }
    return *this;
}

Clock Clock::operator++(int)
{
    Clock p = *this;
    Second++;
    if(Second >= 60)
    {
        Second = 0;
        Minute++;
        if(Minute >= 60)
        {
            Minute = 0;
            Hour++;
            if(Hour >= 24)
                Hour = 0;
        }
    }
    return p; 
}

Clock Clock::operator+(Clock &c)
{
    Clock p;
    p.Second = Second + c.Second;
    p.Minute = Minute + c.Minute;
    p.Hour = Hour + c.Hour;
    
    if(p.Second >= 60)
    {
        p.Second -= 60;
        p.Minute++;
    }
    
    if(p.Minute >= 60)
    {
        p.Minute -= 60;
        p.Hour++;
    }
    
    if(p.Hour >= 24)
    {
        p.Hour %= 24;
    }
    
    return p;
}

void Clock::ShowTime()
{  
   cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

int main()
{
    Clock c1(23,59,59),c2(5,12,10),c3;
    c1.ShowTime();
    c1++;
    c1.ShowTime();
    c3=++c2;
    c3.ShowTime();
    c3=c2+c1;
    c3.ShowTime();
    return 0;
}