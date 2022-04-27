#include <iostream>

using namespace std;

// function prototypes
double acquireHatSize(double height, double weight);
double acquireJacketSize(double height, double weight, int age);
double acquireWaist(double height, double weight, int age);

int main(int argc, char *argv[]) {
	// variables
	double height, weight, hatSize, jacketSize, waist;
	int age;
	char option;
	
	// using do-while loop to repeat the calculation
	do{
		// get the height, weight, age from user 
		cout << "Enter your height: ";
		cin >> height;
		cout << "Enter your weight: ";
		cin >> weight;
		cout << "Enter your age: ";
		cin >> age;
		
		// Call the functions to the compute Hat Size, Jacket Size and Waist
		hatSize = acquireHatSize(height, weight);
		jacketSize = acquireJacketSize(height, weight, age);
		waist = acquireWaist(height, weight, age);
		
		// Show the result
		cout << "The size of the hat is " << hatSize << endl;
		cout << "The size of the jacket is " << jacketSize << endl;
		cout << "The size of the waist is " << waist << endl;
		
		// ask the users whether they want to repeat the program
		cout << "Do you want to repeat the program? (Y/N): ";
		cin >> option;
	} while(option == 'Y' || option == 'y'); // if the option is equal to No, it will end to program
	
	return 0;
}

// The acquireHatSize function
double acquireHatSize(double height, double weight){
	double sizeOfTheHat;
	
	// compute the size of the hat
	sizeOfTheHat = (weight / height) * 2.9;
	
	return sizeOfTheHat;
	
}

// The acquireJacketSize
double acquireJacketSize(double height, double weight, int age){
	double sizeOfTheJacket;
	int ageOver;
	int tenYears;
	
	// compute the size of the jacket
	sizeOfTheJacket = (height * weight) / 288;
	
	// cheking the age is larger than 30
	if (age > 30){
		// Find the age over 30
		ageOver = age - 30;
		
		// find the number of a full 10 years
		tenYears = ageOver / 10;
		
		//adjust by adding 1/8 inch to the size of the jacket
		sizeOfTheJacket +=(tenYears * (1.0/8.0));
	}
	
	return sizeOfTheJacket;
}

// The acruireWaist function
double acquireWaist(double height, double weight, int age){
	double sizeOfTheWaist;
	int ageOver;
	int twoYears;
	
	//compute the size of the waist
	sizeOfTheWaist = weight / 5.7;
	
	//checking the age is over 28
	if (age > 28) {
		// Find the age over 28
		ageOver = age - 28;
		
		// Find the number of full 2 years
		twoYears = ageOver / 2;
		
		//adjust by adding 1/10 inch to the size of the waist
		sizeOfTheWaist += (twoYears * (1.0 / 10.0));
	}
	
	return sizeOfTheWaist;
}


/*
	The output of the program:

	Enter your height: 85
	Enter your weight: 130
	Enter your age: 35
	The size of the hat is 4.43529
	The size of the jacket is 38.3681
	The size of the waist is 23.107
	Do you want to repeat the program? (Y/N): y
	Enter your height: 60
	Enter your weight: 120
	Enter your age: 23
	The size of the hat is 5.8
	The size of the jacket is 25
	The size of the waist is 21.0526
	Do you want to repeat the program? (Y/N): n

*/