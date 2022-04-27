#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int num;
	int factorial = 1;   
	
	//read the a value from the keyboard
	cout << "Enter a number: ";
	cin >> num;
	
	// if the value is a positive number, then compute the nth number factorial
	// 0! = 1
	if (num >= 0){
		// using for loop to calculate n(n-1) for the factorial
		for(int i = num; i >=1; i--){
			factorial *=i;
		}
		cout << "The result of " << num << " factorial is " << factorial; 
	} else {
		cout << "Math error! "; 
	}
}

/*
	The output of Lab Exercise 1.4

	The output of positive number:

	Enter a number: 4
	The result of 4 factorial is 24

	The output of negative number:

	Enter a number: -5
	Math error! 

*/