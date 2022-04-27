#ifndef H_LinkedQueueType
#define H_LinkedQueueType

#include <iostream>
#include <cassert>

using namespace std;


// create linked node structure
template <class Type>
struct queueNode{
	Type info;
	queueNode<Type> *link;
};

// linkedQueue Type template class
template <class Type>
class linkedQueueType{
public:
	const linkedQueueType<Type>& operator= (const linkedQueueType<Type>& );
	linkedQueueType(const linkedQueueType<Type>& );
	
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue (const Type&);
	void deleteQueue();
	linkedQueueType<Type>();
	~linkedQueueType();
	
private:
	queueNode<Type> *queueFront;
	queueNode<Type> *queueRear;
	int count;
	
	void copyQueue(const linkedQueueType<Type>& );

};

template <class Type>
const linkedQueueType<Type>&
linkedQueueType<Type>::operator=(const linkedQueueType<Type> &otherQueue){
	if (this != &otherQueue) {
		copyQueue(otherQueue);
	}
	
	return *this;
}

template <class Type> 
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue){
	queueFront = NULL;
	queueRear = NULL;
	
	copyQueue(otherQueue);
}

template <class Type>
void linkedQueueType<Type>::copyQueue(const linkedQueueType<Type> &otherQueue){
	// delete the current queue elements
	initializeQueue();
	
	// create temp and initialize temp pointer
	queueNode<Type> *temp;
	temp = otherQueue.queueFront;
	
	// copy the nodes from otherQueue
	while (temp != NULL) {
		// add to cureent queue
		addQueue(temp->info);
		// go to next node
		temp = temp->link;
	}
}

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const {
	return (queueFront == NULL);
}

template <class Type>
bool linkedQueueType<Type>::isFullQueue() const {
	return false;
}

template <class Type>
void linkedQueueType<Type>::initializeQueue() {
	queueNode<Type> *temp;
	
	// elements at left in the Queue
	while (queueFront != NULL) {
		// set temp to the current node
		temp = queueFront;
		// goes to next node
		queueFront = queueFront->link;
		// deallocate memory by temp
		delete temp;
	}
	
	count = 0;
	queueRear = NULL;
}

template <class Type>
Type linkedQueueType<Type>::front() const{
	assert(queueFront != NULL);
	return queueFront->info;
}

template <class Type>
Type linkedQueueType<Type>::back() const {
	assert(queueRear != NULL);
	return queueRear->info;
}

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement){
	// creat a new node object
	queueNode<Type> *newNode;
	newNode = new queueNode<Type>;
	
	// initialize the node with newElement
	newNode->info = newElement;
	newNode->link = NULL;
	
	// place the new node in the position
	if (queueFront == NULL) {
		queueFront = newNode;
	} else {
		queueRear->link = newNode;
	}
	
	// update the queue
	queueRear = newNode;
	count++;
}

template <class Type>
void linkedQueueType<Type>::deleteQueue(){
	queueNode<Type> *temp;
	
	if (!isEmptyQueue()) {
		// set temp point to first node
		temp = queueFront;
		// goes to queueFront
		queueFront = queueFront->link;
		// delete the first node
		delete temp;
		count--;
		
		// if the queue is empty
		if (queueFront == NULL) {
			queueRear = NULL; // set queueRear to NULL

		}
	} else {
		cout << "It cannot remove from empty queue!" << endl;
	}
}

template <class Type>
linkedQueueType<Type>::linkedQueueType(){
	// set front and rear to NULL
	queueFront = NULL;
	queueRear = NULL;
	count = 0;
}

template <class Type>
linkedQueueType<Type>::~linkedQueueType(){
	initializeQueue();
}

#endif