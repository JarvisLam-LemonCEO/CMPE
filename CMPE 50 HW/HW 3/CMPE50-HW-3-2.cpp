#include <iostream>

using namespace std;

// Month class
class Month{
public:
	// constructor with parameters to set the month using the 1st 3 characters of a month
	Month(char firstChar, char secondChar, char thirdChar);
	
	// consturctor with a int parameter to set the month using a number between 1 and 12
	Month(int integer);
	
	// default constructor
	Month();
	
	// Function get the number between 1 and 12
	void getMonthWithInterger(istream&);
	
	// Function get the 1st 3 characters of the month 
	void getMonthWithFirstThreeChar(istream&);
	
	// show the month as a integer
	void showMonthAsInt(ostream&);
	
	// show the month as the first three letters
	void showMonthAsFirstThreeChar(ostream&);
	// get next month fucntion
	Month getNextMonth();
	
private:
	// variable
	int month;
};

int main(int argc, char *argv[]) {
	// create a class object for monthTest
	Month monthTest;
	
	// using the constructor Month(char firstChar, char secondChar, char thirdChar)
	cout << "Month(char firstChar, char secondChar, char thirdChar)" << endl;
	
	//Test January
	monthTest = Month('j', 'a', 'n');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test Febrary
	monthTest = Month('f', 'e', 'b');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test March
	monthTest = Month('m', 'a', 'r');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test April
	monthTest = Month('a', 'p', 'r');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test May
	monthTest = Month('m', 'a', 'y');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test June
	monthTest = Month('j', 'u', 'n');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test July
	monthTest = Month('j', 'u', 'l');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test August
	monthTest = Month('a', 'u', 'g');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test September
	monthTest = Month('s', 'e', 'p');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test October
	monthTest = Month('o', 'c', 't');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test November
	monthTest = Month('n', 'o', 'v');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	//Test October
	monthTest = Month('d', 'e', 'c');
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "\t";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	
	// using Month(int integer) constructor
	for (int i = 1; i <= 12; i++) {
		monthTest = Month(i);
		monthTest.showMonthAsInt(cout);
		cout << "\t";
		monthTest.showMonthAsFirstThreeChar(cout);
		cout << endl;
	}
	
	// Test the getMonthWithFirstThreeChar() function
	cout << "\n Using getMonthWithFirstThreeChar()" << endl;
	monthTest = Month();
	cout << "Enter the first three letter of the month: ";
	monthTest.getMonthWithFirstThreeChar(cin);
	cout << "Month: ";
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << "Month Integer: ";
	monthTest.showMonthAsInt(cout);
	cout << endl;
	
	// Test the getMonthWithInt()
	cout << "\n Using getMonthWithInt()" << endl;
	monthTest = Month();
	cout << "Enter an integer of a month: ";
	monthTest.getMonthWithInterger(cin);
	cout << "Month integer: ";
	monthTest.showMonthAsInt(cout);
	cout << "\nMonth: ";
	monthTest.showMonthAsFirstThreeChar(cout);
	cout << endl;
	
	// test the nextFunction()
	cout << "\nUsing the nextMonth()" << endl;
	monthTest = Month();
	cout << "Enter an integer of a month: ";
	monthTest.getMonthWithInterger(cin);
	cout << "Current Month interger: ";
	monthTest.showMonthAsInt(cout);
	cout << "\nCurrent month: ";
	monthTest.showMonthAsFirstThreeChar(cout);
	
	// call the getNextMonth function
	Month nextMonth = monthTest.getNextMonth(); //get the next month 
	cout << "\nNext month integer: ";
	nextMonth.showMonthAsInt(cout);
	cout << "\nNext month: ";
	nextMonth.showMonthAsFirstThreeChar(cout);
	cout << endl;
	
	return 0;
}

// constructor with char parameters (1st 3 characters)
Month::Month(char firstChar, char secondChar, char thirdChar){
	// convert the 1st 3 characters to lower case
	firstChar = towlower(firstChar);
	secondChar = towlower(secondChar);
	thirdChar = towlower(thirdChar);
	
	// check the three characters contains the first three letters of a month
	if(firstChar == 'j' && secondChar == 'a' && thirdChar == 'n'){ // if contains jan
		month = 1; // 
	} else if (firstChar == 'f' && secondChar == 'e' && thirdChar == 'b') { // if contains feb
		month = 2;
	} else if (firstChar == 'm' && secondChar == 'a' && thirdChar == 'r') { // if contains mar
		month = 3;
	} else if (firstChar == 'a' && secondChar == 'p' && thirdChar == 'r') { // if contains apr
		month = 4;
	} else if (firstChar == 'm' && secondChar == 'a' && thirdChar == 'y') { // if contains may
		month = 5;
	} else if (firstChar == 'j' && secondChar == 'u' && thirdChar == 'n') { // if contains jun
		month = 6;
	} else if (firstChar == 'j' && secondChar == 'u' && thirdChar == 'l') { // if contains jul
		month = 7;
	} else if (firstChar == 'a' && secondChar == 'u' && thirdChar == 'g') { // if contains aug
		month = 8; 
	} else if (firstChar == 's' && secondChar == 'e' && thirdChar == 'p') { // if contains sep
		month = 9;
	} else if (firstChar == 'o' && secondChar == 'c' && thirdChar == 't') { // if contains oct
		month = 10;
	} else if (firstChar == 'n' && secondChar == 'o' && thirdChar == 'v') { // if contains nov
		month = 11;
	} else if (firstChar == 'd' && secondChar == 'e' && thirdChar == 'c') { // if contains dec
		month = 12;
	} else {
		// show an error message
		cout << firstChar << secondChar << thirdChar << "is not the short form of a month";
		exit(1); // then terminate the program
	}
}

// constructor with int parameters (month in a number)
Month::Month(int integer){
	// check if the int value is between 1 and 12
	if (integer >= 1 && integer <= 12) {
		month = integer;
	} else {
		// show an error message
		cout << integer << "is a number for a month";
		exit(1); // then terminate the program
	}
}

// default consturctor 
Month::Month(){
	
}

// get a month with integer function
void Month::getMonthWithInterger(istream& input){
	//read an integer
	input >> month;
}

// get a month with first three characters
void Month::getMonthWithFirstThreeChar(istream& input){
	// variables
	char firstChar;
	char secondChar;
	char thirdChar;
	
	// read first three characters
	input >> firstChar >> secondChar >> thirdChar;
	
	// convert the 1st 3 characters to lower case
	firstChar = towlower(firstChar);
	secondChar = towlower(secondChar);
	thirdChar = towlower(thirdChar);
	
	// check the three characters contains the first three letters of a month
	if(firstChar == 'j' && secondChar == 'a' && thirdChar == 'n'){ // if contains jan
		month = 1; // 
	} else if (firstChar == 'f' && secondChar == 'e' && thirdChar == 'b') { // if contains feb
		month = 2;
	} else if (firstChar == 'm' && secondChar == 'a' && thirdChar == 'r') { // if contains mar
		month = 3;
	} else if (firstChar == 'a' && secondChar == 'p' && thirdChar == 'r') { // if contains apr
		month = 4;
	} else if (firstChar == 'm' && secondChar == 'a' && thirdChar == 'y') { // if contains may
		month = 5;
	} else if (firstChar == 'j' && secondChar == 'u' && thirdChar == 'n') { // if contains jun
		month = 6;
	} else if (firstChar == 'j' && secondChar == 'u' && thirdChar == 'l') { // if contains jul
		month = 7;
	} else if (firstChar == 'a' && secondChar == 'u' && thirdChar == 'g') { // if contains aug
		month = 8; 
	} else if (firstChar == 's' && secondChar == 'e' && thirdChar == 'p') { // if contains sep
		month = 9;
	} else if (firstChar == 'o' && secondChar == 'c' && thirdChar == 't') { // if contains oct
		month = 10;
	} else if (firstChar == 'n' && secondChar == 'o' && thirdChar == 'v') { // if contains nov
		month = 11;
	} else if (firstChar == 'd' && secondChar == 'e' && thirdChar == 'c') { // if contains dec
		month = 12;
	} else {
		// invalid month set to 0
		month = 0;
	}
	
}

// function to show month as a integer
void Month::showMonthAsInt(ostream& output){
	// check if the integer is between 1 and 12
	if (month >= 1 && month <=12) {
		// ptint the month as an integer
		output << month;
	} else {
		output << "No integer matched";
	}
}

// function to show month as the first three letters
void Month::showMonthAsFirstThreeChar(ostream& output){
	// use switch to show corresonded month
	
	switch (month) {
		case 1: // if the case is January
			output << "Jan";
			break;
		case 2: // if the case is February
			output << "Feb";
			break;
		case 3: // if the case is March
			output << "Mar";
			break;
		case 4: // if the case is April
			output << "Apr";
			break;
		case 5: // if the case is May
			output << "May";
			break;
		case 6: // if the case is June
			output << "Jun";
			break;
		case 7: // if the case is July
			output << "Jul";
			break;
		case 8: // if the case is August
			output << "Aug";
			break;
		case 9: // if the case is September
			output << "Sep";
			break;
		case 10: // if the case is October
			output << "Oct";
			break;
		case 11: // if the case is November
			output << "Nov";
			break;
		case 12: // if the case is December
			output << "Dec";
			break;
		default:
			output << "No month matched!";
	}
}

// Function to get the next month
Month Month::getNextMonth(){
	int nextMonth = 0;
	
	// check the current month is between 1 and 12
	if (month >= 1 && month <= 12) {
		nextMonth = (month % 12) + 1; // next month
	}
	// return next to the Month(int integer) constructor
	return Month(nextMonth);
}

/*
	The output of the program 
	Month(char firstChar, char secondChar, char thirdChar)
	Jan	1
	Feb	2
	Mar	3
	Apr	4
	May	5
	Jun	6
	Jul	7
	Aug	8
	Sep	9
	Oct	10
	Nov	11
	Dec	12
	1	Jan
	2	Feb
	3	Mar
	4	Apr
	5	May
	6	Jun
	7	Jul
	8	Aug
	9	Sep
	10	Oct
	11	Nov
	12	Dec
	
	Using getMonthWithFirstThreeChar()
	Enter the first three letter of the month: mar
	Month: MarMonth Integer: 3
	
	Using getMonthWithInt()
	Enter an integer of a month: 9
	Month integer: 9
	Month: Sep
	
	Using the nextMonth()
	Enter an integer of a month: 6
	Current Month interger: 6
	Current month: Jun
	Next month integer: 7
	Next month: Jul
*/