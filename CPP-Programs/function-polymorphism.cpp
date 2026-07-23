#include <iostream>

using namespace std;

//function overloading or function polymorphism
int add(int n1, int n2) {
    return n1+n2;
}

int add(int n1, int n2, int n3) {
    return n1+n2+n3;
}

int main() {
    int n1, n2, n3;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Sum is " << add(n1, n2);
    cout << endl << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;
    cout << "Sum is " << add(n1, n2, n3);
    cout << endl;
    return 0;
}