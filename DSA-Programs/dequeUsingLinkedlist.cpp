#include <iostream>

struct Node {
	int data;
	Node* next;
};

class Deque {
	Node* front;
	Node* rear;
	Node* createNode(int data);
	public:
		Deque();
		Deque(Deque& obj);
		Deque& operator=(Deque& obj);
		bool isEmpty();
		void insertAtFront(int data);
		void insertAtBack(int data);
		void deleteAtFront();
		void deleteAtBack();
		int getFront();
		int getBack();
		~Deque();
};

Deque::Deque() {
	front = rear = NULL;
}

Deque::Deque(Deque& obj) {
	if(obj.rear) {
    	if(obj.front == obj.rear)
			insertAtFront(obj.front->data);
		else {
			Node* tmp = obj.rear;
			Node* tmp2 = obj.front;
			while(tmp != tmp2) {
				insertAtBack(tmp2->data);
				while(tmp->next != tmp2)
					tmp = tmp->next;
				tmp2 = tmp;
				tmp = obj.rear;
			}
			insertAtBack(tmp2->data);
		}
	}

}

Deque& Deque::operator=(Deque& obj) {
    if(this != &obj) {
		while(rear)
			deleteAtBack();
		if(obj.front == obj.rear)
			insertAtFront(obj.front->data);
		else {
			Node* tmp = obj.rear;
			Node* tmp2 = obj.front;
			while(tmp != tmp2) {
				insertAtBack(tmp2->data);
				while(tmp->next != tmp2)
					tmp = tmp->next;
				tmp2 = tmp;
				tmp = obj.rear;
			}
			insertAtBack(tmp2->data);
		}
	}
	return *this;
}

Node* Deque::createNode(int data) {
	Node* tmp = new Node;
	if(!tmp)
		std::cout << "Memory allocation failed." << std::endl;
	else {
		tmp->data = data;
		tmp->next = NULL;
    }
	return tmp;
}

bool Deque::isEmpty() {
    return front == NULL;
}

void Deque::insertAtFront(int data) {
	if(isEmpty())
		rear = front = createNode(data);
	else {
		front->next = createNode(data);
		front = front->next;
	}
}

void Deque::insertAtBack(int data) {
	if(isEmpty())
		rear = front = createNode(data);
	else {
		Node* tmp = createNode(data);
        if(tmp) {
			tmp->next = rear;
			rear = tmp;
        }
    }
}

void Deque::deleteAtFront() {
	if(rear != NULL) {
		if(front == rear) {
			delete front;
			front = rear = NULL;
		}
		else {
			Node* tmp = rear;
			while(tmp->next != front)
				tmp = tmp->next;
			delete front;
			tmp->next = NULL;
			front = tmp;
		}
	}
}

void Deque::deleteAtBack() {
	if(rear != NULL) {
        if(front == rear) {
			delete rear;
			front = rear = NULL;
		}
		else {
			Node* tmp = rear->next;
			delete rear;
			rear = tmp;
		}
    }
}

int Deque::getFront() {
	if(front)
    	return front->data;
}

int Deque::getBack() {
	if(rear)
    	return rear->data;
}

Deque::~Deque() {
	while(rear)
    	deleteAtBack();
}

int main() {
	Deque obj;
	obj.insertAtFront(1);
	obj.insertAtFront(2);
	obj.insertAtFront(3);
	obj.insertAtFront(4);
	obj.deleteAtFront();
	obj.insertAtBack(5);
	obj.deleteAtFront();
	obj.deleteAtFront();
	obj.insertAtBack(5);
	Deque obj2;
	obj2 = obj;
	getchar();
	return 0;
}

