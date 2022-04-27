#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
	Binary search: sorted list

	0 1 2 3 4 
	a = {45, 67, 78, 100, 256}
	targeValue: 100
	problem statement: return the position of targetValue in the list: 3
	
	left half: {45, 67, 78}
	right half: {100, 256}
	
	mid =2 
	3 4
	{100, 256}
	left = {100}
	right = {256}
	mid = 3
	
	step 1: get the mid element
	setp 2: if(mid == targetValue){
	} else if(mid > targetValue){
		look for the left part
	} else {
		look for the rihgt part
	}
*/

/*
a[] = {45, 67, 78, 100, 256}
targetVlaue = 256
left = 0
right = 4
mid = 2
left = 3
right = 4
mid = 3
a[mid] = 100
left = 4
right = 4
--------------------------------------------
a[] = {45, 67, 78, 100, 256}
targetVlaue = 13

left = 0
right = 4

mid = 2
left = 0
right = 1

mid = 0
a[mid] = 45
left = 0
right = -11

*/

int binarySearch(int a[], int n, int targetValue){
	int left = 0;
	int right = n - 1;
	
	while (left <= right) {
		//int mid = (left + right) / 2;
		
		int mid = left + (right - left) / 2;
		
		if (a[mid] == targetValue) {
			return mid;
		} else if (a[mid] > targetValue) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

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

/*
	problem statement: find the ceiling value of the given element x;

	a[] = {10, 45, 67, 78, 89, 100}
	x = 75;
	output: 78
	
	left = 0;
	right = 5;
	
	mid = 2
	a[mid] = 67
*/
	
int findCeilValue(int left, int right, int a[], int n, int x) {
	if (left <= right){
		int mid = left + (right - left) / 2;
		
		if (a[mid] == x) {
			return a[mid];
		}else if (a[mid] > x) {
			if (mid - 1 >= left && a[mid - 1] >= x) {
				return a[mid - 1];;
			}
			findCeilValue(left, mid-1, a, n, x);
		} else {
			if (mid + 1 <= right && a[mid + 1] >= x) {
				return a[mid + 1];
			} else {
				findCeilValue(mid+1, right, a, n, x);
			}
		}
	}
	return -1;
}


int main(int argc, char *argv[]) {
	
}