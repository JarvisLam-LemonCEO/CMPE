#include <iostream>
#include <list>
using namespace std;

/*
	1] left view of binary tree
		3,10,11,15
				3
			   / \
			10    12
			 \   /  \
			 11 13  14
					 \
			         15

*/

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node *newNode(int item){
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}


void printLeftView(struct Node *root, int level, int *maxLevel){
	
	if (root == NULL) {
		return;
	}
	

	if (*maxLevel < level) {
		cout << root->data << " ";
		*maxLevel = level;
	}
	
	printLeftView(root->left, level + 1, maxLevel);
	printLeftView(root->right, level + 1, maxLevel);
	
}

void leftView(struct Node *root){
	int maxLevel = 0;
	printLeftView(root, 1, &maxLevel);
}

/*
	2] dectect at cycle in graph
		0 -- 1----3
		|   /
		|  /
		2 /
		
		BFS 
		0
		1,2
		3
		
		
*/
		
// Graph Class
class Graph{
	// number of vertices
	int V;
	
	// pointer to an array containing adjacency lists
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	// Constrcutor
	Graph(int V);
	
	// to add an edge to graph
	void addEdge(int v, int w);
	
	// return true if there is a cycle
	bool isCyclic();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	// add w to v list
	adj[v].push_back(w);
	
	// add v to w list
	adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent){
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i){
		if (!visited[*i]){
			if (isCyclicUtil(*i, visited, v)){
				return true;
			}
		} else if (*i != parent){
			return true;
		}
	}
	return false;
}

bool Graph::isCyclic(){
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++){
		visited[i] = false;
	}
	
	for (int u = 0; u < V; u++){
		if (!visited[u]){
			if (isCyclicUtil(u, visited, -1)){ // int v, bool visited[], int parent
				return true;
			}
		}
	}
	return false;
}
	


int main(int argc, char *argv[]) {
	// 1] print left view of binary tree
	Node* root = newNode(3);
	root->left = newNode(10);
	root->right = newNode(12);
	root->left->right = newNode(11);
	root->right->left = newNode(13);
	root->right->right = newNode(14);
	root->right->left->left = newNode(15);
	
	leftView(root);
	
	cout << endl;
	
	// 2] detect cycle in graph
	Graph grapgh(4);
	grapgh.addEdge(1, 0);
	grapgh.addEdge(0, 2);
	grapgh.addEdge(2, 1);
	grapgh.addEdge(1, 3);
	grapgh.isCyclic() ? cout << "Graph contains cycle\n": cout << "Graph does not contain cycle\n";
	
	return 0;
}