#include <iostream>
using namespace std;

class Complex {
    private:
        int a, b;
    public:
        void setValue(int, int);
        void showValue();
};

void Complex::setValue(int x, int y) {
            a = x;
            b = y;
}

void Complex::showValue() {
    cout << a << " " <<b << "i" << endl;
}

int main() {
    Complex c1;
    c1.setValue(2, 5);
    c1.showValue();
    return 0;
}