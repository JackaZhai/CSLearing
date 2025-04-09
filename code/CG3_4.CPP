#include <iostream>
using namespace std;

class ARR{
    private:
        int n;
        int a[100];
    public:
        ARR(int x[],int size){
            n = size;
            for(int i=0;i<n;i++){
                a[i] = x[i];
            }
        }
        void delsame() {
            if (n <= 1) return; 
            int writeIndex = 1; 
            
            for (int readIndex = 1; readIndex < n; readIndex++) {
                if (a[readIndex] != a[writeIndex-1]) {
                    a[writeIndex] = a[readIndex];
                    writeIndex++;
                }
                
            }
            n = writeIndex;
        }
        void show(){
            int count;
            for(int i=0;i<n;i++){
                if (count==10){
                    cout<<endl;
                    count=0;
                }
                cout<<a[i]<<" ";
                count++;
            }
            cout<<endl;
        }
};

int main(){
    int size=16;
    int x[100] = {1,2,2,3,4,4,5,6,6,7,8,8,8,9,10,10};
    ARR A(x,size);
    A.delsame();
    A.show();
    return 0;
}