#include <iostream>
#include "BaseLinkedListType.h"

using namespace std;


/*
	Exercise 1: Print the linked list in reverse order
*/
	
template <class Type>
void printReverse(nodeType<Type> *node){
	if(node == NULL){
		return;
	}
	
	printReverse(node->next);
	cout << node->data;
}

/*
	Exercise 2: Merge two srted linked list

	list 1: 3 -> 5 -> 7 -> 9 -> null
	list 2: 2 -> 4 -> 6 -> null
	l1 = 3
	l2 = 2
	2 3 4 5 6 
	Expected answer: 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 9 -> null
*/
	
	
template<class Type>
nodeType<Type> *mergeList(nodeType<Type> *l1, nodeType<Type> *l2){
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	if (l1 -> data > l2 -> data) {
		l2 -> next = mergeList(l1, l2->next);
		return l2;
	} else {
		l1->next = mergeList(l1->next, l2);
		return l1;
	}
}

/*
	l1 - 4 -> null
	l2 - 3 -> null
	3 -> 4 -> null
	
	l1 = 4
	l2 =3
	mergeList(4,3)
*/


/*
[1] mergeList(3, 2)
	next of 2 = [2] mergeList(3, 4)
					|
					next of 3 = [3] mergeList(5, 4)
									|
									next of 4 = [4] mergeList(5, 6)
													|
													next of 5 = [5] mergeList(null, 6)
*/
													
