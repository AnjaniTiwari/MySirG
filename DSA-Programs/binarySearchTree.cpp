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
	Node* deleteBstNode(Node*& root, int data);
	void goMaxNode(Node** tmp);
	public:
		BinarySearchTree();
		void insert(int data);
		void traversal();
		void deleteNode(int data);
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

void BinarySearchTree::goMaxNode(Node** tmp) {
	while((*tmp)->right != NULL && (*tmp)->right->right != NULL)
    	(*tmp) = (*tmp)->right;
}

Node* BinarySearchTree::deleteBstNode(Node*& root, int data) {
	if(!root) {
		std::cout << data << " is not the tree." << std::endl;
    	return root;
	}
	if(data < root->data) {
		deleteBstNode(root->left, data);
	}
	else if(data > root->data) {
        deleteBstNode(root->right, data);
	}
	else {
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if(root->left) {
			Node* tmp = root->left;
			if(!tmp->left && !tmp->right) {
				tmp->right = root->right;
				delete root;
				root = tmp;
			}
			else if(!tmp->right) {
				tmp->right = root->right;
				delete root;
                root = tmp;
			}
			else {
				goMaxNode(&tmp);
				if(!tmp->right->left) {
					tmp->right->left = root->left;
					tmp->right->right = root->right;
					delete root;
					root = tmp->right;
					tmp->right = NULL;
				}
				else {
					Node* tmp2 = tmp->right->left;
					tmp->right->left = root->left;
					tmp->right->right = root->right;
                    delete root;
                    root = tmp->right;
					tmp->right = tmp2;
                }
            }
		}
		else {
			Node* tmp = root->right;
			delete root;
			root = tmp;
		}
    }
}

void BinarySearchTree::deleteNode(int data) {
	deleteBstNode(root, data);
}



int main() {
	BinarySearchTree obj;
	obj.insert(10);
	obj.insert(6);
	obj.insert(4);
	obj.insert(3);
	obj.insert(5);
	obj.insert(8);
	obj.insert(7);
	obj.insert(9);
	obj.insert(14);
	obj.insert(12);
	obj.insert(11);
	obj.insert(13);
	obj.insert(16);
	obj.insert(15);
	obj.insert(17);

	obj.deleteNode(10);
	obj.deleteNode(9);
	obj.deleteNode(8);
	obj.deleteNode(7);
	obj.deleteNode(6);
	obj.deleteNode(5);
	obj.deleteNode(4);
	obj.deleteNode(3);

	obj.deleteNode(16);
//	obj.deleteNode(4);
//	obj.deleteNode(3);

//	obj.traversal();
	getchar();
	return 0;
}


