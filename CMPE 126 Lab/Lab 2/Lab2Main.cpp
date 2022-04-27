#include <iostream>
#define MAX_SIZE 30

using namespace std;

// function prototypes
//part one
void switchOperands(int *x, int *y);

// part two
void enterArrayData(int *arr, int num);
void outputArrayData(int *arr, int num);
void sumArray(int *arr, int num);

// part three template functions
// reverse array function
template<typename t>
t *reverseArray(t *arr, int size) {
	t * result = new t[size];
	for (int i = 0; i < size; i++) {
		result[i] = arr[size - i - 1];
	}
	return result;
}

// print array function
template<typename t>
void printArray(t *arr, int size){
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// main
int main(int argc, char *argv[]) {
	
	// part one
	int x = 9;
	int y = 10;
	
	switchOperands(&x, &y);
	
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	
	// part two
	int arr[MAX_SIZE];
	int num;
	
	int *ptr = arr;
	
	cout << "Enter array size: ";
	cin >> num;
	
	enterArrayData(arr, num);
	outputArrayData(arr, num);
	sumArray(arr, num);
	
	
	//part three
	int arr1[] = {1, 10, 20, 30, 40, 50, 99};
	int size1 = 7;
	
	cout << "The array: ";
	printArray(arr1, size1);
	cout << "The reversed array: ";
	printArray(reverseArray(arr1, size1), size1);
	
	return 0;
	
}

// part one function
void switchOperands(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

// part two function
void enterArrayData(int *arr, int num){
	cout << "Enter the elements in array: ";
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
		
	}
}

void outputArrayData(int *arr,int num){
	cout << "The elements of the array: ";
	for (int i = 0; i < num; i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

void sumArray(int *arr,int num){
	int sum = 0;
	
	cout << "The sum of the array: ";
	for (int i = 0; i < num; i++) {
		sum = sum + *(arr + i);
	}
	cout << sum << endl;
}

