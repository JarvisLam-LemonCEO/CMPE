#include <iostream>
#include "administrator.h"
using namespace std;

// set_supervisor function, changes the supervisor’s name
void Administrator::set_supervisor(string s){
	supervisor = s;
}

// input member function
void Administrator::input(istream& in){
	string name;
	string ssn;
	
	// ask user input name
	cout << "Please input name: ";
	in >> name;
	this->set_name(name); // change the employee's name 
	
	// ask user input ssn
	cout << "Please input ssn: ";
	in >> ssn;
	this->set_ssn(ssn); // change the employee's ssn
	
	// ask user input title, responsibility, supervisor and salary
	cout << "Please input title: ";
	in >> title;

	cout << "Please input responsibility: ";
	in >> responsibility;

	cout << "Please input supervisor: ";
	in >> supervisor;

	cout << "Please input salary: ";
	in >> salary;//annual salary
}


void Administrator::print(ostream& out){
	out << "\n__________________________________________________\n";
	out << "title: " << title << endl;
	out << "responsibility: " << responsibility << endl;
	out << "supervisor: " << supervisor << endl;
	out << "_________________________________________________\n";

}

void Administrator::print_check(){
	set_net_pay(salary);
	cout << "\n__________________________________________________\n";
	cout << "Pay to the order of " << get_name( ) << endl;
	cout << "The sum of " << get_net_pay( ) << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Employee Number: " << get_ssn( ) << endl;
	cout << "Salaried Employee. Regular Pay: "
		 << salary << endl;
	cout << "_________________________________________________\n";
}