#include<iostream>
#include "Car.h"
#include"arrayListType.h"
using namespace std;


int main(int argc, const char * argv[]) 
{  
    //testing with car class, int and string
    arrayListType<Car> list1;

    Car car1 {"Subaru", 2000, 4500};
    Car car2{"Honda", 2018, 17000};

    list1.insert(car1);
    list1.insert(car2);
    
    cout << "list1 contains two cars  Car car1 {Subaru, 2000, 4500}; Car car2{Honda, 2018, 17000}" << endl;
    cout << "Length of list1 " << list1.listSize() << endl;
    
    cout << "Inserting new car at index 1\n";

    Car car3{"Aspire", 2021, 32000};
    list1.insertAt(1, car3);

    list1.print();

    cout << "\nRemoving car from index 2\n";
    list1.removeAt(2);
    list1.print();


    cout << "\nTesting list2 of integers\n";
    arrayListType<int> list2;

    list2.insert(10);
    list2.insert(11);
    list2.insert(12);
    list2.insert(13);
    list2.insert(14);

    cout << "list2 intially: ";
    list2.print();

    cout << "list2 size: " << list2.listSize() << endl;
    
    cout << "\nSearching index of 12: " << list2.seqSearch(12) << endl;

    cout << "\nInserting 15 at index -2: ";
    list2.insertAt(-2, 15);

    cout << "\nInserting 15 at end: ";
    list2.insertEnd(15);
    list2.print();

    cout << "\nRemoving int at index -1: ";
    list2.removeAt(-1);

    cout << "\nRemoving int at index 1: ";
    list2.removeAt(1);
    list2.print();  
    
    int a;
    cout << "\nRetrieving item at index 2: ";
    list2.retrieveAt(2, a);
    cout << a << endl;


    cout << "\nRetrieving item at index -2: ";
    list2.retrieveAt(-2, a);


    cout << "\nTesting list3 of strings\n";
    arrayListType<string> list3;

    list3.insert("Subaka");
    list3.insert("Ava");
    list3.insert("Sophia");
    list3.insert("Amelia");

    cout << "list3 intially: ";
    list3.print();


    cout << "\nReplacing item at index -1 with Isabella: ";
    list3.replaceAt(-1, "Isabella");

    cout << "\nReplacing item at index 0 with Isabella: ";
    list3.replaceAt(0, "Isabella");
    list3.print();

    cout << "\nSearching Mia index in list3: " << list3.seqSearch("Mia") << endl;

    cout << "Searching Sophia index in list3: " << list3.seqSearch("Sophia") << endl;

    cout << "\nList3 size: " << list3.listSize() << endl;
    cout << "Is list3 full: " << boolalpha << list3.isFull() <<endl;

    cout << "\nMaking list3 empty" << endl;
    list3.clearList();

    cout << "\nIs list3 empty: " << boolalpha << list3.isEmpty() << endl;

    cout << "Trying to remove from empty list3: ";
    list3.remove("Sophia");
}