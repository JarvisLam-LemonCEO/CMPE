#include "Complex.h"
#include <cmath>

// constructor function
Complex::Complex():real(0), imaginary(0){
	
}

// constructor function with two double paramters
Complex::Complex(double r, double i):real(r), imaginary(i){

}

// constructor function with one double oarameter
Complex::Complex(double real_part):real(real_part), imaginary(0){

}


bool operator ==(const Complex& coma, const Complex& comb){
	return coma.real == comb.real && coma.imaginary == comb.imaginary;
}

Complex operator +(const Complex& coma, const Complex& comb){
	double real = coma.real + comb.real;
	double imaginary = coma.imaginary + comb.imaginary;
	Complex result(real, imaginary);
	return result;
}

Complex operator -(const Complex& coma, const Complex& comb){
	double real = coma.real - comb.real;
	double imaginary = coma.imaginary - comb.imaginary;
	Complex result(real, imaginary);
	return result;
}

Complex operator *(const Complex& coma, const Complex& comb){
	double real = coma.real * comb.real - coma.imaginary * comb.imaginary;
	double imaginary = coma.real * comb.imaginary + comb.real * coma.imaginary;

	Complex result(real, imaginary);

	return result;
}

istream& operator >> (istream& in, Complex& com){

	double r, i;
	char plus;
	
	// read the input
	in >> r; // read the real number

	in >> plus; // read the math sign 

	in >> i; // read the imaginary sign
	
	com.real = r;
	
	// if the sign before i is negative
	if (plus == '-') {
		com.imaginary = -i; // then the imaginary number is assigned = -i
	} else {
		com.imaginary = i; // otherwise the imaginary number is assigned = i
	}
	
	// read the sign
	in >> plus; // read the * sign
	in >> plus; // read the i sign

	return in;
}

ostream& operator <<(ostream& out, const Complex& com){
	// print the real part
	out << com.real;
	
	// check whether the imaginary part is larger than 0
	if (com.imaginary > 0) {
		out << " + " << com.imaginary; // print positive imaginary number
	} else {
		out << " - " << fabs(com.imaginary); // print negative imaginary number
	}
	out << "i"; // print imaginary sign

	return out;
}