#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]) {
	int a, b;
	
	// read the a value from the keyboard
	cout << "Enter a number for the base: " ;
	cin >> a;
	
	// read the b value from the keyboard
	cout << "Enter a number for the power: ";
	cin >> b;
	
	// pow() function to compute result of a^b
	cout << a << " raised to the power of " << b << " is " << pow(a, b);
	
	
}

/*  The output of Lan Exercise 1.3

	Enter a number for the base: 2
	Enter a number for the power: 4
	2 raised to the power of 4 is 16
*/