#include <iostream>
#include <cstring>
//#include <string>
using namespace std;

const int MAX_SIZE = 100;

// function prototype
void readCString(char arr[], int size);
void showCString(char arr[], int size);

int main(){
	char str[MAX_SIZE + 1]; // since the last element of the MAX_SISE is '\0', add 1 to store 100 character
	
	// ask user to enter a sentence
	cout << "Enter a sentence: ";
	// call the read 
	readCString(str, MAX_SIZE + 1);
	showCString(str, MAX_SIZE + 1);
}

// this function is to read the string input from user
void readCString(char arr[], int size){
	bool skip_space = false;
	int i = 0;
	char ch;
	cin.get(ch); // get the array
	
	// using while loop to repeat for 99 characters when last elemnt is not a period
	while (i < (MAX_SIZE + 1) - 2 && ch != '.'){
		
		// convert the first character to upper case
		arr[0] = toupper(arr[0]);
		// checl if there is a space
		if (isspace(ch)){
			// check if the first elemnt doesn't have a space
			if (i == 0){
				skip_space = true;
			}else{
				// check if the next element have a space
				if (!skip_space){
					arr[i] = ' ';
					skip_space = true;
					i++;
				}
			}
		}else{
			// capitialize each word
			if (arr[i-1] == ' '){
				arr[i] = toupper(ch);
			}else{
				arr[i] = tolower(ch); // the 
			}
			i++; //go to next index of the array
			skip_space = false;
		}
		cin.get(ch); // get the next character 
	}
	
	// add a period at the line 
	arr[i] = '.';
	i++;
	// add the null character at the end of the array
	arr[i] = '\0';
}

// function is to show the result of the sentence
void showCString(char arr[], int size){
	int i = 0;
	
	// while loop to repeat the 100 characters until it reaches the end of the sentence
	while (i < (MAX_SIZE + 1) && arr[i] != '\0'){
		cout << arr[i];
		i++; // go to next index of the array
	}
}

/* The output of the program 

	Enter a sentence: noW  iS   thE    TiMe  fOr  aLl
	
	gOOD MEN TO  ComE TO   tHe
	
	aId
	
	oF
	
	
	
	
	
	ThE  CounTRY.
	
	Now Is The Time For All Good Men To Come To The Aid Of The Country.

*/