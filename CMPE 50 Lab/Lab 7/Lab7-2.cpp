#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Rational class
class Rational{
public:
	// constructor
	Rational();
	// constructor with parameters
	Rational(int numerator, int denominator);
	
	// input/ output function
	void input(istream& in);
	void output(ostream& out);
	
	// normalize function
	void normalize();
	
	// friend functions 
	friend Rational add(Rational& r1, Rational& r2);
	friend Rational subtract(Rational& r1, Rational& r2);
	friend Rational multiply(Rational& r1, Rational& r2);
	friend Rational division(Rational& r1, Rational& r2);
	
	friend bool equal(const Rational& r1, const Rational& r2);
	friend bool less_than(const Rational& r1, const Rational&r2);
	
private:
	int numerator;
	int denominator;
	
	int gcd(int n1, int n2);
};


int main(int argc, char *argv[]) {
	// declare rational object
	Rational ratNum1, ratNum2;
	
	cout << "Enter a rational number in fraction:  ";
	ratNum1.input(cin);
	cout << "rational number1: ";
	ratNum1.output(cout);
	
	cout << "Enter a rational number in fraction:: ";
	ratNum2.input(cin);
	cout << "rational number2: ";
	ratNum2.output(cout);
	
	cout << "rational number1 + rational number2: ";
	add(ratNum1, ratNum2).output(cout);
	
	cout << "rational number1 - rational number2: ";
	subtract(ratNum1, ratNum2).output(cout);
	
	cout << "rational number1 * rational number2: ";
	multiply(ratNum1, ratNum2).output(cout);
	
	cout << "rational number1 / rational number2: ";
	division(ratNum1, ratNum2).output(cout);
	
	// whether two rational numbers is equal to or more or less than
	if (equal(ratNum1, ratNum2)){
		cout << "rational number1 is equal to rational number2\n";
	}else if (less_than(ratNum1, ratNum2)){
		cout << "rational number1 less than rational number2\n";
	}else{
		cout << "rational number1 larger than rational number2\n";
	}

}

// constructor function
Rational::Rational(){
	
}

// constructor with parameters
Rational::Rational(int numerator, int denominator){
	this->numerator = numerator;
	
	// check wheter denominator is 0
	if (denominator == 0){           // If the denominator is 0
		cout << "Undefine!!! \n";    // show undefine message 
		exit(1);                    // then quit the program
	}else{
		this->denominator = denominator;
		normalize();
	}
}

// input fnction
void Rational::input(istream& in){
	char slash;
	int numerator;
	int denominator;
	
	// enter the rational number
	cin >> numerator >> slash >> denominator;
	
	this->numerator = numerator;
	
	// check whether denominator is 0
	if (denominator == 0){
			cout << "Undefine!!!\n";
			exit(1);
		}
	else
		{
			this->denominator = denominator;
			normalize();
		}
}

// output function
void Rational::output(ostream& out){
	
	if (numerator == 0){           // if the numerator is 0 
		cout << 0 << endl;         // print 0 as the result
	}else if (numerator == denominator){   // if the numerator is equal to the denominator 
		cout << 1 << endl;                  // print 1 as the result
	}else{
		out << numerator << "/" << denominator << endl; // show the fraction
	}
}

// normalize function
void Rational::normalize(){
	
	if (numerator == 0){
		return;
	}
	
	// call the gcd function
	int g = gcd(numerator, denominator);
	

	numerator = numerator / g;
	denominator = denominator / g;
	
	// check positive and negative fractions
	if (numerator * denominator < 0){
		numerator = -abs(numerator);
		denominator = abs(denominator);
	}else{
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
}

// gcd function
int Rational::gcd(int n1, int n2){
	int tmp;
	
	while (n2 != 0){
		tmp = n1;
		n1 = n2;
		n2 = tmp % n2;
	}
	return n1;
	
}

// friend add function
Rational add(Rational& r1, Rational& r2){
	int n = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
	int d = r1.denominator * r2.denominator;
	Rational result(n, d);
	result.normalize();
	return result;
}

// friend subtract function
Rational subtract(Rational& r1, Rational& r2){
	int n = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
	int d = r1.denominator * r2.denominator;
	Rational result(n, d);
	result.normalize();
	return result;
	
}

// friend multiply function
Rational multiply(Rational& r1, Rational& r2){
	int n = r1.numerator * r2.numerator;
	int d = r1.denominator * r2.denominator;
	Rational result(n, d);
	result.normalize();
	return result;
}

// friend division function
Rational division(Rational& r1, Rational& r2){
	// check if the denomiator is equal to 0
	if (r2.numerator == 0){
		cout << "Undefine!!! \n";
		exit(1);
	}
	
	int n = r1.numerator * r2.denominator;
	int d = r1.denominator * r2.numerator;
	Rational result(n, d);
	result.normalize();
	
	return result;
}

// equal friend function 
bool equal(const Rational& r1, const Rational& r2){
	return r1.numerator * r2.denominator == r2.numerator * r1.denominator;
	
}

// less_than friend function
bool less_than(const Rational& r1, const Rational&r2){
	if (r1.numerator == 0 || r2.numerator == 0){
		return r1.numerator < r2.numerator;
	}
	return r1.numerator * r2.denominator < r2.numerator * r1.denominator;
	
}

/*
	The output of the Program

	Enter a rational number in fraction:  1/2
	rational number1: 1/2
	Enter a rational number in fraction:: -301/400
	rational number2: -301/400
	rational number1 + rational number2: -101/400
	rational number1 - rational number2: 501/400
	rational number1 * rational number2: -301/800
	rational number1 / rational number2: -200/301
	rational number1 larger than rational number2
*/