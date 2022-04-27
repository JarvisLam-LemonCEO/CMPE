//
//  ArraybasedList.hpp
//  Lab4
//
//  Created by Vishwa Shah on 9/21/21.
//

#ifndef ArraybasedList_hpp
#define ArraybasedList_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

template <class Type>
class ArraybasedList{
public:
    const ArraybasedList<Type>& operator=(const ArraybasedList<Type>&);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print();
    bool isItemAtEqual(int, const Type&) const;
    void insertAt(int, const Type&);
    void insertEnd(const Type&);
    virtual void removeAt(int);
    void retrieveAt(int, Type&) const;
    void replaceAt(int, const Type&);
    void clearList();
    int seqSearch(const Type&) const;
    void insert(const Type&);
    void remove(const Type&);
    void removeAll(const Type& item);
    ArraybasedList(int);
    ArraybasedList(const ArraybasedList<Type>&);
    
    ~ArraybasedList();
    int min() const;
    int max() const;
    void removeshift(int location);
    
protected:
    Type * list;
    int length;
    int maxSize;
};


template<class T>
ArraybasedList<T>::~ArraybasedList(){
    delete[] list;
}
//print(): prints array in simple format
//Arguments: none | Returns: void
template <class Type>
void ArraybasedList<Type>::print()
{
    int count = 1;
    for (int i = 0; i < length; i++)
    {
        cout << setw(5) << list[i] << " ";
        if (count++ % 10 == 0) cout << endl;
    }
    cout << endl;
}

//insertAt(): inserts an item at a given location
//Arguments: location (int), insertItem (const Type&) | Returns: void
template <class Type>
void ArraybasedList<Type>::insertAt
                  (int location, const Type& insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
             << "is out of range" << endl;
    else
        if (length >= maxSize)  //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                 list[i] = list[i - 1];   //move the elements down
            list[location] = insertItem;  //insert item at position
            length++;
    }
} //end insertAt

//insertEnd(): inserts given item at end of list
//Arguments: insertItem(const Type&) | Returns: void
template <class Type>
void ArraybasedList<Type>::insertEnd(const Type& insertItem)
{

    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
         list[length] = insertItem; //insert the item at the end
         length++;
    }
} //end insertEnd

//removeAt(): removes list element by location
//Arguments: location (int) | Returns: void
template <class Type>
void ArraybasedList<Type>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
             << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];
        length--;
    }
} //end removeAt

//retrieveAt(): retrieves a list item by location
//Arguments: location (int), retItem (Type&) | Returns: void
//retItem is sent by reference and is set to the list item
//retrieved by location
template <class Type>
void ArraybasedList<Type>::retrieveAt
                             (int location, Type& retItem) const
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
             << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt

//replaceAt(): replaces a list item by location
//Arguments: location (int), repItem (const Type&) | Returns: void
template <class Type>
void ArraybasedList<Type>::replaceAt
                          (int location, const Type& repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
             << "out of range." << endl;
    else
        list[location] = repItem;

} //end replaceAt

//seqSearch(): searches the list for a target item
//Arguments: item (const Type&) | Returns: either -1 (item not
//found) or the location (int) (item found)
template <class Type>
int ArraybasedList<Type>::seqSearch(const Type& item) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

//insert(): inserts an item into the list
//Arguments: insertItem (const Type&) | Returns: void
//This function ensures only unique items are inserted into the
//list; duplicates are not entered and a cerr message is generated
template <class Type>
void ArraybasedList<Type>::insert(const Type& insertItem)
{
    int loc;
    
    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and
                                //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);
        if (loc == -1)    //the item to be inserted does not exist
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
                 << "the list. No duplicates are allowed." << endl;
    }
} //end insert

//remove(): removes an item from the list
//Arguments: removeItem (const Type&) | Returns: void
//This function only removes the first instance of the item
//(in the event duplicates were somehow inserted into the list
template<class Type>
void ArraybasedList<Type>::remove(const Type& removeItem)
{
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

//arrayListType(): constructor
//Arguments: array size (int)
template <class Type>
ArraybasedList<Type>::ArraybasedList(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
             << "an array of size 100. " << endl;
        maxSize = 100;
    }
    else
        maxSize = size;
    length = 0;
    list = new Type[maxSize];
} // end constructor

//arrayListType(): copy constructor
//Arguments: otherList (const arrayListType<Type>&)
template <class Type>
ArraybasedList<Type>::ArraybasedList
                   (const ArraybasedList<Type>& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new Type[maxSize]; //create the array
    for (int j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
} //end copy constructor

//operator=(): overloads assignment operator
//Arguments: otherList (const arrayListType<Type>&)
//Returns: *this
template<class Type>
const ArraybasedList<Type>& ArraybasedList<Type>::operator=(const ArraybasedList<Type>& otherList)
{
    if (this != &otherList)   //avoid self-assignment
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new Type[maxSize];  //create the array
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i];
    }
    return *this;
}


//implementation of max
template <class Type>
int ArraybasedList<Type>::max() const{
    int max = list[0];
    for (int i = 0; i < length; i++)
        {
            if(max < list[i]){
                max = list[i];
            }
        }
    return max;
}

//implementation of min
template <class Type>
int ArraybasedList<Type>::min() const
{
    int min = list[0];
    for (int i = 0; i < length; i++){
            if(min > list[i]){
                min = list[i];
            }
        }
    return min;
}

// removeAll
template <class Type>
void ArraybasedList<Type>::removeAll(const Type& item)
{
    int index;
    while((index = seqSearch(item)) != -1)
        {
            removeAt(index);
        }
}

#endif /* ArraybasedList_hpp */
