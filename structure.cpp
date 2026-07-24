#include <iostream>
// #include <string>

using namespace std;

struct book {
    int bookid;
    char title[20];
    float price;
};

void input(struct book* b) {
    cout << "Enter bookid, title and price: ";
    cin >> b->bookid;
    cin.ignore();
    cin.getline(b->title, sizeof(b->title));
    cin >> b->price;
}


void display(struct book* b) {
    cout << b->bookid << " " << b->title << " " << b->price << endl; 
}

int main() {
    struct book b;
    input(&b);
    display(&b);
    cout << endl;
    return 0;
}