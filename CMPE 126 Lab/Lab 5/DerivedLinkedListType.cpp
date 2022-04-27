#include <iostream>
#include "DerivedLinkedListType.h"
#include "BaseLinkedListType.h"


using namespace std;

// delete small node template
template<class Type>
void DerivedLinkedListType<Type>::deleteSmallestNode(){
	if (this->first == NULL) {
		return;
	}
	
	nodeType<Type> *temp = this->first;
	Type minElement = temp->data;
	
	while (temp != NULL) {
		if (temp->data > minElement) {
			minElement = temp->data;
		}
		temp = temp->next;
	}
	this->deleteNode(minElement);
}

// delte all occurances template
template<class Type>
void DerivedLinkedListType<Type>::deleteAllOccurance(Type element){
	if (this->first == NULL) {
		return;
	}
	
	nodeType<Type> *temp = this->first;
	nodeType<Type> *previous = NULL;
	
	
	while (temp != NULL) {
		if (temp->data == element) {
			if (previous == NULL) {
				this->first = temp->next;
				this->last = this ->last;
			} else {
				previous->next = temp->next;
			}
			
			nodeType<Type> *save = temp;
			temp = temp->next;
			delete save;
			this->count--;
			continue;
		}
		previous = temp;
		temp = temp->next;
	}
}

// delete kth elements template
template<class Type>
void DerivedLinkedListType<Type>::deleteKthElement(int k){
	if (this->first == NULL){
		return;
	}
	
	nodeType<Type> *random = this->first;
	
	if (k == 0){
		this->first = random->next;
		free(random);
		return;
	}
	
	for (int i=0; random!=NULL && i<k-1; i++){
		random = random->next;
	}
	
	if (random == NULL || random->next == NULL){
		return;
	}
	
	nodeType<Type> *next = random->next->next;
	free(random->next);
	random->next = next;
}


// return kth elements template
template<class Type>
int DerivedLinkedListType<Type>::getKthElement(int k) {
	if (k > this -> length()){
		cout << "It does not exist!"<< endl;
	}
	
	nodeType<Type> *random = this->first;
	int count = 0; // declaring count value to 0
	while (random != NULL){
		if (count == k){  // if we are at kth position
		return(random->data);
		}
		
		count++;   // else increment the count
		random = random->next;
	}
}