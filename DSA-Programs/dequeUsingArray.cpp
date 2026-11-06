#include <iostream>

class Deque {
	int* arr;
	int capacity;
	int front;
	int rear;
	public:
		Deque(int cap);
		Deque(Deque& obj);
		Deque& operator=(Deque& obj);
		bool isFull();
		bool isEmpty();
		void insertAtFront(int data);
		void insertAtBack(int data);
		void deleteAtFront();
		void deleteAtBack();
		int getFront();
		int getBack();
		~Deque();
};

Deque::Deque(int cap = 0) {
	if(cap > 0) {
		arr = new int[cap];
		if(arr) {
			rear = front = -1;
			capacity = cap;
		}
	}
	else {
		arr = NULL;
		capacity = 0;
		front = -1;
		rear = -1;
    }
}

Deque::Deque(Deque& obj) {
	if(obj.arr && obj.capacity > 0) {
		arr = new int[obj.capacity];
		if(arr) {
			for(int i = 0; i < obj.capacity; ++i)
				arr[i] = obj.arr[i];
			capacity = obj.capacity;
			front = obj.front;
			rear = obj.rear;
		}
	}
}

Deque& Deque::operator=(Deque& obj) {
	if(this != &obj) {
		this->~Deque();
		if(obj.arr && obj.capacity > 0) {
			arr = new int[obj.capacity];
			if(arr) {
				for(int i = 0; i < obj.capacity; ++i)
					arr[i] = obj.arr[i];
				capacity = obj.capacity;
				front = obj.front;
				rear = obj.rear;
			}
		}
	}
	return *this;
}

Deque::~Deque() {
	if(arr)
    	delete []arr;
}

bool Deque::isFull() {
    return (front == 0 && rear == capacity-1 || (rear+1)%capacity == front);
}

bool Deque::isEmpty() {
	return front == -1 || front > rear;
}

void Deque::insertAtFront(int data) {
	if(front == -1) {
		front = rear = 0;
		arr[front] = data;
	}
	else {
		if(isFull())
			std::cout << "Deque is full." << std::endl;
		else {
			for(int i = rear; i >= front; --i)
				arr[(i+1)%capacity] = arr[i];
			arr[front] = data;
			rear++;

		}
    }
}

void Deque::insertAtBack(int data) {
    if(rear == -1) {
		front = rear = 0;
		arr[rear] = data;
	}
	else {
		if(isFull())
			std::cout << "Deque is full." << std::endl;
		else {
			arr[(rear+1)%capacity] = data;
			rear++;
        }
    }
}

void Deque::deleteAtFront() {
	if(isEmpty()) {
		std::cout << "Deque is empty." << std::endl;
    	front = rear = -1;
	}
	else
		front++;
}

void Deque::deleteAtBack() {
	if(isEmpty()) {
		std::cout << "Deque is empty." << std::endl;
    	front = rear = -1;
	}
	else
		rear--;
}

int Deque::getFront() {
	if(isEmpty())
		throw -1;
	else
		return arr[front%capacity];

}

int Deque::getBack() {
	if(isEmpty())
		throw -1;
	else
		return arr[rear%capacity];
}


int main() {
	Deque obj(4);
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

