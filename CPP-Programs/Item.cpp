#include <iostream>
using namespace std;

class Item {
    static int k2;
    public:
        int a, b; //Instance member variable
        static int k; //Static member variable or class variable
        static void set_k2(int x) { k2 = x; } // Static member function
        static int get_k2() { return k2; }  // Static member function
 };

int Item::k; // static member variable declaration
int Item::k2;

int main() {
    Item i1, i2;
    // i1.k = 10;
    Item::k = 11;
    // cout << "k = " << i2.k << endl;
    cout << "k = " << Item::k << endl;

    Item::set_k2(20);
    cout << "k2 = " << Item::get_k2() << endl;
    return 0;
}