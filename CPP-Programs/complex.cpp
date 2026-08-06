#include <iostream>
using namespace std;

class Complex {
    private:
        int a, b;
        // const int k;
        // int &k2;
    public:
        void setValue(int, int);
        void showValue();
        Complex operator+(Complex); 
        Complex operator-(Complex);
        Complex operator-();
        Complex(int = 0, int = 0);
        Complex(Complex&);
};

void Complex::setValue(int x, int y) {
            a = x;
            b = y;
}

void Complex::showValue() {
    cout << a << " " <<b << "i" << endl;
}

Complex Complex::operator+(Complex obj) {
    Complex temp;
    temp.a = a + obj.a;
    temp.b = b + obj.b;
    return temp;
}

Complex::Complex(int x, int y) : a(x), b(y){ }

Complex::Complex(Complex &obj) { //copy  constructor
    a = obj.a;
    b = obj.b;
}

Complex Complex::operator-(Complex obj) {
    Complex temp;
    temp.a = a - obj.a;
    temp.b = b - obj.b;
    return temp;
}

Complex Complex::operator-() {
    Complex temp;
    temp.a = -a;
    temp.b = -b;
    return temp;
}

int main() {
    Complex c1(3, 4), c2(5), c3;
    // c3 = c1.operator+(c2);
    c3 = c1 + c2;
    c3.showValue();
    c1 = c3 - c2;
    c1.showValue();
    c3=-c1;
    c3.showValue();
    return 0;
}