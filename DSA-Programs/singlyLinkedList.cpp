#include <iostream>
using namespace std;

typedef struct{
    int item;
    Node* next;
}Node;

class SLL {
    Node* start;
    public:
        SLL(int item);
        SLL(SLL& obj);
        SLL& operator=(SLL& obj);
        void insertAtStart(int item);
        void insertAtLast(int item);
        void insertAfter(int item, int item2);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int item);
        void edit(int item);
        Node& search(int item);
        int count();
        ~SLL();
};

SLL::SLL(int item) { 
    start = new Node;
    if(start) {
        start->item = item;
    }
}
SLL::SLL(SLL& obj) {
    start = new Node;
    if(start) {
        start->item = obj.start->item;
        start->next = obj.start->next;
    }
}

SLL& SLL::operator=(SLL& obj) {
    if(this != &obj) {
        start->item = obj.start->item;
        start->next = obj.start->next;
    }
    return *this;
}

void SLL::insertAtStart(int item) {
    Node* tmp = new Node;
    if(tmp) {
        tmp->item = item;
        tmp->next = start;
    }
    else 
        cout << "Allocation failed." << endl;
    start = tmp;
}

void SLL::insertAtLast(int item) {
    Node* tmp = start; 
    while(tmp != NULL)
        tmp = tmp->next;
    tmp = new Node;
    tmp->item = item;
    tmp->next = NULL;
}

void SLL::insertAfter(int item, int item2) {
    Node* tmp = start; 
    while(tmp != NULL && tmp->item != item)
        tmp = tmp->next;
    if(!tmp)
        cout << item << " not in list." << endl;
    else {
        Node* tmp2 = new Node;
        if(tmp2) {
            tmp2->item = item2;
            tmp2->next = tmp->next;
            tmp->next = tmp2;
        }
        else 
            cout << "Allocation failed." << endl;
    }
}

void SLL::deleteFirst() {
    if(start) {
        Node* tmp = start->next;
        delete start;
        start = tmp;
    }
}

void SLL::deleteLast() {
    if(start) {
        Node* tmp = start;
        while(tmp->next != NULL && tmp->next->next != NULL)
            tmp = tmp->next;
        if(tmp->next == NULL) {
            delete start;
            start = NULL;
        }
        else {
            delete tmp->next;
            tmp->next = NULL;
        }
    }
}

void SLL::deleteNode(int item) {
    if(start) {
        Node* tmp = start;
        while(tmp->item != item && tmp->next != NULL)
            tmp = tmp->next;
        
    }
}