#include <iostream>

using namespace std;

class Item {
        int a, b;
    public:
        void setData(int a, int b) {
            this->a = a;
            this->b = b;
        }
        void showData() {
            cout << a << " " << b << endl;
        }
        Item greater(Item& obj) {
            if(a + b > obj.a + obj.b)
                return *this;
            return obj;
        }
};

int main() {
    system("clear");
    Item i1, i2, i3;
    i1.setData(2, 3);
    i2.setData(2, 1);
    i3 = i1.greater(i2);
    i3.showData();
    return 0;
}