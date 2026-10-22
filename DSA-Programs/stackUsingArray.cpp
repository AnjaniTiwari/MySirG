#include <iostream>

using namespace std;

class Stack {
    int capacity;
    int top;
    int* ptr;
    public:
        Stack(int capacity);
};

Stack::Stack(int capacity) {
    this->capacity = 0;
    if(capacity > 0) {
        this->ptr = new int[capacity];
        if(this->ptr)
            this->capacity = capacity;
    }
}

