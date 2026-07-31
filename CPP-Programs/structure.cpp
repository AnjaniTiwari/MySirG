#include <iostream>

using namespace std;

struct book {
    private:
        int bookid;
        char title[20];
        float price;
    
    public:
        void input() {
            cout << "Enter bookid, title and price: ";
            cin >> bookid;
            cin.ignore();
            cin.getline(title, sizeof(title));
            cin >> price;
        }

        inline void display() {
            cout << bookid << " " << title << " " << price << endl;    
        }
};



int main() {
    book b;
    b.input();
    b.display();
    cout << endl;
    return 0;
}