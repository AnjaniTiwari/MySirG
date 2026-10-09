#include <iostream>

struct Node {
    int item;
    Node* next;
};

class CLL {
    Node* last;
    public:
        CLL() { last = NULL; }
        CLL(CLL& obj);
        CLL& operator=(CLL& obj);
        void createNode(Node** tmp, int item);
        void insertAtStart(int item);
        void insertAtEnd(int item);
        void insertAtAfter(int item, int inputItem);
        Node* search(int item);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int item);
        void clear();
        void edit(int oldItem, int newItem);
        void display();
        ~CLL();
};

CLL::CLL(CLL& obj) {
	Node* tmp = obj.last;
	last = NULL;
    if(tmp) {
        do {
            tmp = tmp->next;
            insertAtEnd(tmp->item);
        } while(tmp != obj.last);
    }
}

CLL& CLL::operator=(CLL& obj) {
    if(this != &obj) {
        clear();
        Node* tmp = obj.last;
        if(tmp) {
            do {
                tmp = tmp->next;
                insertAtEnd(tmp->item);
            } while(tmp != obj.last);
        }
    }
}

void CLL::createNode(Node** tmp, int item) {
    *tmp = new Node;
    if(*tmp) {
        (*tmp)->item = item;
        (*tmp)->next = NULL;
    }
}

void CLL::insertAtStart(int item) {
    if(!last) {
        createNode(&last, item);
        last->next = last;
    }
    else {
        Node* tmp = NULL;
        createNode(&tmp, item);
        if(tmp) {
            tmp->next = last->next;
            last->next = tmp;
        }
    }
}

void CLL::insertAtEnd(int item) {
    if(!last) {
        createNode(&last, item);
        last->next = last;
    }
    else {
        Node* tmp = NULL;
        createNode(&tmp, item);
        if(tmp) {
            tmp->next = last->next;
            last->next = tmp;
            last = tmp;
        }
    }
}
void CLL::insertAtAfter(int item, int inputItem) {
    Node* tmp = search(item);
    if(tmp) {
        if(tmp == last)
            insertAtEnd(inputItem);
        else if(tmp == last->next)
            insertAtStart(inputItem);
        else {
            Node* tmp2 = NULL;
            createNode(&tmp2, inputItem);
            if(tmp2) {
                tmp2->next = tmp->next;
                tmp->next = tmp2;
            }
        }
    }
    else
        std::cout << item << " is not exist in the list." << std::endl;
}

Node* CLL::search(int item) {
    if(last) {
        Node* tmp = last;
        do {
            if(tmp->item == item)
                return tmp;
            tmp = tmp->next;
        }while(tmp != last);
    }
    return NULL;;
}

void CLL::deleteFirst() {
    if(last == last->next) {
        delete last;
        last = NULL;
    }
    else {
        Node* tmp = last->next;
        last->next = tmp->next;
        delete tmp;
    }
}

void CLL::deleteLast() {
    if(last == last->next) {
        delete last;
        last = NULL;
    }
    else {
        Node* tmp = last->next;
        while(tmp->next != last)
            tmp = tmp->next;
        tmp->next = last->next;
        delete last;
        last = tmp;
    }
}

void CLL::deleteNode(int item) {
    Node* tmp = last;
    if(tmp) {
        if(tmp->next->item == item)
            deleteFirst();
        else if(tmp->item == item)
            deleteLast();
        else {
            tmp = tmp->next;
            while(tmp->next->item != item && tmp->next != last)
                tmp = tmp->next;
            if(tmp->next != last) {
                Node* tmp2 = tmp->next;
                tmp->next = tmp2->next;
                delete tmp2;
            }
            else
                std::cout << item << " is not exist in the list." << std::endl;
        }
    }
    else
        std::cout << "List is empty." << std::endl;
}

void CLL::edit(int oldItem, int newItem) {
    Node* tmp = search(oldItem);
    if(tmp)
        tmp->item = newItem;
    else
        std::cout << oldItem << " is not exist in the list." << std::endl;
}

void CLL::display() {
    Node* tmp = last;
    if(tmp) {
        tmp = last->next;
        while(tmp != last) {
            std::cout << tmp->item << " ";
            tmp = tmp->next;
        }
        std::cout << tmp->item << std::endl;
    }
    else
        std::cout << "List is empty." << std::endl;
}

CLL::~CLL() {
    clear();
}

void CLL::clear() {
    Node* tmp = last, *tmp2 = NULL;
    if(tmp) {
        tmp = tmp->next;
        while(tmp != last) {
            tmp2 = tmp->next;
            delete tmp;
            tmp = tmp2;
        }
        delete last;
        last = NULL;
    }
}

int main() {
    system("clear");
	CLL obj;
	obj.insertAtEnd(2);
	obj.insertAtEnd(3);
	obj.insertAtEnd(5);
	obj.display();
	obj.insertAtStart(1);
	obj.insertAtEnd(7);
	obj.insertAtAfter(5, 6);
	obj.display();
	obj.deleteFirst();
	obj.display();
	obj.deleteLast();
	obj.display();
	obj.deleteNode(5);
	obj.display();
	CLL obj2 = obj;
	obj2.display();
	CLL obj3;
	obj3 = obj2;
	obj3.display();
	getchar();
}