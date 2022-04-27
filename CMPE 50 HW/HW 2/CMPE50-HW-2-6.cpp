#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

// function prototype
string replaceLetter(string str);

int main() {
  string firstName;
  string lastName;
  string name;
  
  // ask user to enter first and last names
  cout << "Enter first name: ";
  cin >> firstName;
  cout << "Enter lastName: ";
  cin >> lastName;
  
  name = replaceLetter(firstName) + " " + replaceLetter(lastName);
  cout << name;
}

// This fuction is to check whether the first letter of string contains a Vowel
string replaceLetter(string str){
  // vowels array store "a e i o u"
  char vowels[] = {'a','e','i','o','u'};
  int flag = 1;
  
  // convert string to lowercase
  transform(str.begin(), str.end(), str.begin(),::tolower);
  
  //check if firstletter is vowel
  for(int i = 0;i < 5;i++){
    if(vowels[i] == str[0]){ // check if the string contins a vowel at the first element
      flag = 0; // then set the value of flag be 0. If the flag = 0, the if statement below will goto else statment.
      
    }
  }
  
  // replacing the letters
  if(flag == 1){ // if the string does not begin vowels
    str = str.substr(1,str.length()) + str[0] + "ay"; // The first letter of the string move to the last place of the string
  }else{
    str = str + "way"; // if the string begins with vowels, 
  }
  
  // convert the first element of a string to uppercase
  str[0] = toupper(str[0]);
  return str;
}

/*
  The output of the program

  Enter first name: Tony
  Enter lastName: Stark
  Onytay Tarksay
  
  Enter first name: Captain
  Enter lastName: America
  Aptaincay Americaway
  
  Enter first name: Iron 
  Enter lastName: Octopus
  Ironway Octopusway
  
  
*/
