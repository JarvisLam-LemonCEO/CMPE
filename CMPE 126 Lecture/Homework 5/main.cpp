#include <iostream>
#include "myStack.h"

using namespace std;
int main(int argc, char *argv[]) {
	
	// create two stack objects
	stackType<int> stack1;
	stackType<int> stack2;
	
	// add number into the stack
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack1.push(4);
	stack1.push(5);
	stack1.push(6);
	stack1.push(7);
	stack1.push(8);
	stack1.push(9);
	
	stack1.reverseStack(stack2);
	
	cout << "Elements in the Stack 1: ";
	while (!stack1.isEmptyStack()) {
		cout << stack1.top() << " ";
		stack1.pop();
	}
	
	cout << endl;
	
	cout << "Elements in the Stack 2: ";
	while (!stack2.isEmptyStack()) {
		cout << stack2.top() << " ";
		stack2.pop();
	}
}