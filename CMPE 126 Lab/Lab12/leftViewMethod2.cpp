
#include<iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node{
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// function to print left view of binary tree
void printLeftView(Node* root){
	if (!root){
		return;
	}

	queue<Node*> q;
	q.push(root);

	while (!q.empty()){	
		// number of nodes at current level
		int n = q.size();
		
		// Traverse all nodes of current level
		for(int i = 1; i <= n; i++){
			Node* temp = q.front();
			q.pop();
				
			// Print the left most element
			// at the level
			if (i == 1){
				cout<<temp->data<<" ";
			}
			
			// Add left node to queue
			if (temp->left != NULL){
				q.push(temp->left);
			}

			// Add right node to queue
			if (temp->right != NULL){
				q.push(temp->right);
			}
		}
	}
}	

// Driver code
int main(){
	Node* root = newNode(3);
	root->left = newNode(10);
	root->right = newNode(12);
	root->left->right = newNode(11);
	root->right->left = newNode(13);
	root->right->right = newNode(14);
	root->right->left->left = newNode(15);
	
	printLeftView(root);
}