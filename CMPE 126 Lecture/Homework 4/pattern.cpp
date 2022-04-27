#include <iostream>

using namespace std;

void pattern(int num1, int num2);
int main(int argc, char *argv[]) {
	int num;
	
	cout << "Enter a number: ";
	cin >> num;
	
	pattern(num, num);
	
	return 0;
}

void pattern(int num1, int num2){
	
	int size = num1 + num2;
	int size2 = num1 + num2 + 1;
	
	if (num1 > 0){
		cout << endl;
		
		// upper part of the pattern
		// print space before *
		for (int i = 0; i < size; i++) {
			cout << " ";
		}
		
		// print the pattern with *
		for (int j = 0; num2 - j >= num1; j++) {
			cout << "* "; 
		}
		
		// 
		pattern(num1 - 1, num2);
		
		cout << endl;
		
		// lower part of the pattern
		// print space before *
		for (int i = 0; i < size2; i++) {
			cout << " ";
		}
		
		// print the pattern with *
		for (int j = 0; num2 - j > num1; j++) {
			cout << "* ";
		}
	}
}