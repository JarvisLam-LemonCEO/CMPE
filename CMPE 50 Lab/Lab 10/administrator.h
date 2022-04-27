#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "salariedemployee.h"

class Administrator : public SalariedEmployee{
public:
	void set_supervisor(string s);
	void input(istream& in);
	void print(ostream& out);
	void print_check();

private:
	string title;
	string responsibility;
	string supervisor;
	double salary;

};

#endif