#include <iostream>
#include <fstream>

using namespace std;

int main() {
   
   // variable for input file
   ifstream inFile("numbers.txt");
   
   // if the file exist, then read the numbers in the file 
   if(inFile.is_open()) {
      // variable
      double avg;
      double num;
      double total = 0;
      int count = 0;
      
      // read the numbers in the file
      while(inFile >> num) {
           total += num; // add the number
           count++; // if there is a number, then increase one 
       }
      // average of the numbers
      avg = total / count;
      
      // display the output
      cout << "The average of the numbers in the file is " << avg;
   } else {
      cout << "The file does not exists"; //this line will be shown if there is no such file
   }
   return 0;
}

/* The input file:
   12.0
   34.6
   33.7 90.6 100.2
   13.70
   13.5
   33.4
   100.23     66.6    120.12

   The output of program:
   
   The average of the numbers in the file is 56.2409

*/