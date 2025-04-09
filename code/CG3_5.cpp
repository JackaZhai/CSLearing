#include <iostream>
using namespace std;

class ARRAY {
private:
    int a[100];
    int n;
public:
    ARRAY(int t[], int m) {
        n = m;
        for(int i = 0; i < n; i++) {
            a[i] = t[i];
        }
    }
    
    int sum(int x) {
        int total = 0;
        if(x < 0) x = -x;
        
        while(x > 0) {
            total += x % 10;
            x /= 10;
        }
        return total;
    }
    
    void fun() {
        for(int i = 0; i < n-1; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(sum(a[j]) > sum(a[j+1])) {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
    }
    
    void print() {
        for(int i = 0; i < n; i++) {
            cout << a[i] << "\t";
        }
        cout << endl;
    }
};

int main()    
{    
    int a[]={297,735,624,158,312,900};
    ARRAY arr(a,sizeof(a)/sizeof(int));
    cout<<"排序前："; 
    arr.print();
    arr.fun();
    cout<<"排序后：";
    arr.print();
    return 0;
}