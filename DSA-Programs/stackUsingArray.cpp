#include <iostream>

using namespace std;

class Stack {
    int capacity;
    int top;
    int* ptr;
    public:
        Stack();
        Stack(int capacity);
        Stack(Stack& obj);
        Stack& operator=(Stack& obj);
        void createStack(int capacity);
        void push(int value);
        bool isFull();
        int peek();
        bool isEmpty();
        void pop();
        ~Stack();
};

Stack::Stack() {
    capacity = 0;
    top = -1;
    ptr = NULL;
}

Stack::Stack(int capacity) {
    if(capacity > 0) {
        this->ptr = new int[capacity];
        if(this->ptr)
            this->capacity = capacity;
        else
            this->capacity = 0;
        top = -1;
    }
}

void Stack::createStack(int capacity) {
    if(capacity > 0) {
        if(ptr)
            delete []ptr;
        this->ptr = new int[capacity];
        if(this->ptr)
            this->capacity = capacity;
    }
}

bool Stack::isFull() {
    return top == capacity-1;
}

void Stack::push(int value) {
    if(isFull())
        cout << "Stack Overflow." << endl;
    else 
        ptr[++top] = value;   
}

bool Stack::isEmpty() {
    return top == -1;
}

int Stack::peek() {
    if(isEmpty()) {
        cout << "Stack Underflow." << endl;
        return top;
    }
    return ptr[top];
}

void Stack::pop() {
    if(isEmpty()) 
        cout << "Stack Underflow." << endl;
    else 
        --top;
}

Stack::~Stack() {
    if(ptr)
        delete []ptr;
}

Stack::Stack(Stack& obj) {
    if(obj.ptr && obj.capacity > 0) {
        createStack(obj.capacity);
        for(int i = 0; i <= obj.top; ++i)
            push(obj.ptr[i]);
    }
}

Stack& Stack::operator=(Stack& obj) {
    if(this != &obj) {
        if(ptr && capacity > 0) {
            delete []ptr;
            capacity = 0;
            top = -1;
        }
        if(obj.ptr && obj.capacity > 0) {
            createStack(obj.capacity);
            for(int i = 0; i <= obj.top; ++i)
                push(obj.ptr[i]);
        }
    }
    return *this;
}