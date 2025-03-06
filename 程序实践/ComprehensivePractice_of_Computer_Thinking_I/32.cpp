#include <iostream>
#include <cmath>    //fabs()的头文件
#include <iomanip>
using namespace std;
int main ()
{
	int n,p;
	double an,d,s=1,e;
	cin>>e;
	n=1,an=1,s=1;
	do{
		an=an*(n)/(2*n+1); 
		s=s+an;
		n++;
		d=2*an;    //次数每加一次'PI值'的差值为:d=2*an,而非d=an
       } 
 while(fabs(d)>=e||n<=2);    //求绝对值的函数  包含在头文件 <cmath>中
 cout<<n<<" "<<setiosflags(ios::fixed)<<setprecision(7)<<2*s;  //保留七位小数  要有<iomanip>
 return 0;
}