#include <iostream>
using namespace std;

//Q1
class Complex {
    int n1, n2;
    public:
        Complex(int n1 = 0, int n2 = 0);
		Complex operator+(Complex& obj);
		Complex operator-(Complex& obj);
		Complex operator*(Complex& obj);
		Complex operator/(Complex& obj);
		bool operator==(Complex& obj);
		void display();
};

Complex::Complex(int n1, int n2) {
	if(n1 == 0 && n2 == 0)
		this->n1 = this->n2 = 0;
	else {
		this->n1 = n1;
		this->n2 = n2;
	}
}

Complex Complex::operator+(Complex& obj) {
	Complex tmp;
	tmp.n1 = n1 + obj.n1;
	tmp.n2 = n2 + obj.n2;
	return tmp;
}

Complex Complex::operator-(Complex& obj) {
	Complex tmp;
	tmp.n1 = n1 - obj.n1;
	tmp.n2 = n2 - obj.n2;
	return tmp;
}

Complex Complex::operator*(Complex& obj) {
	Complex tmp;
	tmp.n1 = n1 * obj.n1;
	tmp.n2 = n2 * obj.n2;
	return tmp;
}

Complex Complex::operator/(Complex& obj) {
	Complex tmp;
	tmp.n1 = n1 / obj.n1;
	tmp.n2 = n2 / obj.n2;
	return tmp;
}

void Complex::display() {
	std::cout << n1 << ", " << n2 << std::endl;
}

bool Complex::operator==(Complex& obj) {
	if(n1 == obj.n1 && n2 == obj.n2)
		return 1;
	else
    	return 0;
}

//Q2
class Time {
	int hours, minutes, seconds;
	public:
		Time(int h = 0, int m = 0, int s = 0);
		bool operator<(Time& obj);
		void operator++();
		void operator++(int);
		void display();
		Time operator+(Time& obj);

};

Time::Time(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
}

bool Time::operator<(Time& obj) {
	if(hours*60*60 + minutes*50 + seconds < obj.hours*60*60 + obj.minutes*60 + obj.seconds)
		return 1;
	else
		return 0;
}

void Time::operator++() {
	seconds++;
}

void Time::operator++(int) {
	++seconds;
}

void Time::display() {
    std::cout << hours << "-" << minutes << "-" << seconds << std::endl;
}

Time Time::operator+(Time& obj) {
	Time tmp;
	tmp.seconds = seconds + obj.seconds;
	tmp.minutes = minutes + obj.minutes;
	tmp.hours = hours + obj.hours;

	tmp.minutes += (tmp.seconds/60);
	tmp.seconds%=60;
	tmp.hours += (tmp.minutes/60);
	tmp.minutes%=60;
	return tmp;
}



int main() {
	Complex obj1(1, 2), obj2(3, 4), obj3;

	obj3 = obj1+obj2;
	obj3.display();

	obj3 = obj1-obj2;
	obj3.display();

	obj3 = obj1*obj2;
	obj3.display();

	obj3 = obj1/obj2;
	obj3.display();

	getchar();
	return 0;
}