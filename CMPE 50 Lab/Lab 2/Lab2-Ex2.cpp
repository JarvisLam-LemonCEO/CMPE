#include <iostream>
using namespace std;
int main() {
    int N;
    
    cout <<"Enter the length of a string: ";
    cin >> N; // get the number of N from user
    
    char arr[N]; // array has N size,  which N is defiend by the user
    cout<<"Enter a String: ";
    cin >> arr; // get a string from user
    
    cout<<"The reverse of the inputed string is: ";
    for(int i = N - 2; i >= 0; i--){ // Because the last element is null and ! is the second last element. N - 2 excludes the !
        cout << arr[i];
    }
    return 0;
}

/*
    The output of the program:

    Enter the length of a string: 6
    Enter a String: abcde!
    The reverse of the inputed string is: edcba
    
*/