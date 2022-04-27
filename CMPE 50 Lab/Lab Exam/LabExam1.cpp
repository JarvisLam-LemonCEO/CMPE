#include <iostream>

using namespace std;

// function prototype
void aFunction();
void bFunction();


int main(int argc, char *argv[]) {
	// variable for option
	char option;
		
	// do-while loop ask users run the program again and again
	do {
		// prompt the users to enter their option
		cout << "[a] execute exercise 2 (Grocery Expense)" << endl;
		cout << "[b] execute exercise 3 (Frequency of the letters)" << endl;
		cout << "[c] end the program" << endl;
		cout << "Your option: "; 
		cin >> option;
		
		// option is a, then execute this code
		if (option == 'a'){
			// call the exercise 2 function to run Grocery Expense
			aFunction();
		} else if (option == 'b'){ // option is b, then execute this code
			// call the exercise 3 function to count letters 
			bFunction();
		
		}
	} while (option != 'c'); // if the option is c, then end the program
}

// Exercise 2 Function
void aFunction(){
	
	// variabels for exercise3
	double arr2[12]; // store 12 elements for the cost of 12 months
	double avg;
	double annual = 0;
	int counter = 0;
	
	
	for(int i = 0; i < 12; i++){
		cout << "Enter cost of grocery purchase of month #" << i + 1 << " in dollars: ";
		cin >> arr2[i]; // store the cost to arr2
		// annual grocery expense 
		annual += arr2[i];
		counter++;
	}
	
	// find the highest grocery expense
	double highestExpen = arr2[0]; // assume the highestExpen be the largest
	for(int i = 1 ;i < 12; ++i){
		// find the largest element
		if(highestExpen < arr2[i])     // if the current array is larger than the highestExpen
			highestExpen = arr2[i];    // Then the current array store in the highestExpen
	}
	
	// find the lowest grocery expense
	double lowestExpen = arr2[0]; // assume the lowestExpen be the smallest
	for(int i = 1 ;i < 12; ++i){
		// find the smallest element
		if(lowestExpen > arr2[i])  // if the current array is smaller than the highestExpen
			lowestExpen = arr2[i]; //Then the current array store in the lowestExpen
	}
	
	// compute the average monthly expense
	avg = annual / counter;
	
	// print the result
	cout << "The annual expense: " << annual << endl;
	cout << "The highest grocery expense: " << highestExpen << endl;
	cout << "The lowest grocery expense: " << lowestExpen << endl;
	cout << "The average monthly expense: " << avg << endl;
	cout << "" << endl;
	
}

// Exercise 3 Function 
void bFunction(){
	
	// variables for Exercise2
	int N;
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int countD = 0;
	int countOther = 0;
	
	cout <<"Enter the length of a string: ";
	cin >> N; // get the number of N from user
	
	char arr[N]; // array has N size,  which N is defiend by the user
	cout << "Enter a String (in lower case): ";
	cin >> arr; // get a string from user
	
	// using for loop to find the occurence of a b c d in the string
	for(int i = 0; arr[i] != '\0'; i++){ 
		if (arr[i] == 'a'){        // if a is found in the string
			countA++;			  // Then occurence of letter a increase by 1 
		} else if (arr[i] == 'b') { // if b is found in the string
			countB++;				 // Then occurence of letter b increase by 1 
		} else if (arr[i] == 'c') { // if c is found in the string
			countC++;				 // Then occurence of letter c increase by 1 
		} else if (arr[i] == 'd') { // if d is found in the string
			countD++;				 // Then occurence of letter d increase by 1 
		} else{
			countOther++;             // Then occurence of other (including e-z and punctuation) increase by 1 
		}
	}
	
	// print the result of exercise 2
	cout << "Letter \t\t Number of Occurrences" << endl;
	cout << "a \t\t" << countA << endl;
	cout << "b \t\t" << countB << endl;
	cout << "c \t\t" << countC << endl;
	cout << "d \t\t" << countD << endl;
	cout << "others \t\t" << countOther << endl;
	cout << "" << endl;
	
}


/*
	The output of the program
	
	[a] execute exercise 2 (Grocery Expense)
	[b] execute exercise 3 (Frequency of the letters)
	[c] end the program
	Your option: a
	Enter cost of grocery purchase of month #1 in dollars: 3254
	Enter cost of grocery purchase of month #2 in dollars: 35.45 
	Enter cost of grocery purchase of month #3 in dollars: 345.78
	Enter cost of grocery purchase of month #4 in dollars: 3245.76 
	Enter cost of grocery purchase of month #5 in dollars: 7684.43
	Enter cost of grocery purchase of month #6 in dollars: 3464.56 
	Enter cost of grocery purchase of month #7 in dollars: 34.78
	Enter cost of grocery purchase of month #8 in dollars: 346.89
	Enter cost of grocery purchase of month #9 in dollars: 3245.67
	Enter cost of grocery purchase of month #10 in dollars: 345
	Enter cost of grocery purchase of month #11 in dollars: 324
	Enter cost of grocery purchase of month #12 in dollars: 75
	The annual expense: 22401.3
	The highest grocery expense: 7684.43
	The lowest grocery expense: 34.78
	The average monthly expense: 1866.78
	
	[a] execute exercise 2 (Grocery Expense)
	[b] execute exercise 3 (Frequency of the letters)
	[c] end the program
	Your option: b
	Enter the length of a string: 10
	Enter a String (in lower case): JamesBond.
	Letter 		 Number of Occurrences
	a 		1
	b 		0
	c 		0
	d 		1
	others 		8
	
	[a] execute exercise 2 (Grocery Expense)
	[b] execute exercise 3 (Frequency of the letters)
	[c] end the program
	Your option: c
*/