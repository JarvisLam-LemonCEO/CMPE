#include <iostream>
#include <cmath>
#include "Polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	degree = 10;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(int degr)
{
	degree = degr;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
//	cout << "copy constructor\n";
	degree = poly.get_degree();
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
}

Polynomial::Polynomial(double cf[], int deg)
{
	degree = deg;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = cf[i];
	}
}

Polynomial::~Polynomial()
{
//	cout << "destructor " << *this << " \n";
	delete [] coeff;
}

int Polynomial::get_degree() const
{
	return degree;
}

double Polynomial::get_coeff(int deg) const
{
	if (degree < deg)
	{
		return 0;
		// The input degree is larger than the polynomial degree
	}
	return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
	if (degree < degr)
	{
		cout << "Degree exceeded." << endl;
		return;
	}
	coeff[degr] = val;
}

// Evaluate the polynomial
double Polynomial::evaluate(double val)
{
	double result = 0;
	for (int i = 0; i <= degree; i++)
	{
		result = result + coeff[i] * pow(val, i);
	}
	return result;
}

// Assignment operator
void Polynomial::operator =(const Polynomial &poly)
{
//	cout << "assignment operator overload\n";
	if (this == &poly)
	{
		// Copy to itself. Nothing to be done.
		return;
	}
	degree = poly.get_degree();
	delete [] coeff;
	coeff = new double[degree+1];

	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
	return;
}

// Overloaded operator +
Polynomial operator+(const Polynomial &pola, const Polynomial &polb)
{
	int degA = pola.get_degree();
	int degB = polb.get_degree();

	int max_degr;

	if (degA > degB)
	{
		max_degr = degA;
	} else
	{
		max_degr = degB;
	}

	Polynomial result(max_degr);

	int i;
	for (i = 0; i <= degA && i <= degB; i++)
	{
		double nc = pola.get_coeff(i) + polb.get_coeff(i);
		result.set_coeff(i, nc);
	}

	// Finish the rest of the coefficients
	for (; i <= max_degr; i++)
	{
		if (degA != max_degr)
		{
			result.set_coeff(i, polb.get_coeff(i));
		} else
		{
			result.set_coeff(i, pola.get_coeff(i));
		}
	}
	return result;
}

// Overloaded operator +
Polynomial operator+(const Polynomial &polya, const int b)
{
	Polynomial result(polya.get_degree());

	for (int i = 0; i < polya.get_degree() + 1; i++) {
		if (i == 0) {
			result.set_coeff(i, polya.get_coeff(i) + b);
		} else {
			result.set_coeff(i, polya.get_coeff(i));
		}
	}

	return result;
}

// Overloaded operator +
Polynomial operator+(const int a, const Polynomial &polyb)
{
	double cfa[1];
	cfa[0] = static_cast<double>(a);
	Polynomial polya(cfa, 0);
	return polya + polyb;
}

// Overloaded operator -
Polynomial operator-(const Polynomial &polya, const Polynomial &polyb)
{
	int max_degree;
	if (polya.get_degree() > polyb.get_degree()) {
		max_degree = polya.get_degree();
	} else {
		max_degree = polyb.get_degree();
	}

	Polynomial result(max_degree);

	int i = 0;
	for (i = 0; i <= polya.get_degree() && i <= polyb.get_degree(); i++)
	{
		result.set_coeff(i, polya.get_coeff(i) - polyb.get_coeff(i));
	}

	for (; i <= max_degree; i++)
	{
		if (max_degree == polya.get_degree()) {
			result.set_coeff(i, polya.get_coeff(i));
		} else {
			result.set_coeff(i, -polyb.get_coeff(i));
		}
	}

	return result;

}

// Overloaded operator -
Polynomial operator-(const Polynomial &polya, const int b)
{
	double cfb[1];
	cfb[0] = b;
	Polynomial polyb(cfb, 0);
	return polya - polyb;
}

// Overloaded operator -
Polynomial operator-(const int a, const Polynomial &polyb)
{
	double cfa[1];
	cfa[0] = a;
	Polynomial polya(cfa, 0);
	return polya - polyb;
}

// Overloaded operator *
Polynomial operator*(const Polynomial &polya, const Polynomial &polyb)
{
	int degree_a = polya.get_degree();
	int degree_b = polyb.get_degree();
	int max_degree = degree_a + degree_b;
	Polynomial result(max_degree);


	for (int i = 0; i <= degree_b; i++) {
		for (int j = 0; j <= degree_a; j++)
		{
			double nc = polyb.get_coeff(i) * polya.get_coeff(j) + result.get_coeff(i + j);
			result.set_coeff(i + j, nc);
		}
	}
	return result;
}

// Overloaded operator *
Polynomial operator*(const Polynomial &polya, const int b)
{
	int degree_a = polya.get_degree();
	Polynomial result(degree_a);
	for (int i = 0; i <= degree_a; i++)
	{
		result.set_coeff(i, b * polya.get_coeff(i));
	}

	return result;

}

// Overloaded operator *
Polynomial operator*(const int a, const Polynomial &polyb)
{
	int degree_b = polyb.get_degree();
	Polynomial result(degree_b);

	for (int i = 0; i <= degree_b; i++)
	{
		result.set_coeff(i, a * polyb.get_coeff(i));
	}
	return result;
}

// Overloaded << operator
ostream& operator << (ostream& out, const Polynomial &pol)
{
	int degr = pol.get_degree();

	for (int i = degr; 0 <= i; i--)
	{
		cout << pol.get_coeff(i) << "x^" << i;
		if (i > 0)
		{
			cout << " + ";
		}
	}

	return out;
}