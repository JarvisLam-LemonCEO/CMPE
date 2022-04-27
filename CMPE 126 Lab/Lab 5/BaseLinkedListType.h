//
//  BaseLinkedListType.hpp
//  DemoLinkedList
//
//  Created by Vishwa Shah on 3/7/22.
//

#ifndef BaseLinkedListType_H
#define BaseLinkedListType_H

#include <stdio.h>
//#include "LinkedListInterator.hpp"

template <class Type>
class nodeType{
public:
    Type data;
    nodeType* next;
};

template <class Type>
class linkedListType
{
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    void initializeList(); //Postcondition: first = NULL, last = NULL, count = 0;
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destroyList();
    Type front() const;
    Type back() const;
    bool search(const Type& searchItem) const;
    void insertFirst(const Type& newItem);
    void insertLast(const Type& newItem);
    void deleteNode(const Type& deleteItem);
    void reverseList();
    
    // delete all occurances
    virtual void deleteAllOccurance(int element) = 0;
    
    // delete all kth element
    void deleteKthElement(int k);
    
    linkedListType();
    linkedListType(const linkedListType<Type>& otherList);
    ~linkedListType();
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
private:
void copyList(const linkedListType<Type>& otherList);
};

#endif /* BaseLinkedListType_hpp */
