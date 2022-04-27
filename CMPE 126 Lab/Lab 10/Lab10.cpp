#include <iostream>
using namespace std;

// Swap
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

// Bubble sort
void bubbleSort( int a[],  int n){
  for ( int i = 0; i < n - 1; i++) {
    for ( int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }
}

// Insertion sort
void insertionSort( int arr[],  int n){
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Selection sort
void selectionSort( int arr[],  int n){
  int mid;
  
  for (int i = 0; i < n - 1; i++) {
    mid = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[mid]){
        mid = j;
      }
    
      swap(arr[mid], arr[i]);
    }
}

void merge( int arr[], int left, int mid, int right){
  
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftArray[n1];
  int rightArray[n2];
  
  for (int i = 0; i < n1; i++){
    leftArray[i] = arr[left + i];
  }
  
  for (int j = 0; j < n2; j++){
    rightArray[j] = arr[mid + 1 + j];
  }
  
  
  int leftPointer = 0; 
  int rightPointer = 0; 
  int originalPointer = left; 
  
  while (leftPointer < n1 && rightPointer < n2) {
    if (leftArray[leftPointer] <= rightArray[rightPointer]) {
      arr[originalPointer] = leftArray[leftPointer];
      leftPointer++;
    } else {
      arr[originalPointer] = rightArray[rightPointer];
      rightPointer++;
    }
    originalPointer++;
  }
  
  while (leftPointer < n1) {
    arr[originalPointer] = leftArray[leftPointer];
    leftPointer++;
    originalPointer++;
  }
  
  while (rightPointer < n2) {
    arr[originalPointer] = rightArray[rightPointer];
    rightPointer++;
    originalPointer++;
  }
}

void mergeSort(int arr[], int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
  
        merge(arr, left, mid, right);
    }
}

int partition (int arr[], int left, int right) { 
  int pivot = arr[right];
  int pointer1 = (left - 1); 
    
  for (int j = left; j <= right - 1; j++) { 
    if (arr[j] < pivot) { 
      pointer1++; 
      swap(arr[pointer1], arr[j]); 
    } 
  } 
  
  swap(arr[pointer1 + 1], arr[right]); 
  
  return (pointer1 + 1); 
} 

void quickSort(int arr[], int left, int right) { 
  if (left < right) { 
    int pivot = partition(arr, left, right); 
    quickSort(arr, left, pivot - 1); 
    quickSort(arr, pivot + 1, right); 
  } 
} 


int main(int argc, char *argv[]){
  
  // let n = 10,000 items
  int size = 10000;
  
  string ms = "ms";
  
  double bubbleSortTime;
  double insertionSortTime;
  double selectionSortTime;
  double mergeSortTime;
  double quickSortTime;
  
  int array1[size];
  int array2[size];
  int array3[size];
  int array4[size];
  int array5[size];
        
  // generate 10,000 random numbers into five saperated arrays
  for (int i = 0; i < size; i++) {
    
    // store random number into num
    int num = rand() % size + 1;
    
    // arrays store random numbers
    array1[i] = num;
    array2[i] = num;
    array3[i] = num;
    array4[i] = num;
    array5[i] = num;
  }
  
  // clock_t to store time
  clock_t start;
  clock_t end;
  
  // Merge Sort
  start = clock();
  mergeSort(array4, 0, size);
  end = clock();
  mergeSortTime = end - start;
  
  // Quick Sort
  start = clock();
  quickSort(array5, 0, size);
  end = clock();
  quickSortTime = end - start;
  
  // Bubble Sort
  start = clock();
  bubbleSort(array1, size);
  end = clock();
  bubbleSortTime = end - start;

  // Insertion sort
  start = clock();
  insertionSort(array2, size);
  end = clock();
  insertionSortTime = end - start;
  
  // Selection sort
  start = clock();
  selectionSort(array3, size);
  end = clock();
  selectionSortTime = end - start;
  
  // print the report on the time taken by each algorithm to sort the list
  cout << "The Time Taken Report" << endl;
  cout << "The time taken by Bubble sort: " << bubbleSortTime << ms << endl;
  cout << "The time taken by Insertion sort: " << insertionSortTime << ms << endl;
  cout << "The time taken by Selection sort: " << selectionSortTime << ms << endl;
  cout << "The time taken by Merge Sort: " << mergeSortTime << ms << endl;
  cout << "The time taken by Quick sort: " << quickSortTime << ms << endl;
  
  return 0;
}
