#include <iostream>

using namespace std;

class Item {
    int a, b;
    public:
        void setData(int x, int y);
        void showData();
        friend Item operator+(Item i1, Item i2);
        friend istream& operator>>(istream& cin, Item &obj);
        friend ostream& operator<<(ostream& count, Item &obj);
};

void Item::setData(int x, int y) {
    a = x;
    b = y;
}

void Item::showData() {
    cout << "a = " << a << ", b = " << b << endl;
}

Item operator+(Item i1, Item i2) {
    Item temp;
    temp.a = i1.a + i2.a;
    temp.b = i1.b + i2.b;
    return temp;
}

istream& operator>>(istream& cin, Item &obj) {
    cout << "Enter a and b: ";
    cin >> obj.a >> obj.b;
    return cin;
}

ostream& operator<<(ostream& cout, Item& obj) {
    cout << "a = " << obj.a << ", b = " << obj.b << endl;
    return cout;
}

int main() {
    Item i1, i2, i3;
    cin >> i1 >> i2;
    i3 = i1 + i2;
    cout << i1 << i2 << i3;
    return 0;
}
