#include <iostream>
#include <fstream>

using namespace std;

bool isPunctuation(char ch){
	return (ch == '!' || ch == ',' || ch == ';' || ch == '.' || ch == '?' || ch == '-' || ch == '\'' || ch == '\"' || ch == ':');
}

int findPunctuation(const string& str, int n) {
	if(n == 0){
		return 0;
	}
	if (n == 1) {
		return isPunctuation(str[n-1]);
	}
	
	return findPunctuation(str, n-1) + isPunctuation(str[n-1]);
}

void countPunctuation(ifstream& file, int& count){
	if(file){
		string line;
		getline(file, line);
		count = count + findPunctuation(line, line.size());
		countPunctuation(file, count);
	} else {
		return;
	}
}

void printReverse(ifstream& file){
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

int main(int argc, char *argv[]) {
	ifstream file;
	string filename = "/Users/jarvislam/Desktop/Lab 6/input.txt";
	file.open(filename);
	int count = 0;
	
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
		countPunctuation(file, count);
		cout << "The number of punctuation: " << count << endl;
		
	} else if (option == 2) {
		// print the story in reverse
		cout << "Print the story in reverse " << endl;
		cout << "---------------------------" << endl;
		printReverse(file);
	} else if (option == 3) {
		// print the result of number of punctuation marks in the story
		countPunctuation(file, count);
		cout << "The number of punctuation: " << count << endl;
		
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