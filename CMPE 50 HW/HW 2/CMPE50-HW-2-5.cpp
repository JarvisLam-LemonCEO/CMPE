#include <iostream>

using namespace std;

int main(){
    //variables
    string str;
    int flag = 0;
    int wordCount = 0;
    int letterCount;
    
    // ask user input a string
    cout<<"Enter a string: ";
    //get the string
    getline(cin,str);
    
    // assign the letterCount to the length of the string
    letterCount = str.length();
    
    // using the for loop to loop the input string 
    for(int i = 0; i < str.length(); i++){
        
        //check if the string contains space, comma and period
        if(str[i]==' ' || str[i]=='.' || str[i]==','){
            flag = 0; // set flag = 0 in order to execut the  wordcount if statment below
            letterCount--;
        }
        
        // increase word count 
        else if(flag == 0){ // since the default value of flag is 0, then goto this if statement
            flag = 1;       // set the flag value to 1
            wordCount++;   // word count increased by 1 before space, comma and period
        }

        
    }
    
    //print the output
    cout << wordCount << " words and " << letterCount << " letter";

    return 0;
}

/*
    The output of the program

    Enter a string: James Bond is working for MI6.
    6 words and 24 letter

*/