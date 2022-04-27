#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main(){

   // open input file
   ifstream inputFile("LabInput4-1.txt");
   
   // declaring a character array of size 1000
   char arr[1000];
   int counter = 0;
   char c;
   
   //when the input file does not exist
   if(inputFile.fail()){
       cout << "Cannot open Input File!!!" << endl;
       exit(1);
   }

   // open the output file
   ofstream outputFile("LabOutput4-1.txt");

   // read the string from the input file 
   while(inputFile >> c){ 
      // if the sting contain whitespaces and punctuations 
      if(c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '!' || c == '?'){
         continue; // it will skip to next interation
      }
      arr[counter++] = c; // store the alphbet character into the array 
   }

   // closing read stream
   inputFile.close();

   // writing in file
   for(int j = 0; j < counter; j++){  // counter is the length of the array
       outputFile << (char)toupper(arr[j]);
   }

   return 0;
}

/*
   Algorithm/Pseudo-code for Exercise 1

   1.ifstream inputFile("LabInput4-1.txt");
   2. char arr[1000];
      int counter = 0;
      char c;
   3. open and check the input file
   4. if(inputFile.fail()){
        cout << "Cannot open Input File!!!" << endl;
        exit(1);
      }  
   5. read the string in the file
      if the file contain dots, Exclamation marks, Question marks and newlines
      skip to the next interation
      
      while(inputFile >> c){
       if(c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '!' || c == '?'){
         continue;
      }
         arr[counter++] = c ;
      }
   6. close the file
      inputFile.close();
   
   7. wtritting output file and convert to uppercase
      for(int j = 0; j < counter; j++){
         outputFile << (char)toupper(arr[j]);
      }
      
      
      The output file of the program
      THISISASAMPLETESTDATAFILE
      



*/