#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// function prototype
void sortTwoFiles(ifstream& inFile1, ifstream& inFile2, ofstream& outFile);

int main(int argc, char *argv[]) {
	
	// variables 
	ifstream inFile1;
	ifstream inFile2;
	ofstream outFile;
	
	// open input file 1
	inFile1.open("LabInput4-3.txt");

	// check whether file 1 exists or not 
	if(inFile1.fail()){
		cout << "File 1 doest not exist";
		exit(1); // End the program
	}
	
	// open input file 2
	inFile2.open("LabInput4-4.txt");
	
	// check whether file 2 exists or not 
	if(inFile2.fail()){
		cout << "File 1 doest not exist";
		exit(1); // End the program
	}
	
	// open the output file 
	outFile.open("LabOutput4-3.txt");
	
	// check whether file 2 exists or not 
	if(outFile.fail()){
		cout << "File 1 doest not exist";
		exit(1); // End the program
	}
	
	// call the sortTwoFiles function 
	sortTwoFiles(inFile1, inFile2, outFile);
	
	// close all the files
	inFile1.close();
	inFile2.close();
	outFile.close();
	
	
	return 0;
}

void sortTwoFiles(ifstream& inFile1, ifstream& inFile2, ofstream& outFile){
	int num1;
	int num2;
	
	// get the numbers from File 1 and File 2
	inFile1 >> num1;
	inFile2 >> num2;
	
	// check whether the files reach the end of the files
	while (!inFile1.eof() && !inFile2.eof()) {
		// check whether the number in the File 1 is smaller than or equal to the number in the File 2
		if(num1 <= num2){           // the number in the File 1 is smaller than or equal to the number in the File 2
			outFile << num1 << endl; // store the number of File 1 to the output file
			inFile1 >> num1;            // read the next number in file 1
		} else {
			outFile << num2 << endl; // store the number of File 2 to the output file
			inFile2 >> num2;         // read next number in file 2
		}
	}
	
	// store the remaining numbers in the File 1 and File 2 into the output file
	// show the remaining numbers in the File 1
	if (num1 <= num2){
		while (!inFile1.eof()) {
			outFile << num1 << endl; // store the number of File 1 to the output file
			inFile1 >> num1;            // read the next number in file 1
		}
	} else {
		// show the remaining numbers in the File 2
		while (!inFile2.eof()) {
			outFile << num2 << endl; // store the number of File 2 to the output file
			inFile2 >> num2;         // read next number in file 2
		}
	}
}

/*
	Algorithm/Pseudo-code for Exercise 3
	1. open the two input files and check for open errors
	2. declare sortTwoFiles function
	3. declare num1 and num2 variables
	4. get the numbrs from file 1 and file 2
	5. use while loop and !eof() to store numbers of both file 1 and file 2
	6. show the remaining numbers 
	
	The output file of the program
	6
	10
	15
	22
	30
	33
	40
	50
	60
	62
	77
	88
	89


*/