#include <iostream>
#include "administrator.h"

using namespace std;


int main(){
	
	// declare Administrator object
	Administrator admin;
	
	// call the input function
	admin.input(cin);
	
	// call the print_check() function
	admin.print_check();
	

	return 0;

}


/*
Please input name: Jason
Please input ssn: 1234567
Please input title: CEO
Please input responsibility: Manage
Please input supervisor: none
Please input salary: 123456

__________________________________________________
Pay to the order of Jason
The sum of 123456 Dollars
_________________________________________________
Check Stub NOT NEGOTIABLE 
Employee Number: 1234567
Salaried Employee. Regular Pay: 123456
_________________________________________________


*/