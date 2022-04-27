#include <iostream>
#include "Polynomial.h"
#include "Complex.h"
using namespace std;


int main() {

	int c = 2;
	
	double test_cfa[] = {2, 5, 3};
	double test_cfb[] = {10, 7};
	
	Polynomial a(test_cfa, 2);
	Polynomial b(test_cfb, 1);
	
	// polynomial + polynomial
	Polynomial sum;
	sum = a + b;
	cout << "polynomial + polynomial" << endl;
	cout << a << " + " << b << " = " << sum;
	
	cout << endl;
	cout << endl;
	
	// polynomial + constant
	cout << "polynomial + constant" << endl;
	cout << a << " + " << c << " = " << a + c;
	
	cout << endl;
	cout << endl;
	
	// constant + polynomial
	cout << "constant + polynomial" << endl;
	cout << c << " + " << a << " = " << c + a;
	
	cout << endl;
	cout << endl;
	
	// polynomial - polynomial
	cout << "polynomial - polynomial" << endl;
	cout << a << " - " << b << " = " << a - b;
	
	cout << endl;
	cout << endl;
	
	// polynomial - constant
	cout << "polynomial - constant" << endl;
	cout << a << " - " << c << " = " << a - c;
	
	cout << endl;
	cout << endl;
	
	// constant - polynomial
	cout << "constant - polynomial" << endl;
	cout << c << " - " << a << " = " << c - a;
	
	cout << endl;
	cout << endl;
	
	// polynomial * polynomial
	cout << "polynomial * polynomial" << endl;
	cout << a << " * " << b << " = " << a * b;
	
	cout << endl;
	cout << endl;
	
	// polynomial * constant
	cout << "polynomial * constant" << endl;
	cout << a << " * " << c << " = " << a * c;
	
	cout << endl;
	cout << endl;
	
	// constant * polynomial
	cout << "constant * polynomial" << endl;
	cout << c << " * " << a << " = " << c * a << endl;
	
	cout << endl;
	cout << endl;

	
	return 0;
}

/*
	The output of the program 

	polynomial + polynomial
	3x^2 + 5x^1 + 2x^0 + 7x^1 + 10x^0 = 3x^2 + 12x^1 + 12x^0
	
	polynomial + constant
	3x^2 + 5x^1 + 2x^0 + 2 = 3x^2 + 5x^1 + 4x^0
	
	constant + polynomial
	2 + 3x^2 + 5x^1 + 2x^0 = 3x^2 + 5x^1 + 4x^0
	
	polynomial - polynomial
	3x^2 + 5x^1 + 2x^0 - 7x^1 + 10x^0 = 3x^2 + -2x^1 + -8x^0
	
	polynomial - constant
	3x^2 + 5x^1 + 2x^0 - 2 = 3x^2 + 5x^1 + 0x^0
	
	constant - polynomial
	2 - 3x^2 + 5x^1 + 2x^0 = -3x^2 + -5x^1 + 0x^0
	
	polynomial * polynomial
	3x^2 + 5x^1 + 2x^0 * 7x^1 + 10x^0 = 21x^3 + 65x^2 + 64x^1 + 20x^0
	
	polynomial * constant
	3x^2 + 5x^1 + 2x^0 * 2 = 6x^2 + 10x^1 + 4x^0
	
	constant * polynomial
	2 * 3x^2 + 5x^1 + 2x^0 = 6x^2 + 10x^1 + 4x^0

*/