#include <iostream>

using namespace std;

// function prototype
char* delete_repeats(const char letters[], int size);

int main(int argc, char *argv[]) {
	char str[100] = "to be or not to be";
	int size = strlen(str);
	char *noRepeat;
	noRepeat = delete_repeats(str, size);
	cout << noRepeat;
}

// delete_repeats function
char* delete_repeats(const char letters[], int size) {
	// tmp 
	char *tmp = new char[size + 1];
	tmp[0] = letters[0];
	
	int k = 1;
	for (int i = 1; i < size; i++) {
		// set the non repeated letter to flase
		bool exist = false;
		
		// check if there has repeated letters 
		for (int j = 0; j < i; j++) {
			if (letters[j] == letters[i]) {   // if the letters are the same
				exist = true;                 // exist is ture
				break;
			}
		}
		
		// if the letters are not repeated 
		if (!exist) {
			tmp[k] = letters[i];   // store a letter into tmp array
			k++;
		}
	}
	
	// set the last index as null character
	tmp[k] = '\0';
	return tmp;
}

/*
	The output of the program

	to bern

*/