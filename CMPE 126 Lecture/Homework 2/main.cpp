#include <iostream>
#include "Car.h"
#include "arrayListType.h"

using namespace std;
int main(int argc, char *argv[]) {
	
	// test car class
	// create list1
	arrayListType<Car> list1;
	
	// create car object
	Car car1("Lamborghini", 2022, 12000000);
	Car car2("Tesla", 2021, 123400);
	
	// add car1 and car2 to the list
	list1.insert(car1);
	list1.insert(car2);
	
	cout << "list1 contains two cars" << endl;
	cout << "The length of List1 " << list1.listSize() << endl;
	
	cout << "Add a new car at index 1\n";
	
	// create a new car object
	Car car3("McLaren", 2021, 2000000);
	// add car3 to index 1
	list1.insertAt(1, car3);
	
	list1.print();
	
	// removing car in index2 of the list
	cout << "\nRemoving car from index 2\n";
	list1.removeAt(2);
	list1.print();
	
	
	cout << "\nTesing numbers in list2\n";
	// create list2
	arrayListType<int> list2;
	
	list2.insert(2);
	list2.insert(6);
	list2.insert(90);
	list2.insert(35);
	list2.insert(100);
	
	cout << "list2: ";
	list2.print();
	
	// find the size of the list 2
	cout << "list2 size: " << list2.listSize() << endl;
	
	// search 10th index
	cout << "\nSearching index of 10: " << list2.seqSearch(10) << endl;
	
	// add a number to specific index
	cout << "\naddinging 20 at index -5: ";
	list2.insertAt(-5, 20);
	
	cout << "\nAdding 14 at end: ";
	list2.insertEnd(14);
	list2.print();
	
	// remove numbers from specific index
	cout << "\nRemoving int at index -3: ";
	list2.removeAt(-3);
	
	cout << "\nRemoving int at index 1: ";
	list2.removeAt(1);
	list2.print();  
	
	int a;
	cout << "\nRetrieving item at index 2: ";
	list2.retrieveAt(2, a);
	cout << a << endl;
	
	
	cout << "\nRetrieving item at index -2: ";
	list2.retrieveAt(-2, a);
	
	// test list 3
	cout << "\nTest List3 with string inside\n";
	// create list3
	arrayListType<string> list3;
	
	list3.insert("Amazon");
	list3.insert("Apple");
	list3.insert("Google");
	list3.insert("Meta");
	list3.insert("Microsoft");
	
	// print the list 3
	cout << "list3: ";
	list3.print();
	
	// replacing specific index
	cout << "\nReplacing item at index -1 with Tesla: ";
	list3.replaceAt(-1, "Tesla");
	
	cout << "\nReplacing item at index 0 with Alibaba: ";
	list3.replaceAt(0, "Alibaba");
	list3.print();
	
	// searching Apple in the list3
	cout << "\nSearching Apple index in list3: " << list3.seqSearch("Apple") << endl;
	
	// show the size of list3
	cout << "\nList3 size: " << list3.listSize() << endl;
	cout << "Is list3 full: " << boolalpha << list3.isFull() <<endl;
	
	// making the list3 empty
	cout << "\n Empty the list 3" << endl;
	list3.clearList();
	
	// check the list is empty
	cout << "\nList3 empty? " << boolalpha << list3.isEmpty() << endl;
	
	cout << "Remove something from empty list3: ";
	list3.remove("Amazon");
	
}