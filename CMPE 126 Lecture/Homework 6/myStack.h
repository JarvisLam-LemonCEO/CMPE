#ifndef H_LinkedStackType
#define H_LinkedStackType
#include <iostream>

using namespace std;

template <class Type>
struct stackNote{
	Type info;
	stackNote<Type> *link;
};

template <class Type>
class linkedStackType{
public:
	const linkedStackType<Type>& operator= (const linkedStackType<Type> &);
	void initializeStack();
	bool isFullStack() const;
	bool isEmptyStack() const;
	void push(const Type&);
	void pop();
	Type top() const;
	linkedStackType();
	linkedStackType(const linkedStackType<Type> &);
	~linkedStackType();
	
private:
	stackNote<Type> *stackTop;
	void copyStack(const linkedStackType<Type>& );
};

template <class Type>
void linkedStackType<Type>::initializeStack(){
	// pointer to delete the node
	stackNote<Type> *temp;
	
	while (stackTop != NULL) {
		// set temp to point to the current node
		temp = stackTop;
		
		// stackTop to the next node
		stackTop = stackTop->link;
		
		// deallocate memory
		delete temp;
	}
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const{
	return false;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const{
	return (stackTop == NULL);
}

template <class Type>
void linkedStackType<Type>::push(const Type& newItem){
	// create a new node
	stackNote<Type> *newNode;
	
	// create nodes
	newNode = new stackNote<Type>;
	
	// store newItem in the node
	newNode->info = newItem;
	
	// insert the newNode before stackTop
	newNode->link = stackTop;
	
	// set stacktop tp point to the top node
	stackTop = newNode;
}

template <class Type>
void linkedStackType<Type>::pop(){
	// pointer to delet the node
	stackNote<Type> *temp;
	
	if (stackTop != NULL) {
		// set temp to point to the top node
		temp = stackTop;
		
		// stackTop to the next node
		stackTop  = stackTop->link;
		
		// delete the node and deallocate memory
		delete temp;
	} else {
		cout << "It cannot remove from an empty stack" << endl;
	}
}

template <class Type>
Type linkedStackType<Type>::top() const {
	assert(stackTop != NULL);
	
	// return to the top element value
	return stackTop->info;
}

template <class Type>
linkedStackType<Type>::linkedStackType(){
	stackTop = NULL;
}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack){
	stackTop = NULL;
	copyStack(otherStack);
}

template <class Type>
linkedStackType<Type>::~linkedStackType(){
	initializeStack();
}

template <class Type>
const linkedStackType<Type>&
linkedStackType<Type>::operator= (const linkedStackType<Type>& otherStack){
	// skip self-copy
	if (this != &otherStack) {
		copyStack(otherStack);
	}
	
	return *this;
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack){
	stackNote<Type> *newNode, *current, *last;
	
	// if the stack is not empty, then make it empty
	if (stackTop != NULL) {
		initializeStack();
	}
	
	if (otherStack.stackTop == NULL) {
		stackTop = NULL;
	} else {
		// set current to point to the stack to be copied
		current = otherStack.stackTop;
		
		// create the node
		stackTop = new stackNote<Type>;
		
		stackTop->info = current->info;
		
		// set the link to null
		stackTop->link = NULL;
		
		// set the last to point to the node
		last = stackTop;
		
		// set currrent to point to the next node
		current = current->link;
		
		// copy the remainng stack
		while (current != NULL) {
			newNode = new stackNote<Type>;
			
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
	
}

#endif