#include<iostream>
#include<fstream>
using namespace std;

// Function prototype
void swapFunc(int arr[], int n, int i);
void countOccurrence(int arr[], int n);
void countOccurrence(int arr[], int n, ofstream& outFile);

int main() {
	int n = 0;
	int count;
	int arr[50];
	int i = 0;
	int j;
	int option;
	char fileName[50];
	
	cout << "1. Enter number from keyboard" << endl;
	cout << "2. Enter number from file"<< endl;
	cout << "Your option: ";
	cin >> option;
	
	
	if(option == 1){
		
		// open output file
		ofstream outFile;
		outFile.open("LabOutputEX4-2.txt");
		
		// ask user to enter thee size of an array
		cout << "\nEnter the size of the array: ";
		cin >> n;
		for(i = 0; i < n; i++){
			cout << "Enter a numbers: ";
			cin >> arr[i];     //store the numbers to the array
		}
		
		// call the swap function
		swapFunc(arr, n, i);
		
		// save the reesult to the output file
		// call the coutOccurrence() with outFile
		countOccurrence(arr, n, outFile);
		
		// display the result
		// call the ciuntOccurrence()
		countOccurrence(arr,n);
		
	} else {
		cout << "\nEnter a file ";
		cin >> fileName;
		
		// open input file
		ifstream myFile(fileName);
		
		// open output file
		ofstream outFile;
		outFile.open("LabOutputEX4-2.txt");
		
		// check the file for error
		if(myFile.fail()){
			cout << "File doest exist!";
			exit(1);
		}
		
		// read the numbers from file
		while(myFile >> arr[i]){
			n++;
			i++;
		}
		
		// call the swap function
		swapFunc(arr, n, i);
		
		// call the coutOccurrence() with outFile
		countOccurrence(arr, n, outFile);
		
		// call the counterOccurrence() and show it to the screen
		countOccurrence(arr, n);

	}
	

	
	return 0;

}

void swapFunc(int arr[], int n, int i){
	//for loop to swap the positon of the numbers
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// countOccurence() to show the result on screen
void countOccurrence(int arr[], int n){
	cout << "\nN\tCount\n";
	for(int i = 0; i < n; i++){
		int count = 1;
		while(arr[i] == arr[i + 1] && i < n){
			count++;
			i++;
		}
		cout << arr[i] << "\t" << count << endl;
	}
}

// countOccurence() to save the result into a output file
void countOccurrence(int arr[], int n, ofstream& outFile){
	outFile << "\nN\tCount\n";    //       save the string into the output file
	for(int i = 0; i < n; i++){
		int count = 1;
		while(arr[i] == arr[i + 1] && i < n){
			count++;
			i++;
		}
		outFile << arr[i] << "\t" << count << endl; // save the result into the output file
	}
}


/*
	Algorithm/Pseudo-code for Exercise 2
	1. ask user to choose the option
	2. if (option ==1){
		enter the size of the array
		save the numbers into array[i]
		call the swap function
		call the countOccurrence(arr, n) to print the result on screen
	    } else {
			open the input and output file
			check the open file error
			read the numbers from file
			call the swap function
			call the countOccurrence(arr, n, outFile) to save the result into the output file
			call the countOccurrence(arr, n) to print the result on screen
		}

---------------------------------------------------
	The output of the program on screen
	
	1. Enter number from keyboard
	2. Enter number from file
	Your option: 1
	
	Enter the size of the array: 10
	Enter a numbers: 1
	Enter a numbers: 4
	Enter a numbers: 7
	Enter a numbers: 2
	Enter a numbers: 4
	Enter a numbers: 2
	Enter a numbers: 1
	Enter a numbers: 6
	Enter a numbers: 1
	Enter a numbers: 8
	
	N	Count
	8	1
	7	1
	6	1
	4	2
	2	2
	1	3



	1. Enter number from keyboard
	2. Enter number from file
	Your option: 2
	
	Enter a file LabInput4-2.txt
	
	N	Count
	4	2
	3	1
	1	2
	-3	1


*/