#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    
    friend Complex operator+( Complex &c1,  Complex &c2);
    friend Complex operator+(double d,  Complex &c);
    friend Complex operator+( Complex &c, double d);
    friend Complex operator-( Complex &c, double d);
    
    friend ostream& operator<<(ostream &out,  Complex &c);
};

Complex operator+( Complex &c1,  Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator+(double d,  Complex &c) {
    return Complex(d + c.real, c.imag);
}

Complex operator+( Complex &c, double d) {
    return Complex(c.real + d, c.imag);
}

Complex operator-( Complex &c, double d) {
    return Complex(c.real - d, c.imag);
}

ostream& operator<<(ostream &out,  Complex &c) {
    out << c.real << "+i" << c.imag;
    return out;
}

int main() {
    Complex a(2, 5), b(7, 8), c;
    
    c = a + b;
    cout << c << endl; 
    
    c = 4.1 + a;
    cout << c << endl; 
    
    c = b - 5.6;
    cout << c << endl; 
    
    return 0;
}