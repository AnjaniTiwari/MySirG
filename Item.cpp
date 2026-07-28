#include <iostream>
using namespace std;

class Item {
    public:
        int a, b; //Instance member variable
        static int k; //Static member variable or class variable
};

int Item::k; // static member variable declaration
int main() {
    Item i1, i2;
    i1.k = 10;
    cout << "k = " << i2.k << endl;
    return 0;
}