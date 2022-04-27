#include <iostream>
#include <vector>
using namespace std;

// function prototype
void slectionSort(vector<int> &arrayList);
void fillArray(vector<int> &arrayList);


int main(int argc, char *argv[]) {
	// declare vector variable
	vector<int> arrayList;
	
	// call fill vector
	fillArray(arrayList);
	// call slection sort function
	slectionSort(arrayList);
	
	// print the result on screen 
	cout << "After sorting: " << endl;
	for (int i = 0; i < arrayList.size(); i++){
		cout << arrayList[i] << endl;
	}
}

// fill array function 
void fillArray(vector<int> &arrayList){
	int num;
	
	cout << "Enter elements (-1 to exit): ";
	cin >> num;
	
	while(num != -1){
		arrayList.push_back(num);
		cin >> num;
	}
}

void slectionSort(vector<int> &arrayList){
	for (int i = 0; i < arrayList.size() - 1; i++){
		for (int j = 0; j < arrayList.size(); j++){
			if(arrayList[i] > arrayList[j]){
				int temp;
				
				temp = arrayList[i];
				arrayList[i] = arrayList[j];
				arrayList[j] = temp;
			}
		}
	}
}

/*
Enter elements (-1 to exit): 20 4 60 203 -1
After sorting: 
60
20
4
203


*/