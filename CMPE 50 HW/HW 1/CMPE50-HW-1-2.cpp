#include <iostream>

using namespace std;

// define constants for the coins in cents 
const double twinkie = 3.50;
const double dollar = 1.0;
const double quarter = 0.25;
const double dime = 0.1;
const double nickle = 0.05;

// function prototype
double puttingCoin();

int main(int argc, char *argv[]) {
	double amount = 0;
	double change;
	
	cout << "The Deep Frying Twinkie Vending Machine" << endl;
	cout << "It costs $3.50"<< endl;
	cout << "-----------------------------------------" << endl;
	
	// Keep adding coin until the amount is equal to or over $3.50
	while (amount < twinkie){
		amount += puttingCoin();
	}
	
	change = amount - twinkie;
	
	cout << "Enjoy your deep-fried twinkie" << endl;
	cout << "The change is " << change;
}

// function of putting the coins to the vending machine
double puttingCoin(){
	int option;
	
	cout << "What is the next coin to be inserted?" << endl;
	cout << "1.Dollar" << endl;
	cout << "2. Quarter" << endl;
	cout << "3. Dime" << endl;
	cout << "4. Nickle" << endl;
	cout << "Please enter your option: ";
	cin >> option;
	
	if (option == 1){
		return dollar;
	} else if (option == 2){
		return quarter;
	} else if (option == 3){
		return dime;
	} else {
		return nickle;
	}
}

/*
	The output of the program
	The Deep Frying Twinkie Vending Machine
	It costs $3.50
	-----------------------------------------
	What is the next coin to be inserted?
	1.Dollar
	2. Quarter
	3. Dime
	4. Nickle
	Please enter your option: 1
	What is the next coin to be inserted?
	1.Dollar
	2. Quarter
	3. Dime
	4. Nickle
	Please enter your option: 1
	What is the next coin to be inserted?
	1.Dollar
	2. Quarter
	3. Dime
	4. Nickle
	Please enter your option: 1
	What is the next coin to be inserted?
	1.Dollar
	2. Quarter
	3. Dime
	4. Nickle
	Please enter your option: 1
	Enjoy your deep-fried twinkie
	The change is 0.5

*/