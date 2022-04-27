#ifndef H_QueueType
#define H_QueueType

#include <iostream>
#include <cassert>

using namespace std;

template <class Type>
class queueType {
public:
	const queueType<Type>& operator= (const queueType<Type> &);
	queueType(const queueType<Type>& otherQueue);
	
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue (const Type&);
	void deleteQueue();
	queueType<Type>(int queueSize = 100);
	~queueType();
	
	void moveNthFront(int n);
	void print();
	
private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	Type *list;
	
	void copyQueue(const queueType<Type>&);
};

template <class Type>
void queueType<Type>::moveNthFront(int n) {
	// checking n is valid
	if (n <= 1) {
		cout << "Invalid" << endl;
		return;
	}
	
	// store the n th element in the temp
	Type temp = *(list + n - 1); 
	
	// move the element to free the front position
	for(int i = n - 1; i >= 0; i--) {
		*(list + i ) =*(list + i - 1);
	}
	
	// copy the nth element as front element
	*list = temp;
}

template <class Type>
const queueType<Type>& queueType<Type>::operator= (const queueType<Type> &otherQueue){
	if(this != &otherQueue){
		copyQueue(otherQueue);
	}
	
	return *this;
}

template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue){
	list = NULL;
	copyQueue(otherQueue);
}

template <class Type>
void queueType<Type>::copyQueue(const queueType<Type> &otherQueue){
	// delete the present element in the queue
	delete [] list;
	
	// assign the value to the queue
	maxQueueSize = otherQueue.maxQueueSize;
	count = otherQueue.count;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;
	
	// allocate memory
	list = new Type[maxQueueSize];
	
	// copy the elements from the queue
	for (int i = 0; i < otherQueue.maxQueueSize; i++) {
		list[i] = otherQueue.list[i];
	}
}

template <class Type>
bool queueType<Type>::isEmptyQueue() const {
	return (count == 0);
}

template <class Type>
bool queueType<Type>::isFullQueue() const {
	return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>::initializeQueue() {
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template <class Type>
Type queueType<Type>::front() const {
	assert(!isEmptyQueue());
	return list[queueFront];
}

template <class Type>
Type queueType<Type>::back() const {
	assert(!isEmptyQueue());
	return list[queueRear];
}

template <class Type>
void queueType<Type>::addQueue(const Type& newElement) {
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize;
		count++;
		list[queueRear] = newElement;
	} else {
		cout << "Unable to add to a full queue" << endl;
	}
}

template <class Type>
void queueType<Type>::deleteQueue(){
	if (!isEmptyQueue()) {
		count--;
		queueFront = (queueFront + 1) % maxQueueSize;
	} else {
		cout << "unable to remove from an empty queue" << endl;
	}
}

template <class Type>
queueType<Type>::queueType(int queueSize){
	if (queueSize <= 0) {
		cout << "Creating an array of size 100" << endl;
		maxQueueSize = 100;
	} else {
		maxQueueSize = queueSize;
	}
	
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new Type[maxQueueSize];
}

template <class Type>
queueType<Type>::~queueType(){
	delete [] list;
}

template <class Type>
void queueType<Type>::print(){
	for (int i = queueFront; i < queueFront + count; i++) {
		cout << list[i] << " ";
	}
}

#endif