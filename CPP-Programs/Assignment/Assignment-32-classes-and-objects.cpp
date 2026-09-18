#include <iostream>
#include <cstring>

using namespace std;

//Q1
class Complex {
    int n1, n2;
    public:
        void setValue(int n1, int n2);
        void print(); 
};

void Complex::setValue(int n1, int n2) {
    this->n1 = n1;
    this->n2 = n2;
}

void Complex::print() {
    cout << "Real: " << n1 << " Imaginary: " << n2 << endl;
} 

//Q2
class Time {
    int hours, minutes, seconds;
    public:
        void setTime(int h, int m, int s);
        void print();
};

void Time::setTime(int h, int m, int s) {
    int tmp;
    if(s >= 60) {
        tmp = s/60;
        s = s - (tmp*60);
        m+=tmp; 
    }
    seconds = s;
    if(m >= 60) {
        tmp = m/60;
        m = m - (tmp*60);
        h+=tmp;
    }
    minutes = m;
    hours = h;
}

void Time::print() {
    cout << hours << " Hr " << minutes << " min " << seconds << " sec" << endl;
}

//Q3
class Date {
    int day, month, year;
    public:
        void setDate(int d, int m, int y);
        void getDate(int pattern);
};

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

//Q4
void Date::getDate(int pattern = 0) {
    if(pattern == 0)
        cout << "d = " << day << " m = " << month << " y = " << year << endl;
    else if(pattern == 1)
        cout << day << "-" << month << "-" << year << endl;
    else if(pattern == 2) {
        char tmp[][15] = {"January", "February", "March", "April", "May",
                          "Jun", "July", "August", "September", "October",
                          "Novermber", "December"};
        
        cout << day << "-" << tmp[month-1] << "-" << year << endl;
    }
}

//Q5
class Circle{
    int radius;
    public:
        void setRadius(int r);
        int getRadius();
        float getArea();
        float getCircumference();
};

void Circle::setRadius(int r) {
    radius = r;
}

int Circle::getRadius() {
    return radius;
}

float Circle::getArea() {
    return 3.14*radius*radius;
}

float Circle::getCircumference() {
    return 2*3.14*radius;
}

int main() {
    // Complex obj;
    // obj.setValue(1, 2);
    // obj.print();
    // Time t1;
    // t1.setTime(2, 69, 301);
    // t1.print();
    Date d1;
    d1.setDate(23, 4, 1965);
    d1.getDate(2);
    return 0;
}