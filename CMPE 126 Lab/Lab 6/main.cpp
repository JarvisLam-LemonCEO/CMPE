#include <iostream>
#include <fstream>

using namespace std;

// function prototypes
int punctCount(fstream &file);
bool checkPunct(char marks);
void printReverse(fstream &file);

int main(int argc, char *argv[]) {
	
	// creat file object and open the specific file (input.txt file)
	fstream file("input.txt", ios::in | ios::binary);
	
	int option;
	
	cout << "[1] To find the number of punctuation marks in the story" << endl;
	cout << "[2] To print the story in reverse" << endl;
	cout << "[3] For both" << endl;
	cout << "Your option: ";
	cin >> option;
	cout << endl;
	
	// if statement executes different options
	if(option == 1){
		// print the result of number of punctuation marks in the story
		cout << "The number of punctuation marks in the story is " << punctCount(file)<< endl;
	} else if (option == 2) {
		// print the story in reverse
		cout << "Print the story in reverse " << endl;
		cout << "---------------------------" << endl;
		printReverse(file);
	} else if (option == 3) {
		// print the result of number of punctuation marks in the story
		cout << "The number of punctuation marks in the story is " << punctCount(file)<< endl;
		
		cout << endl;
		
		// clear end of file bad state
		file.clear();
		
		//seek to 0th position from the beginning of the file
		file.seekg(0);
		
		// print the story in reverse
		cout << "Print the story in reverse " << endl;
		cout << "---------------------------" << endl;
		printReverse(file);
	}
	
	
}

// check the punctuation marks in the file
bool checkPunct(char marks){
	if(marks == '!' || marks == ',' || marks == ';' || marks == '.' || marks == '?' || marks == '-' || marks == '\'' || marks == '\"' || marks == ':'){
		return true;
	}
	return false;
}

int punctCount(fstream &file){
	
	// if there is no punctuation mark, the count will be 0
	if (file.eof()) {
		return 0;
	}
	
	// read punctruation marks in the file
	char marks;
	file >> marks;
	
	// if the there are puntuation marks in the file then run the recursion
	if (checkPunct(marks)) {
		return 1 + punctCount(file); // Then punctuaction +1 and runs the punctCount function again until there is no puntuation marks in the file
	}
	
	return punctCount(file);
	
}

// print the story in reverse

void printReverse(fstream &file){
	char letter;
	
	// read every single white space and every single letter in the file
	file >> noskipws >> letter;
	
	if (file.eof()) {
		return;
	}
	
	// run the recursion of printReverse until end of file
	printReverse(file);
	cout << letter;
		
}
