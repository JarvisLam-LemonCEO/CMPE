#include <iostream>
#include <iomanip>
#include <string>
#include "myStack.h"
using namespace std;

int main(int argc, char *argv[]){
   // create stack object
   stackType<char> stack;
   
   string inputStr;
   char ch;
   int value;
   
   bool isDecimal;
   int numOfdecimals;
   int integerPart;
   double decimalPart;
   double numericFormat;

   //inputStr = "1121.1243";
   
   
   // read string value from user
   cout << "Enter a string: ";
   cin >> inputStr;
   

   // convert the string to the numeric format
   for ( int i = 0; i < inputStr.length(); i++){
       
      //get every character of the string
       ch = inputStr.at(i);
      // check if the string contains decimal 
      if (ch == '.'){
           isDecimal = true;
       }
       else{
         
         // if the string does not contain decimal
         if (!isDecimal){
            // get the integer value of character
            value = (ch - '0');
            
            // multiple the integerPart with 10
            integerPart = integerPart * 10;
            integerPart = integerPart + value;
         }else{
            stack.push(ch);
         }
      }
   }

   if (isDecimal){
      // receive the next number from stack object
      while (!stack.isEmptyStack()){
         numOfdecimals++;
         ch = stack.top();
         stack.pop();
         value = (ch - '0');
            
         // decimalPart deivided by 10
         decimalPart = decimalPart / 10.0;
         decimalPart = decimalPart + value / 10.0;
      }
   }

   // add integerPart and fractionPart to form numeric format.
   numericFormat = integerPart + decimalPart;
   
   cout << setprecision(numOfdecimals) << fixed; // show the exact decimal places from the input string
   cout << "The numeric format of the string: " << numericFormat << endl;
   
   return 0;
}