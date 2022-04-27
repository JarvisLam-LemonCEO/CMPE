#include <iostream>

using namespace std;

// Merge sort
/*
	[1] Devide the array
*/
// a = 5 {0, 1, 2, 3, 4}

int left = 0;
int mid = 2;
int right = 4;

void mergeArrays(int a[], int left, int mid, int right){
	int left_array[mid - left + 1];
	int right_array[right - mid];
	
	for (int i = 0; i < mid - left + 1; i++) {
		left_array[i] = a[left + i];
	}
	
	for (int i = 0; i < right - mid + 1; i++) {
		right_array[i] = a[mid + 1 + i];
	}
	
	int left_pointer = 0;
	int right_pointer = 0;
	int original_pointer = left;
	
	while (left_pointer < mid - left + 1 && right_pointer < right - mid) {
		
		if(left_array[left_pointer] < right_array[right_pointer]) {
			a[original_pointer] = left_array[left_pointer];
			left_pointer++;
		} else {
			a[original_pointer] = right_array[right_pointer];
			right_pointer++;
		}
		original_pointer++;
	}
	
	while (left_pointer < mid - left + 1) {
		a[original_pointer] = left_array[left_pointer];
		left_pointer++;
		original_pointer++;
	}
	
	while (right_pointer < right - mid) {
		a[original_pointer] = right_array[right_pointer];
		right_pointer++;
		original_pointer++;
	}
}

void merge(int a[], int left, int right){
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		merge(a, left, mid);
		merge(a, mid + 1, right);
		
		mergeArrays(a, left, mid, right);
	}
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int left, int right){
	int pivot = a[right];
	int pointer1 = left - 1;
	
	for (int pointer2 = left; pointer2 <= right - 1; pointer2++) {
		if (a[pointer2] < pivot) {
			pointer1++;
			swap(a[pointer1],a[pointer2]);
		}
		
	}
	swap(a[++pointer1],pivot);
	return pointer1;
}

void quickSort(int a[], int left, int right){
	if (left < right) {
		int pivot = partition(a, left, right);
		quickSort(a, left, right);
		quickSort(a, pivot + 1, right);
	}
}



int main(int argc, char *argv[]) {
	
}