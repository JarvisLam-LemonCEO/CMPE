#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

template <class T>
class BinaryTree{
private:
	struct Node{ 
		T val;
		Node* left;
		Node* right;
	};
	
	Node* root;

	void insertNode(Node&);
	void destroy(Node*);
	void findDeleteNode(T,Node*&);
	void deleteNode(Node*&);
	void printInOrder(Node*) const;
	void printPreOrder(Node*) const;
	void printPostOrder(Node*) const;
	int nodeCounter(Node *node);
	int leaftCounter(Node *node);
	
public:
	
	BinaryTree():root(nullptr){}
	~BinaryTree(){
		this->destroy(this->root); 
	}
	
	void insert(T);
	bool isFound(T);
	void remove(T);
	void printInOrder() const{
		printInOrder(this->root); 
	}
	
	void printPostOrder() const{ 
		printPostOrder(this->root);
	}
	
	void printPreOrder()const{
		printPreOrder(this->root);
	}
};

template <class T>
void BinaryTree<T>::insertNode(Node& newNode){
	Node** p = &this->root;
	
	while (*p) {
		if ((*p)->val > newNode.val) {
			p = &((*p)->left);
		} else {
			p = &((*p)->right);
		}
	}
	*p =&newNode;
}

template<class T>
void BinaryTree<T>::destroy(Node* root){
	if(root){ 
		destroy(root->left); 
		destroy(root->right); 
		delete root;
	} 
}


template<class T>
void BinaryTree<T>::findDeleteNode(T value,Node*& subRoot){
	if(!subRoot){
		// the subRoot points to null, return 
		return;
	} else if(value < subRoot->val){
		// Search in the left subtree 
		findDeleteNode(value,subRoot->left);
	} else if(value > subRoot->val){
		// Search in the right subtree 
		findDeleteNode(value,subRoot->right);
	} else {
		deleteNode(subRoot);
	} 
}

template<class T>
void BinaryTree<T>::deleteNode(Node*& node){ 
	
	Node* temp= nullptr;
	
	if( !(node->right) ){
		// There is no right subtree,
		temp = node;
		node = node->left;
		delete temp;
	} else if ( !(node->left) ){
		// There is no left subtree,
		temp = node;
		node = node->right;
		delete temp; 
	} else {
		temp = node->left;
		while(temp->right){
			temp = temp->right;
		}
		
		temp->right = node->right;
		temp = node;
		node = node->left;
		delete temp; 
	}
}

template<class T>
void BinaryTree<T>::printInOrder(Node* subRoot) const{ 
	if(subRoot){
		printInOrder(subRoot->left);
		cout << subRoot->val << endl;
		printInOrder(subRoot->right);
	}
}

template<class T>
void BinaryTree<T>::printPreOrder(Node* subRoot) const{ 
	if(subRoot){
		// Firstly, display the current value
		cout<<subRoot->val<<endl;
		// Then, display the smaller part of the left subtree
		printPreOrder(subRoot->left);
		// Finally, display the bigger part of the right subtree
		printPreOrder(subRoot->right);
	}
}

template<class T>
void BinaryTree<T>::printPostOrder(Node* subRoot) const{ 
	if(subRoot){
		// Firstly, display the smaller part of the left subtree
		printPostOrder(subRoot->left);
		// Then, display the bigger part of the right subtree
		printPostOrder(subRoot->right);
		// Finally, display the current value
		cout << subRoot->val << endl;
	}
}

template<class T>
void BinaryTree<T>::insert(T value){
	Node* newNode = new Node;
	newNode->val = value;
	newNode->left = newNode->right = nullptr;
	insertNode(*newNode);
}

template<class T>
bool BinaryTree<T>::isFound(T value){
	Node* node = this->root;
	while(node){
		if(node->val == value){
			return true;
		} else if(node->val > value){
			// The value is smaller, go to the left
			node = node->left; } else {
				// Otherwise, go to the right
				node = node->right;
			}
	}
	// If  null, not found, return false
	return false; 
}

template<class T>
void BinaryTree<T>::remove(T value){ 
	findDeleteNode(value,this->root);
}

template <class T>
int BinaryTree<T>::nodeCounter(Node *node){
	if (node == NULL) {
		return 0;
	} else {
		return (1 + nodeCounter((node->left) + nodeCounter(node->right)));
	}
}

template <class T>
int BinaryTree<T>:: leaftCounter(Node *node){
	if (node == NULL) {
		return 0;
	} else if (node->left == NULL && node->righ == NULL) {
		return 1;
	} else {
		return (leaftCounter(node->left) + leaftCounter(node->right));
	}
}

#endif