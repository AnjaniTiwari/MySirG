#include <iostream>
using namespace std;

class Complex {
    int n1, n2;
    public:
        Complex(int n1 = 0, int n2 = 0);
		Complex operator+(Complex& obj);
		Complex operator-(Complex& obj);
		Complex operator*(Complex& obj);
		Complex operator/(Complex& obj);
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
    
    return 0;
}