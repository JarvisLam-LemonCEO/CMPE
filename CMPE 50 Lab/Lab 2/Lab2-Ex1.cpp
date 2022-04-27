#include <iostream>

using namespace std;

// function prototypes
double Add(double num3, double num4);
int Add(int num1, int num2);
void Add(string str1, string str2);

int main(int argc, char *argv[]) {
	int num1, num2;
	int option;
	double result1;
	int result2;
	double num3, num4;
	string str1, str2;
	
	// ask user to enter options
	cout << "Enter 1 for double" << endl;
	cout << "Enter 2 for int" << endl;
	cout << "Enter 3 for string" << endl;
	cout << "You option: ";
	cin >> option;
	
	if (option == 1){
		// ask user to enter two double numbers
		cout << "Enter 1st number: ";
		cin >> num3;
		cout << "Enter 2nd number: ";
		cin >> num4;
		result1 = Add(num3, num4);
		
		//Display the doubleresult
		cout << "The result is " << result1;
		
	} else if(option == 2){
		// ask user to enter two int numbers
		cout << "Enter 1st number: ";
		cin >> num1;
		cout << "Enter 2nd number: ";
		cin >> num2;
		result2 = Add(num1, num2);
		
		//Display the int result
		cout << "The result is " << result2;
	} else {
		// ask user to enter two int numbers
		cout << "Enter 1st string: ";
		cin >> str1;
		cout << "Enter 2nd string: ";
		cin >> str2;
		
		// Display the string result & call Add function with string type
		Add(str1, str2);
	}
	
	
}

// function of adding two double numbers
double Add(double num3, double num4){
	double result;
	result = num3 + num4;
	return result;
}

// function of adding two int numbers
int Add(int num1, int num2){
	int result;
	result = num1 + num2;
	return result;
}

// function of adding two strings
void Add(string str1, string str2){
	cout << str1 + " " + str2 ; 
}


/*
	The output of the program
	Enter 1 for double
	Enter 2 for int
	Enter 3 for string
	You option: 1
	Enter 1st number: 3.14
	Enter 2nd number: 6.66
	The result is 9.8
	
	Enter 1 for double
	Enter 2 for int
	Enter 3 for string
	You option: 2
	Enter 1st number: 1
	Enter 2nd number: 5
	The result is 6
	
	Enter 1 for double
	Enter 2 for int
	Enter 3 for string
	You option: 3
	Enter 1st string: James
	Enter 2nd string: Bond
	James Bond

*/