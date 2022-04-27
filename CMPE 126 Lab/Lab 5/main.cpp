#include <iostream>
#include "BaseLinkedListType.cpp"
#include "DerivedLinkedListType.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
	
	// create linked list object
	DerivedLinkedListType<int> *list = new DerivedLinkedListType<int>();
	list->initializeList();
	// insert First and last nodes
	list->insertFirst(1);
	list->insertFirst(2);
	list->insertFirst(2);
	
	list->insertLast(7);
	list->insertLast(8);
	list->insertLast(300);
	
	// print the list to screen
	list->print();
	
	cout << endl;
	
	// Delete the smallest node
	cout << "Delete the Smallest Node" << endl;
	list->deleteSmallestNode();
	list->print();
	
	cout << endl;
	
	int ans;

	// Delete all occutances
	cout << "Delete All occurrence: ";
	cin >> ans;
	
	list->deleteAllOccurance(ans);
	list->print();

	cout << endl;
	
	int kth;
	
	// Return kth element
	cout << "Return element: ";
	cin >> kth;
	
	list->getKthElement(1);
	list->print();
	
	cout << endl;
	
	// Delete kth element 
	cout << "Delete Kth element: ";
	cin >> kth;
	list->deleteKthElement(kth);
	list->print();
	
	
	return 0;
}