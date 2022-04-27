#include <iostream>

using namespace std;

// function prototype
int swapFrontBack(int array[], int size);

int main(int argc, char *argv[]) {
	int num;
	int array[100];
	int swap;
	
	cout << "Enter a number for the entry of an array: ";
	cin >> num;
	
	// for loop to Store the inputed elements to the array 
	for (int i = 0; i < num; i++){
		cout << "Enter the element: ";
		cin >> array[i]; 
	}
	
	swap = swapFrontBack(array, num);
	
	//checking if the array is empty to prevent errors
	if (swap == 0){
		cout << "Error! Array is empty.";
	} else {
		cout << "The result of swapping the first and last elements is ";
		
		for (int i = 0; i < num; i++){
			cout << array[i] << " ";
		}
	}
	
}

// The swapFrontBack function
int swapFrontBack(int array[], int size){
	int temp;
	temp = array[0]; // array[0] is the first element  
	array[0] = array[size - 1]; // array[size - 1] is the last element
	array[size - 1] = temp;
	
	return temp;
}

/*
	The output of the program

	Enter a number for the entry of an array: 4
	Enter the element: 1
	Enter the element: 3
	Enter the element: 5
	Enter the element: 8
	The result of swapping the first and last elements is 8 3 5 1 

*/