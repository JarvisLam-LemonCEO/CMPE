#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int main(){
   //variables
   // students' names variable
   string name;
   
   // counter variable
   int counter = 1;
   
   //variable for 5 scores
   double s1;
   double s2;
   double s3;
   double s4;
   double s5;
   
   //read the input file
   ifstream inputFile("grades.txt");
   
   //checking if the input file does not exist
   if(!inputFile){
       cout<<"The inputted file does not exist" << endl;
       exit(1); // end the program
   }
   
   //output file
   ofstream outputFile("grades2.txt");
   
   //using while loop until end of file
   while(!inputFile.eof()){
       // read the name and 5 scores from the input file
       inputFile >> name >> s1 >> s2 >> s3 >> s4 >> s5;
       
      // output the file with correct formet
       outputFile << left << counter << ". " << setw(10) <<name 
      << fixed << right << setw(7) << setprecision(2) << s1
      << right << setw(7) << setprecision(2) << s2
      << right << setw(7) << setprecision(2) << s3
      << right << setw(7) << setprecision(2) << s4
      << right << setw(7) << setprecision(2) << s5 << endl;
       
      // counter increased by 1
       counter++;
   }

   //closing input and output files
   inputFile.close();
   outputFile.close();
   
   return 0;
}

/* The ourput file of the program
1  . Jones       80.50  77.00  95.70  88.60 100.00
2  . Smith       80.00  99.00 100.00  87.80  93.76
3  . Holmes      53.65  84.54  76.67  97.75  89.90
*/
