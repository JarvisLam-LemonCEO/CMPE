#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// SeatPlan class
class SeatPlan{
public:
	
	// constructor 
	SeatPlan(int size);
	
	void display(ostream& out);
	bool checkSeat(char seat[]);
	bool checkFull();
	void assignSeat(char seat[]);
	
	// destructor
	~SeatPlan();
private:
	
	int rowSize;
	char** seats;
	int digitToRow(char d);
	int digitToColumn(char d);
};

// function prototype
void autoTest();
void SeatPlanMenu();

int main(int argc, char *argv[]) {
	autoTest();
}

// constructor
SeatPlan::SeatPlan(int size){
	
	rowSize = size;
	seats = new char*[rowSize];
	
	// store A B C D into the column array 
	for (int i = 0; i < rowSize; i++){
		seats[i] = new char[4];
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
		}
}

// Display Seat Plan function 
void SeatPlan::display(ostream& out){
	
	// print the seat plan
	for (int i = 0; i < rowSize; i++){
		out << i + 1;
		for (int j = 0; j < 4; j++){
			out << " " << seats[i][j];
		}
		out << endl;
	}
}

// cheak the seat function 
bool SeatPlan::checkSeat(char seat[]){
	int row = digitToRow(seat[0]);
	if (row < 1 || row > rowSize){
		return false;
	}
	
	int column = digitToColumn(seat[1]);
	return seats[row - 1][column] != 'X';
}

// check the seat are full function
bool SeatPlan::checkFull(){
	for (int i = 0; i < rowSize; i++){
		for (int j = 0; j < 4; j++){
			if (seats[i][j] != 'X'){ // if the element do not contain 'X'
				return false; // return false
			}
		}
	}
	return true; // return ture unless all the elements of seats contains 'X'
}

// The seat is slected function
void SeatPlan::assignSeat(char seat[]){
	int row = digitToRow(seat[0]);
	int column = digitToColumn(seat[1]);
	
	// the slected seat will store 'X'
	seats[row - 1][column] = 'X';
}

// digitToRow function
int SeatPlan::digitToRow(char d){
	return d - '0'; // return the integer of the row
}

// digitToColumn function
int SeatPlan::digitToColumn(char d){
	if (d <= 'z' && d >= 'a'){
		return d - 'a'; // returnn lower case
	}else{
		return d - 'A'; // return upper case
	}
	
}

// destructor
SeatPlan::~SeatPlan(){
	for (int i = 0; i < rowSize; i++){
		delete[] seats[i]; // delete seat array objects
	}
	delete[] seats; // delete seat array objects
}

void autoTest(){
	
	// ask user to enter their choice
	cout << "Input from the keyboard or an input file?(1 from keyboard, 2 from file)\n";
	int option;
	cin >> option;
	
	if (option == 1) {
		SeatPlanMenu(); // read the input from keyboarf
	} else { // read the ipout from file
		// ask use to enter a file
		cout << "Input file name:\n";
		string file_name;
		cin >> file_name; // read the name of the file
		
		ifstream fin;
		fin.open(file_name.c_str()); // open input file
		
		// show error message if the file doest not exist
		if (fin.fail()) {
			cout << "file cannot open\n";
			exit(1); // quit the program
		}
		
		int rowSize;
		fin >> rowSize; // read the row size from file
		fin.get(); // ignore the new line character.
		
		// declare SeatPlan object
		SeatPlan seatManager(rowSize);
		while (true){
			seatManager.display(cout);
			char seat[4];
			fin.getline(seat, 4);
			
			// if the first element of the seat contain 'e' or E''
			if (seat[0] == 'e' || seat[0] == 'E'){
				cout << "exit\n";
				break;
			}
			
			// check the availablity of seats
			if (seatManager.checkSeat(seat)){
				seatManager.assignSeat(seat);
				cout << seat << " Seat assigned\n";
			}else{
				cout << seat << " Seat not available\n";
			}
			
			// if the seat Plan is full
			if (seatManager.checkFull()){
				cout << "Seat full exit\n";
				break;
			}
		}
		// close the file
		fin.close();
	}
}

// SeatPlanMenu function
void SeatPlanMenu(){
	int rowSize;
	
	// ask user enter number of row 
	cout << "How many rows does the plane have?\n";
	cin >> rowSize;
	cin.get(); // ignore the new line character.
	
	// delare SeatPlan object 
	SeatPlan seatManager(rowSize);
	
	while (true){
		seatManager.display(cout);
		cout << "Which seat would you like? (end to exit)\n";
		char seat[4];
		cin.getline(seat, 4);
		
		// if the first element of the seat contain 'e' or E''
		if (seat[0] == 'e' || seat[0] == 'E'){
			cout << "exit\n";      // then quit the program 
			break;
		}
		
		// check the availablity of seats
		if (seatManager.checkSeat(seat)){
			seatManager.assignSeat(seat);
			cout << "Seat assigned\n";
		}else{
			cout << "Seat is not available\n";
		}
		
		// if the seat Plan is full
		if (seatManager.checkFull()){
			cout << "All seats are full\n";
			break;
		}
	}
}

/*
	The output of the program

	Input from the keyboard or an input file?(1 from keyboard, 2 from file)
	1
	How many rows does the plane have?
	1
	1 A B C D
	Which seat would you like? (end to exit)
	1a
	Seat assigned
	1 X B C D
	Which seat would you like? (end to exit)
	1b
	Seat assigned
	1 X X C D
	Which seat would you like? (end to exit)
	1c
	Seat assigned
	1 X X X D
	Which seat would you like? (end to exit)
	1d
	Seat assigned
	All seats are full
	
	-------------------------------------------------------------------------------------
	Input from the keyboard or an input file?(1 from keyboard, 2 from file)
	
	1
	How many rows does the plane have?
	1
	1 A B C D
	Which seat would you like? (end to exit)
	1a
	Seat assigned
	1 X B C D
	Which seat would you like? (end to exit)
	1a
	Seat is not available
	1 X B C D
	Which seat would you like? (end to exit)
	exit
	exit
	
	---------------------------------------------------------------------------------------
	Input from the keyboard or an input file?(1 from keyboard, 2 from file)
	2
	Input file name:
	seat.txt
	1 A B C D
	2 A B C D
	3 A B C D
	4 A B C D
	5 A B C D
	6 A B C D
	7 A B C D
	1A Seat assigned
	1 X B C D
	2 A B C D
	3 A B C D
	4 A B C D
	5 A B C D
	6 A B C D
	7 A B C D
	2A Seat assigned
	1 X B C D
	2 X B C D
	3 A B C D
	4 A B C D
	5 A B C D
	6 A B C D
	7 A B C D
	3A Seat assigned
	1 X B C D
	2 X B C D
	3 X B C D
	4 A B C D
	5 A B C D
	6 A B C D
	7 A B C D
	4A Seat assigned
	1 X B C D
	2 X B C D
	3 X B C D
	4 X B C D
	5 A B C D
	6 A B C D
	7 A B C D
	5A Seat assigned
	1 X B C D
	2 X B C D
	3 X B C D
	4 X B C D
	5 X B C D
	6 A B C D
	7 A B C D
	6A Seat assigned
	1 X B C D
	2 X B C D
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 A B C D
	1A Seat not available
	1 X B C D
	2 X B C D
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 A B C D
	7A Seat assigned
	1 X B C D
	2 X B C D
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 X B C D
	2B Seat assigned
	1 X B C D
	2 X X C D
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 X B C D
	2C Seat assigned
	1 X B C D
	2 X X X D
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 X B C D
	2D Seat assigned
	1 X B C D
	2 X X X X
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 X B C D
	7D Seat assigned
	1 X B C D
	2 X X X X
	3 X B C D
	4 X B C D
	5 X B C D
	6 X B C D
	7 X B C X
	exit

*/