#include <iostream>
#include "myStack.h"

using namespace std;
int main(int argc, char *argv[]) {
	cout << "Program to reverse a stack onto another." << endl;
	
	linkedStackType<int> stack1;
	linkedStackType<int> stack2;
	
	cout << "Inserting elements 5, 10, 15 . . ." << endl;
	
	for (int i = 5; i < 50; i+=5) {
		stack1.push(i);
	}
	
	stack2 = stack1;
	
	if (stack1 == stack2) {
		cout << "The two stacks are equal" << endl;
	} else {
		cout << "The two stacks are unequal" << endl;
	}
	
	cout << "Reversing the stack onto another stack" << endl;
	stack1.reverseStack(stack2);
	
	if (stack1 == stack2) {
		cout << "The two stacks are equal" << endl;
	} else {
		cout << "The two stacks are unequal" << endl;
	}
	
	cout << "The elements in the first stack are: ";
	while (!stack1.isEmptyStack()) {
		cout << stack1.top();
	}
	
	cout << "The elements in the second stack are: ";
	while (!stack2.isEmptyStack()) {
		cout << stack2.pop() << " ";
		stack2.pop();
	}
	
	cout << endl;
	
}