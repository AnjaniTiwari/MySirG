#include <iostream>

struct Node {
	int data;
	int priorityValue;
	Node* next;
};

class PriorityQueue {
	Node* start;
	Node* createNode(int data, int priorityValue);
	public:
		PriorityQueue();
		PriorityQueue(PriorityQueue& obj);
		PriorityQueue& operator=(PriorityQueue& obj);
		void insert(int data, int priorityValue);
		void deleteNode();
		bool isEmpty();

};

PriorityQueue::PriorityQueue() {
	start = NULL;
}

PriorityQueue::PriorityQueue(PriorityQueue& obj) {
    if(obj.start) {
		Node* tmp = obj.start;
		start = createNode(tmp->data, tmp->priorityValue);
		Node* tmp2 = start;
		while(tmp->next) {
		   tmp = tmp->next;
		   tmp2->next = createNode(tmp->data, tmp->priorityValue);
		   tmp2 = tmp2->next;
        }
    }
}

PriorityQueue& PriorityQueue::operator=(PriorityQueue& obj) {
    if(this != &obj) {
		while(start)
			deleteNode();
        Node* tmp = obj.start;
		start = createNode(tmp->data, tmp->priorityValue);
		Node* tmp2 = start;
		while(tmp->next) {
		   tmp = tmp->next;
		   tmp2->next = createNode(tmp->data, tmp->priorityValue);
		   tmp2 = tmp2->next;
        }
    }
}

Node* PriorityQueue::createNode(int data, int priorityValue) {
	Node* tmp = new Node;
	if(!tmp)
		std::cout << "Memory Allocation failed." << std::endl;
	else {
		tmp->data = data;
		tmp->priorityValue = priorityValue;
		tmp->next = NULL;
	}
	return tmp;
}

void PriorityQueue::insert(int data, int priorityValue) {
	if(!start)
		start = createNode(data, priorityValue);
	else {
		Node* tmp = start;
		Node* previousNode = NULL;
		while(tmp->priorityValue > priorityValue && tmp->next) {
			previousNode = tmp;
			tmp = tmp->next;
		}
		if(!previousNode) {
			start = createNode(data, priorityValue);
			if(start)
				start->next = tmp;
			else
				start = tmp;
		}
		else {
			Node* tmp2 = createNode(data, priorityValue);
			if(tmp2) {
				if(tmp->priorityValue >= priorityValue) {
					tmp2->next = tmp->next;
					tmp->next = tmp2;
				}
				else {
					tmp2->next = previousNode->next;
					previousNode->next = tmp2;
				}
			}
        }
    }
}

bool PriorityQueue::isEmpty() {
	return start == NULL;
}

void PriorityQueue::deleteNode() {
	if(isEmpty())
		std::cout << "Priority Queue is empty." << std::endl;
	else {
		Node* tmp = start->next;
		delete start;
		start = tmp;
    }
}




int main() {
	PriorityQueue obj;
	obj.insert(50, 2);
	obj.insert(40, 7);
	obj.insert(30, 1);
	obj.insert(90, 3);
	obj.insert(120, 8);
	obj.deleteNode();
	PriorityQueue obj2;
	obj2 = obj;
	obj = obj2;
	PriorityQueue obj3 = obj2;
	getchar();
	return 0;
}

