#include <iostream>
#include <ctime>

// define arry size is 1000
#define ARRAY_SIZE 1000


using namespace std;
int main(){
	//declare array with 1000 size
	int arr[ARRAY_SIZE];
	// initialize random function
	srand(time(0));
	
	// generate 1000 size random values
	for(int i = 0; i < ARRAY_SIZE; i++){
		arr[i] = rand() % ARRAY_SIZE + 1; // stores 1000 size values into the array
	}
	
	cout << endl;
	cout << "Elements before sorting: " << endl;
	
	// printing unsorted array
	for(int i = 0;i < ARRAY_SIZE; i++){
		cout << arr[i] << " ";
	}
	
	//sorting the array elements
	for(int i = 0; i < ARRAY_SIZE-1; i++){
		for(int j = i+1; j < ARRAY_SIZE; j++){
			
			// swapping the values
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	cout<<endl;
	cout << "Elements after sorting: " <<endl;
	
	// printing sorted array
	for(int i = 0;i < ARRAY_SIZE; i++){
		cout << arr[i] << " ";
	}
	
	
	//Binary Search
	cout << endl;
	cout << "Binary Search: "<<endl;
	int findElement;
	
	cout << "Enter Searching Element: ";
	cin >> findElement;
	
	int left = 0;
	int right = ARRAY_SIZE - 1;
	int mid = (left + right) / 2;
	int flag = false;
	int numOfComparisons = 0;
	int position;
	
	while(left <= right){
		if(arr[mid] == findElement){
			flag = true;
			position = mid+1;
			break;
		} else if(arr[mid]<findElement){
			left = mid+1;
		} else {
			right = mid-1;
		}
		numOfComparisons++; // number of comparisons increased by 1
		mid = (left + right) / 2; // middle value
	}
	
	if(flag){
		cout<<endl;
		cout << findElement << " is found at "<< position << " position" << endl;
	} else {
		cout << findElement << " is not found in the list" << endl;
	}
	
	cout << "Number of comparisons: " << numOfComparisons<<endl;
	
	//Sequential Search for sorted list
	cout << "\nSequential Search: " << endl;
	cout << "Enter Searching Element: ";
	cin >> findElement;
	
	// set numOfComparisons to zero, clean the previous value that stored in numOfComparisons
	numOfComparisons = 0;
	flag = false;
	for(int i = 0;i <ARRAY_SIZE; i++){
		if(arr[i] == findElement){
			flag = true;
			position = i+1;
			break;
		}
		numOfComparisons++; // number of comparisons increased by 1
	}
	
	if(flag){
		cout<<endl;
		cout << findElement<<" is found at "<< position << " position" << endl;
	}else{
		cout << findElement<<" is not found in the list"<< endl;
	}
	cout<<"Number of comparisons: " << numOfComparisons<<endl;
}
