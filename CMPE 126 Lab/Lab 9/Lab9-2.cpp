#include <iostream>

using namespace std;

int recursiveBinarySearch(int left, int right, int a[], int n, int targetValue) {
	if (left <= right){
		int mid = left + (right - left) / 2;
		
		if (a[mid] == targetValue) {
			return mid;
		}else if (a[mid] > targetValue) {
			recursiveBinarySearch(left, mid-1, a, n, targetValue);
		} else {
			recursiveBinarySearch(mid+1, right, a, n, targetValue);
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = recursiveBinarySearch(0, n - 1, arr, n, x);
	
	if (result == -1){
		cout << "Element is not present in array" << result;
	} else {
		cout << "Element is present at index " << result;
	}
	return 0;
}