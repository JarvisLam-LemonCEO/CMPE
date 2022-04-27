#include <iostream>
#include <cmath>

using namespace std;

// function prototype
double average(double s1, double s2, double s3, double s4);
double standDeviation(double s1, double s2, double s3, double s4, double average, int num);

int main(int argc, char *argv[]) {
	double s1 , s2, s3, s4, avg, stanDev;
	char option;
	
	// do-while to ask the user to repeat the calculation
	do {
		cout << "Enter the number of S1: ";
		cin >> s1;
		cout << "Enter the number of S2: ";
		cin >> s2;
		cout << "Enter the number of S3: ";
		cin >> s3;
		cout << "Enter the number of S4: ";
		cin >> s4;
		
		avg = average(s1, s2, s3, s4);
		stanDev = standDeviation(s1, s2, s3, s4, avg, 4);
		
		cout << "The standard deviation is " << stanDev << endl;
		cout << "Press Y to repeat the program: " ;
		cin >> option;
		
	} while (option == 'Y' || option == 'y');
}

// Average function
double average(double s1, double s2, double s3, double s4){
	return (s1 + s2 + s3 + s4) / 4;
}

// standard deviation function
double standDeviation(double s1, double s2, double s3, double s4, double average, int num){
	double standDev;
	
	standDev = sqrt((pow((s1 - average), 2) + pow((s2 - average), 2) + pow((s3 - average), 2) + pow((s4 - average), 2)) / num);
	
	return standDev;
}

/*
	The output of the program:

	Enter the number of S1: 45
	Enter the number of S2: 23
	Enter the number of S3: 54
	Enter the number of S4: 65
	The standard deviation is 15.4333
	Press Y to repeat the program: y
	Enter the number of S1: 3
	Enter the number of S2: 4
	Enter the number of S3: 5
	Enter the number of S4: 2
	The standard deviation is 1.11803
	Press Y to repeat the program: n
*/