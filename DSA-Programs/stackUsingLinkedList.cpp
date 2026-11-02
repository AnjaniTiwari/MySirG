#include <iostream>

struct Node{
	int data;
	Node* next;
};

class Stack{
	Node* top;
	public:
		Stack();
		Stack(Stack& obj);
		Stack& operator=(Stack& obj);
		Node* createNode(int data);
		void push(int data);
		int peek();
		void pop();
		void reverse();
		~Stack();
};

Stack::Stack() {
	top = NULL;
}

Node* Stack::createNode(int data) {
	Node* tmp = new Node;
	if(!tmp)
		std::cout << "allocation failed." << std::endl;
	else {
		tmp->data = data;
		tmp->next = NULL;
	}
	return tmp;
}

void Stack::push(int data) {
	Node* tmp = createNode(data);
	if(tmp) {
		tmp->next = top;
		top = tmp;
	}
}

int Stack::peek() {
	if(!top) {
		std::cout << "Stack is empty." << std::endl;
    	return 0;
	}
	return top->data;
}

void Stack::pop() {
	if(!top)
		std::cout << "Stack is empty." << std::endl;
	else {
		Node* tmp = top;
		top = tmp->next;
		delete tmp;
    }
}

Stack::~Stack() {
	while(top)
		pop();
}

Stack::Stack(Stack& obj) {
	top = NULL;
	Node* tmp = obj.top;
	while(tmp) {
		push(tmp->data);
		tmp = tmp->next;
	}
	reverse();
}

Stack& Stack::operator=(Stack& obj) {
    if(this != &obj) {
		this->~Stack();
		Node* tmp = obj.top;
		while(tmp) {
			push(tmp->data);
			tmp = tmp->next;
		}
		reverse();
	}
	return *this;
}

void Stack::reverse() {
	Stack obj;
	Node* tmp = top;
	Node* tmp2;
	while(tmp) {
		obj.push(tmp->data);
		tmp = tmp->next;
		pop();
	}
	if(obj.top) {
		top = obj.top;
		obj.top = NULL;
	}
}

int main() {
	Stack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	Stack obj2;
	obj2 = obj;
	getchar();
	return 0;
}