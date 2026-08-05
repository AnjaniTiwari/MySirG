#include <iostream>
using namespace std;

class Complex {
    private:
        int a, b;
    public:
        void setValue(int, int);
        void showValue();
        Complex add(Complex); 
        Complex(int=0, int=0);
        Complex(Complex&);
};

void Complex::setValue(int x, int y) {
            a = x;
            b = y;
}

void Complex::showValue() {
    cout << a << " " <<b << "i" << endl;
}

Complex Complex::add(Complex obj) {
    Complex temp;
    temp.a = a + obj.a;
    temp.b = b + obj.b;
    return temp;
}

Complex::Complex(int x, int y) {
    a = x;
    b = y;
}

Complex::Complex(Complex &obj) { //copy  constructor
    a = obj.a;
    b = obj.b;
}

int main() {
    Complex c1(3, 4), c2(5), c4;
    Complex c3 = c1.add(c2);
    c3.showValue();
    return 0;
}