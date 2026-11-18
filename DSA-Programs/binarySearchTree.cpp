#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

class BinarySearchTree {
	Node* root;
	Node* createNode(int data);
	void insertBST(Node*& root, int data);
	void preOrder(Node* tmp);
	void inOrder(Node* tmp);
	void postOrder(Node* tmp);
	public:
		BinarySearchTree();
		void insert(int data);
		void traversal();
};

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

Node* BinarySearchTree::createNode(int data) {
	Node* tmp = new Node;
	if(!tmp)
		std::cout << "Memory allocation failed." << std::endl;
	else {
		tmp->data = data;
		tmp->left = tmp->right = NULL;
	}
	return tmp;
}

//using recursion
void BinarySearchTree::insertBST(Node*& tmp, int data) {
	if(!tmp)
		tmp = createNode(data);
	else if(data < tmp->data)
		insertBST(tmp->left, data);
	else
    	insertBST(tmp->right, data);
}

void BinarySearchTree::insert(int data) {
//    insertBST(root, data);
	if(!root)
		root = createNode(data);
	else {
		Node* tmp = root;
		while(true) {
			if(data < tmp->data) {
				if(!tmp->left) {
					tmp->left = createNode(data);
					break;
				}
				else
					tmp = tmp->left;
			}
			else {
				if(!tmp->right) {
					tmp->right = createNode(data);
					break;
				}
				else
					tmp = tmp->right;
			}
		}
    }
}

void BinarySearchTree::preOrder(Node* tmp) {
    if(tmp) {
		std::cout << tmp->data << " ";
		preOrder(tmp->left);
		preOrder(tmp->right);
    }
}

void BinarySearchTree::inOrder(Node* tmp) {
	if(tmp) {
		inOrder(tmp->left);
		std::cout << tmp->data << " ";
		inOrder(tmp->right);
	}
}

void BinarySearchTree::postOrder(Node* tmp) {
	if(tmp) {
		postOrder(tmp->left);
		postOrder(tmp->right);
		std::cout << tmp->data << " ";
	}
}

void BinarySearchTree::traversal() {
	std::cout << "Pre-order traversal: ";
	preOrder(root);
	std::cout << std::endl << "In-order traversal: ";
	inOrder(root);
	std::cout << std::endl << "Post-order traversal: ";
	postOrder(root);
}



int main() {
	BinarySearchTree obj;
	obj.insert(4);
	obj.insert(2);
	obj.insert(6);
	obj.insert(1);
	obj.insert(7);
	obj.insert(3);
	obj.insert(5);
    obj.traversal();
	getchar();
	return 0;
}


