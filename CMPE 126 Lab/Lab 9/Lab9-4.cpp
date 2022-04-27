#include <iostream>

using namespace std;

// find peak function
int findPeak(int arr[], int n);

int main(int argc, char *argv[]) {
	int arr[] = {12, 67, 90, 100, 400, 399};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The Peak is "
	<< findPeak(arr, n);
}

// find peak function
int findPeak(int arr[], int n)
{
	// first or last element is peak element
	if (n == 1){
		return 0;
	}
	if (arr[0] >= arr[1]){
		return 0;
	}
	if (arr[n - 1] >= arr[n - 2]){
		return n - 1;
	}
	
	// check for every other element
	for (int i = 1; i < n - 1; i++) {
		
		// check if the left and right values are smaller
		if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1]){
			return i;
		}
	}
}
