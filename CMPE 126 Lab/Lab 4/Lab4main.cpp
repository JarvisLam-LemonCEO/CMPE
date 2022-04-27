#include <iostream>
//#include "extArrayListType.h"
#include "ArraybasedList.h"

using namespace std;

int main(int argc, char *argv[]) {

	
	int n = 3;
	int element, position,occurrence;
	
	ArraybasedList<int> intList(100);
	cout<<"Enter 3 elements in the list: ";
	for(int i = 0; i < n; i++){
		cin >> element;
		intList.insertEnd(element);
	}
	
	
	cout << "The list of numbers is " << endl;
	intList.print();
	cout << "Maximum element is:"<<intList.max()<<endl;
	cout << "Minimum element is:"<<intList.min()<<endl;
	
	
	cout << "Enter the position of element to remove: ";
	cin >> position;
	intList.removeAt(position);
	cout << "Display the list after Removing the element at give position: " << endl;
	intList.print();
	
	cout << "Maximum element is:"<<intList.max()<<endl;
	cout << "Minimum element is:"<<intList.min()<<endl;
	
	cout << "Enter a number to insert: ";
	cin >> element;
	intList.insert(element);
	cout << "Display the list after inserting the element: " << endl;
	intList.print();
	cout << "Maximum element is:"<<intList.max() << endl;
	cout << "Minimum element is:"<<intList.min() << endl;
	
	cout << "Enter number to delete it's all occurrence: ";
	cin >> occurrence;
	intList.removeAll(occurrence);
	cout<<"Display the list after Removing the all occurrence of "<< occurrence <<" : "<<endl;
	intList.print();
	cout << "Maximum element is:"<<intList.max()<<endl;
	cout << "Minimum element is:"<<intList.min()<<endl;
	
}