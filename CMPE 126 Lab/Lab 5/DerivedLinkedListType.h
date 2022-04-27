#ifndef DerivedLinkedListType_H
#define DerivedLinkedListType_H
#include <iostream>
#include "BaseLinkedListType.h"

template <class Type>
class DerivedLinkedListType: public linkedListType<Type>{
public:
	void deleteSmallestNode();
	void deleteAllOccurance(Type element);
	int getKthElement(int k);
	void deleteKthElement(int position);
};

#endif