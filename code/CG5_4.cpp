#include<iostream>
#include<iomanip>
using namespace std;

//人民币类的定义与实现
class RMB {
private:
    int yuan, jiao, fen;
public:
    RMB(int y = 0, int j = 0, int f = 0) : yuan(y), jiao(j), fen(f) {
        ten();
    }

    void ten() {
        jiao += fen / 10;
        fen %= 10;
        yuan += jiao / 10;
        jiao %= 10;
    }

    RMB operator+(RMB &other) const {
        RMB temp(yuan + other.yuan, jiao + other.jiao, fen + other.fen);
        temp.ten();
        return temp;
    }

    RMB operator-(const RMB &other) const {
        int totalFen1 = yuan * 100 + jiao * 10 + fen;
        int totalFen2 = other.yuan * 100 + other.jiao * 10 + other.fen;
        int diff = totalFen1 - totalFen2;
        int y = diff / 100;
        diff %= 100;
        int j = diff / 10;
        int f = diff % 10;
        return RMB(y, j, f);
    }

    RMB& operator+=(const RMB &other) {
        yuan += other.yuan;
        jiao += other.jiao;
        fen += other.fen;
        ten();
        return *this;
    }

    RMB& operator++() {
        fen++;
        ten();
        return *this;
    }

    friend istream& operator>>(istream &in, RMB &rmb) {
        cout << "请分别输入元、角、分(整数之间用空格或回车间隔): " << endl;
        in >> rmb.yuan >> rmb.jiao >> rmb.fen;
        rmb.ten();
        return in;
    }

    friend ostream& operator<<(ostream &out, RMB &rmb) {
        if (rmb.yuan < 100) {
            out << "￥ " << rmb.yuan << "." << setw(1) << rmb.jiao << rmb.fen;
        } else {
            out << "￥" << rmb.yuan << "." << setw(1) << rmb.jiao << rmb.fen;
        }
        return out;
    }
};



int main()
{
    RMB  r1(14, 5 ,7),r2,r3;  //定义三个人民币的对象, 其中两个调用缺省的构造, 构造为0
    cout<<"请输入一个人民币数值: \n";
    cin>>r2;  //调用重载的输入流输入对象的数值
    r3=r1+r2;  //调用重载的加法运算符
    cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
    cout<<r3<<" + "<<r1<<" = "; 
    r3+=r1; //调用重载运算符
    cout<<r3<<endl;
    cout<<r3<<" - "<<r1<<" = ";
    r3=r3-r1; //调用重载运算符
    cout<<r3<<endl;
    cout<<r3<<" + "<<"￥  0.01 = ";
    ++r3; //调用重载运算符
    cout<<r3<<endl;
    return 0;
}