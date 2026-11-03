#include <iostream>

class Queue {
	int capacity;
	int* ptr;
	int front;
	int rear;
	bool flag;
	public:
		Queue(int cap);
		Queue(Queue& obj);
		Queue& operator=(Queue& obj);
		void insert(int data);
		void viewRear();
		void viewFront();
		void deleteFront();
		bool isFull();
		bool isEmpty();
		int count();
		~Queue();
};

Queue::Queue(int cap = 0) {
	if(cap == 0)
		capacity = cap = 10;
	else
		capacity = cap;

	rear = front = -1;
	flag = false;
	ptr = new int[capacity];
	if(!ptr) {
		std::cout << "Allocation failed." << std::endl;
		capacity = 0;
	}
}

void Queue::insert(int data) {
	if(isFull())
		std::cout << "Queue is full." << std::endl;
	else {
    	if(front == -1)
			front = 0;
		else if(rear == capacity-1) {
			rear = -1;
			flag = true;
		}
		ptr[++rear] = data;

	}
}

void Queue::viewRear() {
	if(isEmpty())
		std::cout << "Queue is empty." << std::endl;
	else
		std::cout << ptr[rear] << " ";
}

void Queue::viewFront() {
    if(isEmpty())
		std::cout << "Queue is empty." << std::endl;
	else
		std::cout << ptr[front] << " ";
}

void Queue::deleteFront() {
	if(isEmpty())
		std::cout << "Queue is empty." << std::endl;
	else {
		if(front == capacity-1) {
			front = 0;
			flag = false;
		}
		else
			front++;
	}

}

Queue::~Queue() {
	delete []ptr;
}

bool Queue::isFull() {
	return (front == 0 && rear == capacity-1 || rear+1 == front);
}

bool Queue::isEmpty() {
	return (front == -1 || (front > rear && !flag));
}

int Queue::count() {
	if(front == -1)
    	return 0;
	else if(!flag)
		return rear+1 - front;
	else
    	return capacity + rear - front;
}

Queue::Queue(Queue& obj) {
	if(obj.capacity > 0) {
		ptr = new int[obj.capacity];
		if(!ptr)
			std::cout << "Allocation failed." << std::endl;
		else {
			for(int i = 0; i < obj.capacity; ++i)
				ptr[i] = obj.ptr[i];
			front = obj.front;
			rear = obj.rear;
			capacity = obj.capacity;
		}
	}
}

Queue& Queue::operator=(Queue& obj) {
	if(this != &obj) {
		if(ptr) {
			delete []ptr;
			ptr = NULL;
        }
		front = rear = -1;
        if(obj.capacity > 0) {
			ptr = new int[obj.capacity];
			if(!ptr)
				std::cout << "Allocation failed." << std::endl;
			else {
				for(int i = 0; i < obj.capacity; ++i)
					ptr[i] = obj.ptr[i];
				front = obj.front;
				rear = obj.rear;
				capacity = obj.capacity;
			}
		}
	}
	return *this;
}

int main() {
	Queue obj(3);
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

