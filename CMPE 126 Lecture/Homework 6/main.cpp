#include <iostream>
#include "myQueue.h"

using namespace std;
int main(int argc, char *argv[]) {
	cout << "Program moves Nth element " << "of the queue to the front" << endl;
	
	queueType<int> queue;
	int position;
	
	queue.initializeQueue();
	queue.addQueue(5);
	queue.addQueue(11);
	queue.addQueue(34);
	queue.addQueue(67);
	queue.addQueue(43);
	queue.addQueue(55);

	
	// print the first queue
	cout << "The elements in the Queue are ";
	queue.print();
	
	// ask user to move an element's position
	cout << endl;
	cout << "Enter an position to move an element: ";
	cin >> position;
	
	// move the nth position to the front
	queue.moveNthFront(position);
	
	// print the first Queue after moving the position
	cout << "The elements in the Queue after moving the position are ";
	queue.print();
	
	return 0;
}