#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

// Binary Tree

struct binaryTree{
	int data;
	binaryTree *left;
	binaryTree *right;
};

void levelOrderTraversal(binaryTree * root){
	queue<binaryTree*> q;
	
	q.push(root);
	
	while (!q.empty()) {
		int length = q.size();
		
		for (int i = 1; i <= length; i++) {
			binaryTree * node = q.front();
			cout << node->data << endl;
			q.pop();
			if (node->left != NULL) {
				q.push(node->left);
			}
			
			if (node->right!= NULL) {
				q.push(node->right);
			}
		}
	}
}

/*
	Print or return the list of all the nodes distance K from root
*/
	
vector<int> kDistance(binaryTree * root, int k){
	queue<binaryTree*> q;
	vector<int> answer;
	int distance = -1;
	
	q.push(root);
	
	while (!q.empty()) {
		int length = q.size();
		distance++;
		
		for (int i = 1; i <= length; i++) {
			binaryTree * node = q.front();
			if (distance == k) {
				answer.push_back(node->data);
				cout << node->data << endl;
			}
			
			cout << node->data << endl;
			q.pop();
			
			if (node->left != NULL) {
				q.push(node->left);
			}
			
			if (node->right!= NULL) {
				q.push(node->right);
			}
		}
		
		if (distance == k) {
			break;
		} 
	}
	return answer;
}

/*
	find out the height of the binary tree
*/
	
int height(binaryTree *root){
	if (root == NULL) {
		return 0;
	}
	
	return  1 + max(height(root->left),height(root->right));
}

int main(int argc, char *argv[]) {
	
}