#include <iostream>
#include "BinaryTree.h"
using namespace std;

// function protopypes
void menu();
int readVal();


int main(int argc, char *argv[]) {
	
	cout << "Binary Tree Program" << endl;
	cout << "-------------------------" << endl;
	
	int option = 1;
	BinaryTree<int> tree;
	
	// keep looping until you enter 0 to end the program
	while (option != 0) {
		menu();
		cout << "Your Option: ";
		cin >> option;
		cout << endl;
		
		if (option == 1) {
			cout << "Insert a value: ";
			tree.insert(readVal()); // insert the value inputed by user
			cout << "The value was inserted." << endl;
		} else if (option == 2) {
			cout<<"Search a value: ";
			if(tree.isFound(readVal())){ // call the isFound to search a value
				cout<<"The value is found,\n"; 
			} else {
				cout<<"The value is not found." << endl;
			}
		} else if(option == 3){
			cout<<"Remove a value: ";
			tree.remove(readVal());
			cout<<"The value is removed" <<endl;
		} else if(option == 4){
			cout<<"Printing the values in order" << endl;
			tree.printInOrder();
		} else if(option == 5){
			cout<<"Printing the values in pre-order" << endl;
			tree.printPreOrder();
		} else if (option == 6){
			cout<<"Printing the values in post-order" << endl; 
			tree.printPostOrder();
		}
	}
	
	return 0;
	
}

void menu() {
	cout<<"1. Insert a value." << endl;
	cout<<"2. Search for a value." << endl;
	cout<<"3. Remove a value." << endl;
	cout<<"4. Display the values in order." << endl;
	cout<<"5. Display the values in pre-order." << endl;
	cout<<"6. Display the values in post-order." << endl;
	cout<<"0. End the program" << endl;
}

int readVal(){
	int Val;
	cin >> Val;
	return Val;
}