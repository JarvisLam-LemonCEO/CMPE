#include <iostream>

using namespace std;

//function prototypes
double max(double num1, double num2);
double max(double num1, double num2, double num3);

int main(int argc, char *argv[]) {
	double num1;
	double num2;
	double num3;
	
	// read the values of num1, num2, num 3 from keyboard
	cout << "Enter Number 1: ";
	cin >> num1;
	cout << "Enter Number 2: ";
	cin >> num2;
	cout << "Enter Number 3: ";
	cin >> num3;
	
	// print the result
	cout << "The maximum of Number 1 and Number 2 is " << max(num1, num2) << endl;
	cout << "The maximum of Number 1 and Number 2 is " << max(num1, num2, num3);
}

// This function is to find the largest number between two numbers that inputed by user
double max(double num1, double num2){
	if (num1 > num2){ //if num1 is larger than num2, then num1 is the largest
		return num1;
	} else {
		return num2; //if num1 is smaller than num2, then num2 is the largest
	}
}

// This function is to find the largest number between three numbers that inputed by user
double max(double num1, double num2, double num3){
	if (num1 > num2){ // if num1 is larger than num2, then compare num1 with num3 
		if (num1 > num3){ // if num1 is larger than num3, then num1 is the largest 
			return num1;
		} else {
			return num3; //if num1 is smaller than num3, then num3 is the largest
		}
	} else {
		if (num2 > num3){ //if num2 is larger than num3, then num2 is the largest
			return num2;
		} else {
			return num3; //if num2 is smaller than num3, then num3 is the largest
		}
	}
}


/*
	The output of the program 
	Enter Number 1: 3
	Enter Number 2: 6
	Enter Number 3: 10
	The maximum of Number 1 and Number 2 is 6
	The maximum of Number 1 and Number 2 is 10

*/