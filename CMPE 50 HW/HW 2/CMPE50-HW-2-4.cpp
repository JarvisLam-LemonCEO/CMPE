#include <iostream>
#include <fstream>
using namespace std;

int main () {
   
   // variable
   char fileName[1000]; // This variable stores the fileName
   
   // Ask user to input a file
   cout << "Enter a file name: ";
   cin.get(fileName,1000); //get the file name from user 
   
   // open the input file
   ifstream inputFile(fileName);
   
   char ch;
   int count = 1;
   int flag = 1;
   
   // using while loop to get ch from the input file
   while (inputFile.get(ch)){
      if(flag == 1){
         cout << count << ": ";
         flag = 0; // flag = 0 will not goto flag == 1 if statement
         count++;
      }
      //get ch 
      cout << ch;
      
      if(ch == '\n'){ // if there is a new line
         flag = 1;  // then flag = 1 and goto flag == 1 if statement to print number and colon
      }
   }
   //close the input file
   inputFile.close();
   return 0;
}

/* The output of the program

   Enter a file name: file.txt
   1: I am doing this Homework
   2: It is      quite   Hard
   3: I solved     it
   4: Done      Coding

*/
