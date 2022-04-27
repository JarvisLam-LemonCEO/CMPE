#include <iostream>
#include <string>
using namespace std;

// function prototype
template <class BaseType>
int search(BaseType list[], BaseType str, int num);

int main(int argc, char *argv[]) {
	int num;
	int found;
	int list[10];
	int ser;
	char charList[10];
	char cser;
	
	cout << "Enter number integer: ";
	cin >> num;
	
	cout << "Enter elements: ";
	for (int i = 0; i < num; i++) {
		cin >> list[i];
	}
	
	cout << "Enter element searched: ";
	cin >> ser;
	
	found = search(list, ser, num);
	
	if (found > 0){
		cout << "Element found: " << found << " times" << endl;
	}else {
		cout << "Element not found" << endl;
	}
	
	cout << "Enter number of character: ";
	cin >> num;
	
	cout << "Enter elements: ";
	for(int i = 0; i < num; i++){
		cin >> charList[i];
	}
	
	cout << "Enter element searched: ";
	cin >> cser;
	
	found = search(charList,cser, num);
	if (found > 0){
		cout << "Element found: " << found << " times" << endl;
	}else {
		cout << "Element not found" << endl;
	}
}

template <class BaseType>
int search(BaseType list[], BaseType str, int num){
	bool found = false;
	int count = 0;
	
	for (int i = 0; i < num; i++){
		if (list[i] == str){
			count++;
		}
	}
	return count;
}

/*
Enter number integer: 5
Enter elements: 1 1 1 1 1 
Enter element searched: 1
Element found: 5 times
Enter number of character: 6
Enter elements: batman
Enter element searched: a
Element found: 2 times

*/