#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int arr[10];
	int largest, secondLargest;
	
	// using for loop to store 10 elements into arr[10]
	for(int i = 0; i < 10; i++){
		cout << "Enter a number: ";
		cin >> arr[i];
	}
	
	//comparing the first two elements of the array
	if(arr[0] < arr[1]){ // if the 1st element is smaller than the 2nd element
		largest = arr[1]; // then the 2nd element will store index 1
		secondLargest = arr[0]; //then the 1st element will store index 0
	} else {			// if the 1st element is larger than the 2nd element
		largest = arr[0]; //then the 1st element will store index 0
		secondLargest = arr[1]; //then the 2nd element will store index 1
	}
	
	for(int i = 2; i < 10; i++){ // if the value of the current array is larger than the value of "largest" 
		if(arr[i] > largest){
			secondLargest = largest; // The value "largest" is copied to the "secondLargest" variable
			largest = arr[i]; // the value of the current array will become the largest number
		} else if(arr[i] > secondLargest && arr[i] != largest){ // if the value of the current array is larger than secondLargest and less than "largest"
			secondLargest = arr[i]; // then the value of the current array is copied to the "secondLargest" variable
		}
	}
	cout << "The second largest number is " << secondLargest;
}