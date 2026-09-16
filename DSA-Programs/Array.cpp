#include <iostream>

using namespace std;

class Array {
    int* arr;
    int capacity;
    int lastIndex;
    public :
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

void Array::createArray(int size) {
    if(size > 0) {
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
    if(lastIndex+1 >= capacity) {
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
    if(lastIndex == -1)
        return true;
    else
        return false;
}

bool Array::isFull() {
    if(lastIndex+1 >= capacity)
        return true;
    else
        return false;
}

void Array::del(int index) {
    if(index <= lastIndex) {
        for(int i = index; i < lastIndex; ++i)
            arr[i] = arr[i+1];
        --lastIndex;
    }
}

void Array::edit(int value, int index) {
    if(index <= lastIndex) {
        arr[index] = value;
    }
}

int Array::count() {
    return lastIndex;
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