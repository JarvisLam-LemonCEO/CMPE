#include <iostream>
#include "stackADT.h"
using namespace std;

template <class Type>
class stackType: public stackADT<Type> {
public:
	const stackType<Type>& operator=(const stackType<Type>&); //Overload the assignment operator.
	void initializeStack();
	//Function to initialize the stack to an empty state. //Postcondition: stackTop = 0;
	bool isEmptyStack() const;
	//Function to determine whether the stack is empty. //Postcondition: Returns true if the stack is empty, // otherwise returns false.
	bool isFullStack() const;
	//Function to determine whether the stack is full. //Postcondition: Returns true if the stack is full, // otherwise returns false.
	void push(const Type& newItem);
	//Function to add newItem to the stack. //Precondition: The stack exists and is not full. //Postcondition: The stack is changed and newItem is // added to the top of the stack.
	Type top() const;
	//Function to return the top element of the stack. //Precondition: The stack exists and is not empty. //Postcondition: If the stack is empty, the program
	// terminates; otherwise, the top element of the stack
	//    is returned.
	void pop();
	//Function to remove the top element of the stack. //Precondition: The stack exists and is not empty. //Postcondition: The stack is changed and the top element is
	//    removed from the stack.
	stackType(int stackSize = 100);
	//Constructor
	//Create an array of the size stackSize to hold
	//the stack elements. The default stack size is //Postcondition: The variable list contains the
	// of the array, stackTop = 0, and maxStackSize = stackSize
	stackType(const stackType<Type>& otherStack); //Copy constructor
	~stackType();
	//Destructor
	//Remove all the elements from the stack.
	//Postcondition: The array
	//    elements is deleted.
	
	void reverseStack(stackType<Type> &otherStack); 
private:
	int maxStackSize; //variable to store the maximum stack ssize
	int stackTop;     //variable to point to the top of the stack
	Type *list; //pointer to the array that holds the stack elements
	
	void copyStack(const stackType<Type>& otherStack);
	//Function to make a copy of otherStack.
	//Postcondition: A copy of otherStack is created and assigned // to this stack.
};

template <class Type>
void stackType<Type>::reverseStack(stackType<Type>& otherStack) {
	
	otherStack.initializeStack(); // destory the old contents of otherStack
	
	// add the elements of this stack to another Stack in reverse order
	for (int i = stackTop - 1; i > 0; i--) {
		otherStack.push(list[i]);
	}
}

template <class Type>
void stackType<Type>::initializeStack() {
	stackTop = 0; 
}//end initializeStack

template <class Type>
bool stackType<Type>::isEmptyStack() const {
	return(stackTop == 0); 
}//end isEmptyStack

template <class Type>
bool stackType<Type>::isFullStack() const {
	return(stackTop == maxStackSize); 
} //end isFullStack

template <class Type>
void stackType<Type>::push(const Type& newItem) {
	if (!isFullStack())
		{
			list[stackTop] = newItem; //add newItem at the top
			stackTop++; //increment stackTop
		} else {
			cout << "Cannot add to a full stack." << endl;
		}
}//end push

template <class Type>
Type stackType<Type>::top() const {
	assert(stackTop != 0); //if stack is empty, terminate the program
	return list[stackTop - 1]; //return the element of the stack indicated by stackTop - 1
}//end top


template <class Type>
void stackType<Type>::pop() {
	if (!isEmptyStack()){
		stackTop--;     //decrement stackTop
	} else {
		cout << "Cannot remove from an empty stack." << endl;
	}
}//end pop

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
	delete [] list;
	maxStackSize = otherStack.maxStackSize; stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];
	//copy otherStack into this stack
	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j]; 
} //end copyStack

template <class Type> stackType<Type>::stackType(int stackSize) {
	if (stackSize <= 0) {
		cout << "Size of the array to hold the stack must be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxStackSize = 100;
	} else {
		maxStackSize = stackSize;
	}
	
	stackTop = 0;
	list = new Type[maxStackSize];
}

template <class Type> stackType<Type>::~stackType() //destructor
{
	delete [] list; //deallocate the memory occupied
}

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack) {
	list = NULL;
	copyStack(otherStack);
}//end copy constructor

template <class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack) {
	if (this != &otherStack){ //avoid self-copy 
		copyStack(otherStack);
	} 
	
	return *this;
	
}