#include <iostream>
#include <cstring>
using namespace std;

//Q1
class Cuboid {
    int length, breath, height;
    public:
        Cuboid(int l, int b, int h);
};

Cuboid::Cuboid(int l, int b, int h) {
    length = l;
    breath = b;
    height = h;
}

//Q2
class Customer {
    int cust_id;
    char name[30];
    char email[50];
    char mobile[13];
    public:
        Customer(int id = 0, char* name = NULL, char* email = NULL, char* mobile = NULL) {
            cust_id = id;
            if(name != NULL) 
                strcpy(this->name, name);
            if(email != NULL)
                strcpy(this->email, email);
            if(mobile != NULL)
                strcpy(this->email, email);
        }
};

//Q3
class Time {
    int hr, min, sec;
    public:
        Time(int h = 0, int m = 0, int s = 0):hr(h), min(m), sec(s) {};
};

//Q4
class Book {
    int book_id;
    char title[50];
    float price;
    public:
        Book(int book_id = 0, char* title = NULL, int price = 0) {
            this->book_id = book_id;
            if(title != NULL)
                strcpy(this->title, title);
            this->price = price;
        }
};

//Q5
class Complex {
    int real, imaginary;
    public:
        Complex(int real = 0, int imaginary = 0) {
            this->real = real;
            this->imaginary = imaginary;
        }
        void showData() {
            cout << "real: " << real << " imaginary: " << imaginary << endl;
        }
};

//Q6
class Numbers {
    int* arr;
    int size;
    public:
        Numbers(int size) {
            arr = new int[size];
            if(!arr)
                cout << "Memory allocation failed." << endl;
        }
        
        Numbers(Numbers &obj) {
            if(this != &obj) {
                arr = new int[obj.size];
                if(!arr)
                    cout << "Memory allocation failed." << endl;
                else {
                    for(int i = 0; i < obj.size; ++i)
                        arr[i] = obj.arr[i];
                        size = obj.size;
                }
            }
        }

        ~Numbers() {
            delete []arr;
        }
};

//Q7
class Student {
    int rollno;
    string name;
    public:
        Student() {
            cout << "Enter rollno: ";
            cin >> rollno;
            cin.ignore();
            cout << "Enter student name: ";
            getline(cin, name);
        }
        void display() {
            cout << "Rollno: " << rollno << " Name: " << name << endl;
        }      
};

//Q8
class Date {
    int day, month, year;
    public:
        Date(int d, int m, int y): day(d), month(m), year(y) {}
};

//Q9
class Room {
    int roomNo;
    string roomType;
    bool is_AC;
    float price;
    public:
        Room(int n, string rt, bool ac, float p): roomNo(n), roomType(rt), is_AC(ac), price(p) {}
};

//Q10
class Circle {
    int redius;
    public:
        Circle() { redius = 1; }
        Circle(int r): redius(r) { }
};

int main() {
    // Complex obj[5];
    // for(int i = 0; i < 5; ++i)
    //     obj[i].showData();
    Student s;
    s.display();
}