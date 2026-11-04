#include <iostream>

struct Node {
	int data;
	Node* next;
};

class Queue {
	Node* front;
	Node* rear;
	Node* createNode(int data);
	public:
		Queue();
		Queue(Queue& obj);
		Queue& operator=(Queue& obj);
		void insert(int data);
		void viewRear();
		void viewFront();
		void deleteFront();
		int count();
		~Queue();
};

Queue::Queue() {
	front = rear = NULL;
}

Node* Queue::createNode(int data) {
	Node* tmp = new Node;
	if(!tmp) {
		std::cout << "Memory allocation failed.";
	}
	else {
		tmp->data = data;
		tmp->next = NULL;
	}
	return tmp;
}

void Queue::insert(int data) {
	Node* tmp = createNode(data);
	if(tmp) {
        if(rear == NULL) {
			rear = tmp;
			front = tmp;
		}
		else {
			tmp->next = rear;
			rear = tmp;
        }
    }
}

void Queue::viewRear() {
	if(!rear)
		std::cout << "Queue is empty." << std::endl;
	else
		std::cout << rear->data << " ";
}

void Queue::viewFront() {
	if(!front)
		std::cout << "Queue is empty." << std::endl;
	else
		std::cout << front->data << " ";
}

void Queue::deleteFront() {
	if(!front)
		std::cout << "Queue is empty." << std::endl;
	else {
    	if(front == rear) {
			delete front;
			front = rear = NULL;
		}
		else {
			Node* tmp = rear;
			while(tmp && tmp->next != NULL && tmp->next->next != NULL)
				tmp = tmp->next;
			delete front;
			tmp->next = NULL;
			front = tmp;
        }
	}

}

Queue::~Queue() {
	while(front)
    	deleteFront();
}

int Queue::count() {
	Node* tmp = rear;
    int count = 0;
	while(tmp) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

Queue::Queue(Queue& obj) {
    Node* tmp = obj.rear;
	Node* tmp2 = NULL, *ptr = NULL;
	rear = front = NULL;
	while(tmp) {
		tmp2 = createNode(tmp->data);
		if(tmp2) {
			if(!rear)
				ptr = rear = tmp2;
			else {
				ptr->next = tmp2;
				ptr = tmp2;
			}
			tmp = tmp->next;
		}
	}
	front = ptr;
}

Queue& Queue::operator=(Queue& obj) {
	if(this != &obj) {
		if(rear)
			this->~Queue();
		Node* tmp = obj.rear;
		Node* tmp2 = NULL, *ptr = NULL;
		while(tmp) {
			tmp2 = createNode(tmp->data);
			if(tmp2) {
				if(!rear)
					ptr = rear = tmp2;
				else {
					ptr->next = tmp2;
					ptr = tmp2;
				}
				tmp2 = tmp2->next;
			}
		}
		front = ptr;
	}
	return *this;
}

int main() {
	Queue obj;
	obj.insert(1);
	obj.insert(2);
	obj.insert(3);
	obj.deleteFront();
	obj.insert(4);
	obj.insert(5);
	obj.insert(6);
	Queue obj2 = obj;
	getchar();
	return 0;
}

