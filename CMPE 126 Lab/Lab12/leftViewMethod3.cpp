#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to
// create a new Binary Tree Node
struct Node *newNode(int item){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}



vector<int> leftView(Node *root){
	// Your code here
	vector<int>ans;
	if(!root){
		return ans;
	}
	
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	bool ok=true;
	while(!q.empty()){
		auto it=q.front();
		q.pop();
		if(it==NULL){
			if(ok==false){
				ok=true;
			}
			if(q.size()==0){
				break;
			} else {
				q.push(NULL);
			}
		} else { 
			if(ok){
				ans.push_back(it->data);
				ok=false;
			}
		
			if(it->left){
				q.push(it->left);
			}
			
			if(it->right){
				q.push(it->right);
			}
		}
	}
	return ans;
}

int main(){
	Node* root = newNode(3);
	root->left = newNode(10);
	root->right = newNode(12);
	root->left->right = newNode(11);
	root->right->left = newNode(13);
	root->right->right = newNode(14);
	root->right->left->left = newNode(15);

	
	vector<int> vec = leftView(root);
		for(int x : vec)
		cout<<x<<" ";
		cout << endl;

	return 0;
}
