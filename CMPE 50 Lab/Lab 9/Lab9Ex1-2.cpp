#include <iostream>
#include "Polynomial.h"
#include "Complex.h"
using namespace std;


int main() {
	
	// decare complex obejct
	Complex com_a, com_b;
	
	//prompt the use to enter two compex numbers
	cout << "Enter a complex number A ( a + b * i): ";
	cin >> com_a;
	
	cout << "Enter a complex number B ( a + b * i): ";
	cin >> com_b;
	cout << endl;
	
	// print the two complex numbers
	cout << "x = " << com_a << endl;
	cout << "y = " << com_b << endl;
	cout << endl;
	
	// print complex numbers addition
	cout << "x + y = " << com_a + com_b << endl;
	cout << endl;
	
	// print complex numbers subtruction
	cout << "x - y = " << com_a - com_b << endl;
	cout << endl;
	
	// print complex numbers multiplicaton
	cout << "x * y = " << com_a * com_b << endl;
	cout << endl;
	
	// compare whether the two complex numbers are the same 
	cout << com_a << " == " << com_b << " = " << (com_a == com_b ? "true" : "false");
	cout << endl;

	return 0;
}

/*
	The output of the program 
	Enter a complex number A ( a + b * i): 2 - 3 * i
	Enter a complex number B ( a + b * i): -7 + 5 * i
	
	x = 2 - 3i
	y = -7 + 5i
	
	x + y = -5 + 2i
	
	x - y = 9 - 8i
	
	x * y = 1 + 31i
	
	2 - 3i == -7 + 5i = false
	
*/