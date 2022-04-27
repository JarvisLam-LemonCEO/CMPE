#include <iostream>
#include <vector>


using namespace std;

template<class T>
class Set{
public:
	
	// function to add new set item 
	int addItem(T item);
	// function to remove item from the set */
	int removeItem(T item);
	// returns number of items in the set */
	int numItems();
	// returns true, if given item is in set */
	bool IsMember(T item);
	// returns array of elements includes all set elements */
	T* getArrayOfSetItems();

private:
	
	//vector store set elements
	vector<T> mElems;
};

class A{
	A *a;
	public:
		A(){
			a = this;
		}
	
	bool operator==(const A &obj){
		if (&obj == a){
			return true;
		}
		return false;
	}
	
	bool operator!=(const A &obj){
		if (&obj != a){
			return true;
		}
		return false;
	}
};


int main(){
	
	// declare a object
	A a;
	A b;
	
	Set<int> set1; 
	Set<A> set2;
	
	// Adding objects to set
	set2.addItem(a);
	set2.addItem(b);
	
	// Adding items
	set1.addItem(5);
	set1.addItem(6);
	set1.addItem(1);
	set1.addItem(1);
	set1.addItem(10);
	set1.addItem(12);
	
	// Remove items
	set1.removeItem(6);
	
	// Checking members whether members of set or not
	set1.IsMember(6);
	set1.IsMember(5);
	
	// Getting array of set elements
	int * array = set1.getArrayOfSetItems();
	
	// returning array
	delete array;
	return 0;
	
}


template<class T>
int Set<T>::addItem(T item){
	
	if (find(mElems.begin(), mElems.end(), item) == mElems.end()){
		cout << "Item is added to set.\n";
		mElems.push_back(item);
		return 0;
	}
	cout << "Item is already exists.\n";
	return -1;
}

template<class T>
int Set<T>::removeItem(T item){
	if (find(mElems.begin(), mElems.end(), item) != mElems.end()){
		cout << "Item is removed from set.\n";
		mElems.erase(remove(mElems.begin(), mElems.end(), item), mElems.end());
		return 0;
	}
	cout << "Item is not found in set.\n";
	return -1;
}

template<class T>
int Set<T>::numItems(){
	return mElems.size();
}

template<class T>
bool Set<T>::IsMember(T item){
	if (find(mElems.begin(), mElems.end(), item) != mElems.end()){
		cout << "Given item is member of set.\n";
		return true;
	}
	cout << "Given item is not a member of set.\n";
	return false;
}

template<class T>
T * Set<T>::getArrayOfSetItems(){
	T *array = new T[mElems.size()];
	for (int i=0; i<mElems.size(); ++i){
		array[i] = mElems[i];
	}
	return array;
}