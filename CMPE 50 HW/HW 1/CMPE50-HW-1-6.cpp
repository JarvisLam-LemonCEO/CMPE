#include <iostream>
using namespace std;

// function prototype
void countEvens(int arr[], int size);

int main(){
    int arr[] = { 2, 8, 11, 30, 45, 58, 100, 108, 203, 1000 };
    int n = sizeof(arr) / sizeof(arr[0]); // this line is to find the length of the array
       
    // call the countEvens function
    countEvens(arr, n);
}

void countEvens(int arr[], int arr_size){
  // Even Numbers counter
  int countEvenNum = 0;
  
  // The for loop reads all the values in the array
  for (int i = 0; i < arr_size; i++) {
    
    // Checking the number is divied by 2 
    if (arr[i] % 2 == 0){
        countEvenNum++;
    }
      
  }
  
  cout << "The number of Even Numbers is " << countEvenNum;
}

/*
  The Output of the programm:
  The number of Even Numbers is 7


*/