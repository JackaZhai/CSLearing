#include <iostream>
#include <iomanip>

using namespace std;

class martix
{
    private:
        int a[2][3];
    public:

    martix operator+(martix &m)
    {
        martix temp;
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                temp.a[i][j]=a[i][j]+m.a[i][j];
        return temp;
    }
    martix operator-(martix &m)
    {
        martix temp;
        for(int i=0;i<2;i++)
            for(int j=0;j<3;j++)
                temp.a[i][j]=a[i][j]-m.a[i][j];
        return temp;
    }
    martix operator<<(martix &m)
    {
        for (int i=0;i<2;i++) {
            if(i==1) {cout<<endl;}
            for (int j=0;j<3;j++)
                cout<<setw(7)<<a[i][j];
        }
        cout<<endl;
        return m;
    }

    martix operator>>(martix &m)
    {
        cout<<"请输入2行3列矩阵内容:"<<endl;
        for (int i=0;i<2;i++)
            for (int j=0;j<3;j++)
                cin>>a[i][j];
        return m;
    }   
};

int main(){
    martix m1,m2;
    m1>>m1; 
    m2>>m2;
    cout<<"m1+m2="<<endl;
    m1+m2<<m1;
    cout<<"m1-m2="<<endl;
    m1-m2<<m1;
    return 0;
}