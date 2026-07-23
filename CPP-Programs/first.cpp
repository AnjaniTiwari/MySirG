#include <iostream>

using namespace std;

inline int square(int num) {
    return num*num;
}

inline int add(int n1, int n2, int n3 = 0) {
    return n1+n2+n3;
}

int main() {
    // int x;
    // cout << "Enter a number ";
    // cin >> x;
    // cout << "Square of " << x << " is " << square(x) << endl;
    
    int x, y;
    cout << "Enter two number ";
    cin >> x >> y;
    cout <<  add(x, y) << endl;
    
    int z;
    cout << "\nEnter three number ";
    cin >> x >> y >> z;
    cout <<  add(x, y, z) << endl;
    return 0;
}