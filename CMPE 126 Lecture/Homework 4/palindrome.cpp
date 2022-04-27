#include <iostream>
#include <string>

using namespace std;

bool palindrome(string);

int main(int argc, char *argv[]) {
	string Str;
	
	cout << "Enter a string: ";
	cin >> Str;
	
	cout << "The string is " << Str << endl;
	
	// check and print the string whether is palindrome or not
	if (palindrome(Str)){
		cout << "It is Palindrome";
	} else {
		cout << "It's not palindrome";
	}
	
	return 0;
}

bool palindrome(string Str){
	if (Str.length() <= 1){
		return true;
	} else {
		// check the string whether is palindrome
		if (Str.at(0) != Str.at(Str.length() - 1)) { // check if the first letter of the string is not equal to the last letter of the string
			return false;
		} else {
			// recursion
			return palindrome(Str.substr(1, Str.length() - 2));
		}
	}
}