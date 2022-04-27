#include <iostream>
#include <cmath>

using namespace std;

// function prototype
double average(double s1, double s2, double s3, double s4);
void avg_stdev(double s1, double s2, double s3, double s4, double &average, double &std_dev);

int main(int argc, char *argv[]) {
	double s1 , s2, s3, s4, avg, std_dev;
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
		avg_stdev(s1, s2, s3, s4, avg, std_dev);
		
		cout << "The standard deviation is " << std_dev << endl;
		cout << "Press Y to repeat the program: " ;
		cin >> option;
		
	} while (option == 'Y' || option == 'y'); //If the option is not Y, then end to the program
}

// Average function
double average(double s1, double s2, double s3, double s4){
	double result;
	result = (s1 + s2 + s3 + s4) / 4;
	return result;
}

// standard deviation function
void avg_stdev(double s1, double s2, double s3, double s4, double &average, double &std_dev){
	double d1, d2, d3, d4, mean;
	d1=pow((s1-average),2.);
	d2=pow((s2-average),2.);
	d3=pow((s3-average),2.);
	d4=pow((s4-average),2.);
	mean=(d1+d2+d3+d4)/4.;
	std_dev = sqrt(mean);
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