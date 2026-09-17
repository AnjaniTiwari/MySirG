#include <iostream>

using namespace std;

class Array {
    int* arr;
    int capacity;
    int lastIndex;
    public :
        Array();
        Array(Array& obj);
        Array& operator=(Array& obj);
        void createArray(int size);
        void insert(int value, int index);
        void append(int value);
        int getItem(int index);
        bool isEmpty();
        bool isFull();
        void del(int index);
        void edit(int value, int index);
        int count();
        int getCapacity();
        ~Array();
};

Array::Array() {
    arr = NULL;
}

Array::Array(Array& obj) {
    arr = new int[obj.capacity];
    if(arr) {
        for(int i = 0; i <= lastIndex; ++i)
            arr[i] = obj.arr[i];
        capacity = obj.capacity;
        lastIndex = obj.lastIndex;
    }
}

Array& Array::operator=(Array& obj) {
    if(this != &obj) {
        if(arr)
            delete []arr;
        arr = new int[obj.capacity];
        if(arr) {
            for(int i = 0; i <= lastIndex; ++i)
                arr[i] = obj.arr[i];
            capacity = obj.capacity;
            lastIndex = obj.lastIndex;
        }
    }
    return *this;
}

void Array::createArray(int size) {
    if(size > 0) {
        if(arr)
            delete []arr;
        arr = new int[size];
        capacity = size;
        lastIndex = -1;
    }
}

void Array::insert(int value, int index) {
    if(index < lastIndex) {
        for(int i = ++lastIndex; i > index; --i)
            arr[i] = arr[i-1]; 
        arr[index] = value;
    }
}

void Array::append(int value) {
    if(isFull()) {
        int* tmp = new int[capacity+50];
        if(tmp) {
            for(int i = 0; i < capacity; ++i) 
                tmp[i] = arr[i];
            capacity+=50;
            delete []arr;
            arr = tmp;
        }
    }
    arr[++lastIndex] = value;
}

int Array::getItem(int index) {
    if(index <= lastIndex)
        return arr[index];
    else
        return 0;
}

bool Array::isEmpty() {
    return lastIndex == -1;
}

bool Array::isFull() {
    return lastIndex == capacity-1;
}

void Array::del(int index) {
    if(index >= 0 && index <= lastIndex) {
        for(int i = index; i < lastIndex; ++i)
            arr[i] = arr[i+1];
        --lastIndex;
    }
}

void Array::edit(int value, int index) {
    if(index >= 0 && index <= lastIndex) {
        arr[index] = value;
    }
}

int Array::count() {
    return lastIndex+1;
}

int Array::getCapacity() {
    return capacity;
}

Array::~Array() {
    delete []arr;
}

int main() {
    Array obj;
    // obj.input(10);
    return 0;
}