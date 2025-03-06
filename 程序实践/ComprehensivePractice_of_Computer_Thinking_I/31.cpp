#include <iostream>
using namespace std;

int main() {
    int data1, data2;
    char op;
    
    cin >> data1 >> data2 >> op;
    
    switch(op) {
        case '+':
            cout << data1 + data2 << endl;
            break;
        case '-':
            cout << data1 - data2 << endl;
            break;
        case '*':
            cout << data1 * data2 << endl;
            break;
        case '/':
            if (data2 != 0) {
                cout << data1 / data2 << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator" << endl;
            break;
    }
    
    return 0;
}