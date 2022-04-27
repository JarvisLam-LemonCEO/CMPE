#include <iostream>

using namespace std;

int sequentialSearch(int arr[], int left, int right, int n, int x){
	if (right < left) {
		return -1;
	}
	
	if (arr[left] == x) {
		return left;
	}
	
	return sequentialSearch(arr, left + 1, right, n, x);
}

int main(int argc, char *argv[]) {
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	int result = sequentialSearch(arr, 0, n - 1, n, x);
	
	cout << "X = 10" << endl;
	cout << "Output: " << result;
}