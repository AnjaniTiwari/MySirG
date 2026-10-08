#include <iostream>
using namespace std;

struct Node{
	int item;
	Node* next;
	Node* previous;
};

class DLL {
	Node* start;
	public:
		DLL();
		DLL(int item);
		DLL(DLL& obj);
		DLL& operator=(DLL& obj);
		void createNode(Node** tmp, int item);
		void insertAtStart(int item);
		void insertAtAfter(int item, int inputItem);
		void insertAtEnd(int item);
		void deleteFirst();
		void deleteEnd();
		void deleteNode(int item);
		Node* search(int item);
		void edit(int oldItem, int newItem);
		int cout();
		void display();
		~DLL();
};

DLL::DLL() {
	start = NULL;
}

DLL::DLL(int item) {
	start = new Node;
	if(start) {
		start->item = item;
		start->next = NULL;
		start->previous = NULL;
	}
}

DLL::DLL(DLL& obj) {
	start = NULL;
	Node* tmp = obj.start;
	while(tmp) {
		insertAtEnd(tmp->item);
		tmp = tmp->next;
	}
}

DLL& DLL::operator=(DLL& obj) {
	if(this != &obj) {
		while(start)
			deleteFirst();
		Node* tmp = obj.start;
		while(tmp) {
			insertAtEnd(tmp->item);
			tmp = tmp->next;
		}
	}
	return *this;
}

void DLL::createNode(Node** tmp, int item) {
	*tmp = new Node;
	if(*tmp) {
		(*tmp)->item = item;
		(*tmp)->next = NULL;
		(*tmp)->previous = NULL;
	}
}

void DLL::insertAtStart(int item) {
	if(!start)
		createNode(&start, item);
	else {
		Node* tmp = NULL;
		createNode(&tmp, item);
		tmp->next = start;
		start->previous = tmp;
		start = tmp;
	}
}

void DLL::insertAtAfter(int item, int inputItem) {
	Node* tmp = search(item);
	if(!tmp)
		std::cout << item << "not exist." << endl;
	else {
		if(!tmp->next)
			insertAtEnd(inputItem);
		else {
			Node* tmp2 = NULL;
			createNode(&tmp2, inputItem);
			tmp2->previous = tmp;
			tmp2->next = tmp->next;
			tmp->next->previous = tmp2;
			tmp->next = tmp2;
		}
	}
}

void DLL::insertAtEnd(int item) {
	if(!start)
		createNode(&start, item);
	else {
		Node* tmp = start;
		while(tmp->next)
			tmp = tmp->next;
		createNode(&tmp->next, item);
		tmp->next->previous = tmp;
	}
}

void DLL::deleteFirst() {
	if(start) {
		Node* tmp = start;
		start = start->next;
		if(start)
			start->previous = NULL;
		delete tmp;
	}
}

void DLL::deleteEnd() {
	if(start) {
		Node* tmp = start;
		while(tmp->next)
			tmp = tmp->next;
		tmp->previous->next = NULL;
		delete tmp;
	}
}

void DLL::deleteNode(int item) {
	Node* tmp = search(item);
	if(!tmp)
		std::cout << item << " not exist." << endl;
	else {
		if(!tmp->previous)
			deleteFirst();
		else if(!tmp->next)
			deleteEnd();
		else {
			tmp->next->previous = tmp->previous;
			tmp->previous->next = tmp->next;
			delete tmp;
		}
	}
}

Node* DLL::search(int item) {
	Node* tmp = start;
	while(tmp) {
		if(tmp->item == item)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void DLL::edit(int oldItem, int newItem) {
	Node* tmp = search(oldItem);
	if(!tmp)
		std::cout << oldItem << "not exist." << endl;
	else
		tmp->item = newItem;
}

int DLL::cout() {
	int c = 0;
	Node* tmp = start;
	while(tmp) {
		c++;
		tmp = tmp->next;
	}
	return c;
}

void DLL::display() {
	Node* tmp = start;
	while(tmp) {
		std::cout << tmp->item << " ";
		tmp = tmp->next;
	}
	std::cout << endl;
}

DLL::~DLL() {
	while(start)
		deleteFirst();
}

int main() {
	system("clear");
	DLL obj;
	obj.insertAtEnd(2);
	obj.insertAtEnd(3);
	obj.insertAtEnd(5);
	obj.display();
	obj.insertAtStart(1);
	obj.insertAtEnd(7);
	obj.insertAtAfter(5, 6);
	obj.display();
	obj.deleteFirst();
	obj.display();
	obj.deleteEnd();
	obj.display();
	obj.deleteNode(5);
	obj.display();
	DLL obj2 = obj;
	obj2.display();
	DLL obj3;
	obj3 = obj2;
	obj3.display();
	getchar();
}