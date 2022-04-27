#include <iostream>
#include "ArraybasedList.h"


// derived function
template <class Type> class extArrayListType : ArraybasedList<Type> {
public:
	void removeAt(int a[], int aSize);
	
	void removeAll(const Type& removeItem);
	
	
	int max(int a[], int aSize) const;
	
	int min(int a[], int aSize) const;
	
};

template <class Type>
void extArrayListType<Type>::removeAt(int a[], int aSize){
	if (a[0] < 0 || a[0] >= aSize){
		cerr << "The location of the item to be removed "
		<< "is out of range" << endl;
	} else {
		for (int i = a[i]; i < aSize - 1; i++)
			a[i] = a[i+1];
		aSize--;
	}
}

template <class Type>
int extArrayListType<Type>::max(int a[], int aSize) const{
	int max = a[0];
	
	for (int i = 0; i < aSize; i++){
		if(max < a[i]){
			max = a[i];
		}
	}
	return max;
}

//implementation of min
template <class Type>
int extArrayListType<Type>::min(int a[], int aSize) const{
	int min = a[0];
	
	for (int i = 0; i < aSize; i++){
		if(min > a[i]){
			min = a[i];
		}
	}
	return min;
}

template <class Type>
void extArrayListType<Type>::removeAll(const Type& item)
{
	int index;
	while((index = seqSearch(item)) != -1)
		{
			removeAt(index);
		}
}