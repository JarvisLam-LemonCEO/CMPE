#include <iostream>

using namespace std;

int sum(int n);

int main(int argc, char *argv[]) {
	
	// for loop
	int sum0 = 0;
	int n = 5;
	for (int i = 0; i < n; i++) {
		sum0 += sum0 + i;
	}
	
	// while loop
	int sum1 = 0;
	int i = 1;
	while (i <= n) {
		sum1 += sum1 + i;
		i++;
	}
	
	cout << sum0 << endl;
	cout << sum1 << endl;
	
	cout << sum(5) << endl;
	
}

int sum(int n){
	if (n == 1) {
		return 1; // stop at 1
	}
	
	return n + sum(n - 1);
}

