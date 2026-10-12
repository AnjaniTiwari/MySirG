#include <iostream>

struct Node {
    Node* previous;
    int data;
    Node* next;
};

class CDLL {
    Node* start;
    public:
		CDLL() { start = NULL; }
		CDLL(CDLL& obj);
        CDLL& operator=(CDLL& obj);
		void createNode(Node** tmp, int data);
		void insertAtStart(int data);
		void insertAtEnd(int data);
		void insertAtAfter(int data, int inputData);
		Node* search(int data);
		void deleteAtStart();
		void deleteAtEnd();
		void deleteNode(int data);
		void deleteAllNodes();
        ~CDLL();
};

void CDLL::createNode(Node** tmp, int data) {
	(*tmp) = new Node;
	(*tmp)->previous = NULL;
	(*tmp)->data = data;
	(*tmp)->next = NULL;
}

CDLL::CDLL(CDLL& obj) {
	start = NULL;
	if(obj.start != NULL) {
		Node* tmp = obj.start;
		do {
			insertAtEnd(tmp->data);
			tmp = tmp->next;
		} while(tmp != obj.start);
	}
}

CDLL& CDLL::operator=(CDLL& obj) {
	if(this != &obj) {
		if(start)
			deleteAllNodes();
		Node* tmp = obj.start;
		do {
			insertAtEnd(tmp->data);
			tmp = tmp->next;
		} while(tmp != obj.start);
	}
	return *this;
}

void CDLL::insertAtStart(int data) {
	if(!start) {
		createNode(&start, data);
		start->previous = start;
		start->next = start;
	}
	else {
		Node* tmp = NULL;
		createNode(&tmp, data);
		start->previous->next = tmp;
		tmp->next = start;
		tmp->previous = start->previous;
		start->previous = tmp;
		start = tmp;
	}
}

void CDLL::insertAtEnd(int data) {
	if(!start) {
		createNode(&start, data);
		start->previous = start;
		start->next = start;
	}
	else {
		Node* tmp = NULL;
		createNode(&tmp, data);
		start->previous->next = tmp;
		tmp->next = start;
		tmp->previous = start->previous;
		start->previous = tmp;
	}
}

void CDLL::insertAtAfter(int data, int inputData) {
	Node* tmp = search(data);
	if(!tmp)
		std::cout << data << "not exist." << std::endl;
	else {
		if(tmp == start)
			insertAtStart(inputData);
		else if(tmp == start->previous)
			insertAtEnd(inputData);
		else {
			Node* tmp2 = NULL;
			createNode(&tmp2, inputData);
			tmp2->next = tmp->next;
			tmp2->next->previous = tmp2;
			tmp2->previous = tmp;
			tmp->next = tmp2;
		}
	}
}

Node* CDLL::search(int data) {
	Node* tmp = start;
	if(tmp) {
		do {
			if(tmp->data == data)
				return tmp;
			tmp = tmp->next;
		} while(tmp != start);
	}
	return NULL;
}

void CDLL::deleteAtStart() {
	Node* tmp = start;
	if(!tmp)
		std::cout << "list empty." << std::endl;
	else {
		if(tmp->next == start) {
			delete start;
			start = NULL;
		}
		else {
			start = start->next;
			start->previous = tmp->previous;
			start->previous->next = start;
			delete tmp;
		}
	}
}

void CDLL::deleteAtEnd() {
	Node* tmp = start;
	if(!tmp)
		std::cout << "list empty." << std::endl;
	else {
		if(tmp->next == start) {
			delete start;
			start = NULL;
		}
		else {
			tmp = tmp->previous;
			start->previous = tmp->previous;
			tmp->previous->next = start;
			delete tmp;
		}
	}
}

void CDLL::deleteNode(int data) {
	Node* tmp = search(data);
    if(!tmp)
		std::cout << data << "not exist." << std::endl;
	else {
		if(tmp == start)
			deleteAtStart();
		else if(tmp == start->previous)
			deleteAtEnd();
		else {
			tmp->previous->next = tmp->next;
			tmp->next->previous = tmp->previous;
			delete tmp;
		}
	}
}

void CDLL::deleteAllNodes() {
	while(start)
		deleteAtEnd();
}

CDLL::~CDLL() {
    deleteAllNodes();
}

int main() {
	CDLL obj;
	obj.insertAtEnd(1);
	obj.insertAtEnd(2);
	obj.insertAtEnd(3);
	obj.insertAtEnd(4);
//	obj.insertAtAfter(2, 5);
//	obj.deleteAtStart();
//	obj.deleteAtEnd();
//	obj.deleteNode(3);
	CDLL obj2;
	obj2 = obj;
//	obj2.deleteAllNodes();
}