#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function prototype
void mergeTwoFiles(ifstream &inFile1, ifstream &inFile2, ofstream &outFile);

int main(){
  
  //variable of file names
  string inputFileName1;
  string inputFileName2;
  string outputFileName;
  
  // file variables
  ifstream inputFile1;
  ifstream inputFile2;
  ofstream outputFile;
  
  //input the files
  cout << "Enter the first file: ";
  cin >> inputFileName1; // get the file name
  
  cout << "Enter the second file: ";
  cin >> inputFileName2; // get the file name
  
  cout << "Enter output file: ";
  cin >> outputFileName; // get the output file name
  
  //open the first file
  inputFile1.open(inputFileName1);
  
  //checking if the file doest not exist
  if (inputFile1.fail()){
    cout << "The file does not exist" << endl;
    exit(1);
  }
  
  // open the second file
  inputFile2.open(inputFileName2);
  if (inputFile2.fail()){
    cout << "The file does not exist" << endl;
    exit(1);
  }
  
  //open the output file
  outputFile.open(outputFileName);
  
  //checking if the output file doest not exist
  if (outputFile.fail()){
    cout << "The file does not exist" << endl;
    exit(1);
  }
  
  // call the mergeTwoFiles function
  mergeTwoFiles(inputFile1, inputFile2, outputFile);
  
  // closing the input file 1 and 1 and output files
  inputFile1.close();
  inputFile2.close();
  outputFile.close();
  
  return 0;
}

// The fuction of merging two input files
void mergeTwoFiles(ifstream &inFile1, ifstream &inFile2, ofstream &outFile){
  // variables
  int value1;
  int value2;
  
  // get the values from the files
  inFile1 >> value1;
  inFile2 >> value2;
  
  
  // read the first file and the second file
  while(inFile1 && inFile2){
    if(value1 <= value2){ // compare the values from two files
      outFile << value1 << endl; // if the value1 <= value2, then output values1
      inFile1 >> value1; // get the next value from the first file
    }else{
      outFile << value2 << endl; // if the value1 >= values2, then output values2
      inFile2 >> value2; // get the next values from the second file
    }
  }
  
  // read the first file
  while(inFile1){
    outFile << value1 << endl;
    inFile1 >> value1;
  }
  
  // read the second file
  while(inFile2)
    {
      outFile << value2 << endl;
      inFile2 >> value2;
    }
}

/*
  The output file of the program

1
2
2
3
4
12
13
17
35
100


*/