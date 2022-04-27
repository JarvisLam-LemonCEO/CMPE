#ifndef H_LinkedStackType
#define H_LinkedStackType

#include <iostream>

using namespace std;

// Node definition
template <class Type>
struct nodeType {
	Type info;
	nodeType<Type> *link;	
};

template <class Type>
class linkedStackType {
public:
	const linkedStackType<Type>& operator = (const linkedStackType<Type> &);
	bool operator == (const linkedStackType<Type>&);
	void initializeStack();
	bool isFullStack() const;
	bool isEmptyStack() const;
	void push(const Type&);
	void pop();
	Type top() const;
	linkedStackType();
	linkedStackType(const linkedStackType<Type>&);
	~linkedStackType();
	
	void reverseStack(linkedStackType<Type>&);
	
private:
	nodeType<Type> *stacktop;
	void copyStack(const linkedStackType<Type>& );
	
};

template <class Type>
void linkedStackType<Type>::initializeStack(){
	nodeType<Type> *temp;
	
	while (stacktop != NULL) {
		temp = stacktop;
		stacktop = stacktop->link;
		
		delete temp;
	}
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const{
	return false;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const{
	return (stacktop == NULL);
}

template <class Type>
void linkedStackType<Type>::push(const Type& newItem) {
	
	nodeType<Type> *newNode; // pointer to creat the new node
	newNode = new nodeType<Type>; // creat the node
	newNode->info = newItem; // store new item in the node
	newNode->link = stacktop; // insert the new node nefore stack top
	stacktop = newNode; // set stack top to point to the top node
}

template <class Type>
void linkedStackType<Type>::pop(){
	nodeType<Type> *temp; // pointer to delete the node 
	if (stacktop != NULL) {
		temp = stacktop; // set temp to point to the top node
		stacktop = stacktop->link; // stack top points to the next node
		delete temp; // delete the node and memory
	} else {
		cout << endl;
		cout << "It cannot remove from the empty stack!" << endl;
	}
}

template <class Type>
Type linkedStackType<Type>::top() const{
	assert(stacktop != NULL);
	return stacktop->info;
}

template <class Type>
linkedStackType<Type>::linkedStackType(){
	stacktop = NULL;
}

template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type> &otherStack){
	stacktop = NULL;
	copyStack(otherStack);
}

template <class Type>
linkedStackType<Type>::~linkedStackType(){
	initializeStack();
}

template <class Type>
const linkedStackType<Type>&
linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack){
	if (this != &otherStack) {
		copyStack(otherStack);
	}
	
	return *this;
}

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack){
	nodeType<Type> *newNode, *current, *last;
	
	if (stacktop != NULL) {
		initializeStack();
	}
	
	if (otherStack.stacktop == NULL) {
		stacktop = NULL;
	} else {
		current = otherStack.stacktop;
		stacktop = new nodeType<Type>;
		stacktop->info = current->info;
		stacktop->link = NULL;
		last = stacktop;
		current = current->link;
		
		while (current != NULL) {
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}

template <class Type>
bool linkedStackType<Type>::operator == (const linkedStackType<Type>&otherStack){
	if ((this->stacktop == NULL) && (otherStack.stacktop == NULL)) {
		return true;
	}
	
	nodeType<Type> *temp1, *temp2;
	
	temp1 = this->stacktop;
	temp2 = otherStack.stacktop;
	
	while ((temp1 != NULL) && (temp2 != NULL)) {
		if (temp1->info != temp2->info) {
			return false;
		} else {
			temp1 = temp1->link;
			temp2 = temp2->link;
		}
	}
	
	if ((temp1 != NULL) || (temp2 != NULL)){
		return false;
	}
	
	return true;
}

template <class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type>& right){
	right.initializeStack();
	
	nodeType<Type> *temp = this->stacktop;
	while (temp != NULL) {
		right.push(temp->info);
		temp = temp->link;
	}
}

#endif