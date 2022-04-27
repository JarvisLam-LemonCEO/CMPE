#include <iostream>

using namespace std;
bool isPrime(int k);

int main(int argc, char *argv[]) {
	int k;
	
	cout << "Enter a number: ";
	cin >> k;

	// using the for loop to print prime number
	for(int i = 3; i <= k; i++){
		if(isPrime(i)){
			cout << i << " is a prime number\n";
		}
	}

	
}

// this bool function is to check whether the inputed number is a prime number or not
bool isPrime(int k){
	//If the k is 2 or 3 it is a prime, then stop here 
	if (k == 2 || k == 3){
		return true;
	} else {
		// Iterate from i = 2 to i = (k-1), test if k can be evenly divided by i, if so k is not a prime, stop.
		for(int i = 2; i <= k - 1; i++){
			if(k % i == 0){
				return false;
			}
		}
		return true;
	}
}

/*	The output of Lab Exercise 1.5

	Enter a number: 30
	3 is a prime number
	5 is a prime number
	7 is a prime number
	11 is a prime number
	13 is a prime number
	17 is a prime number
	19 is a prime number
	23 is a prime number
	29 is a prime number


*/