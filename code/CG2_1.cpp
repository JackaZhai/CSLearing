#include <iostream>
 
using namespace std;

class datatype {
private:
    int a;
    char b;
    double c;
    int type;
public:
    datatype(int a){
        this->a = a;
        type = 1;
    }

    datatype(char b){
        this->b = b;
        type = 2;
    }

    datatype(double c){
        this->c = c;
        type = 3;
    }

    void display() {
        if (type == 1) {
            cout << "int:" << a << endl;
        } else if (type == 2) {
            cout << "character:" << b << endl;
        } else if (type == 3) {
            cout << "float:" << c << endl;
        }
    }
};

int main(){
    int n,m;
    char ch;
    double f;
    cin>>n;
    if (n == 1) {
        cin >> m;
        datatype a(m);
        a.display();
    } else if (n == 2) {
        cin >> ch;
        datatype b(ch);
        b.display();
    } else if (n == 3) {
        cin >> f;
        datatype c(f);
        c.display();
    }
    return 0;
}


