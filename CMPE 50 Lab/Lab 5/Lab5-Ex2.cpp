#include<iostream>
#include<string>
using namespace std;

// global string variable for pronouns 
string sWord1[] = {"he", "him","his"};
string sWord2[] = {"she", "her", "her(s)"};
string sWord3[] = {"He","His"};
string sWord4[] = {"She", "Her"};
string sword1[] = {"she or he","her or him", "hers or his"};
string sword2[] = {"She or he", "Hers or his"};

// function prototype 
string replacePronoun(string word);

int main(){
   string output = "";
   char nextWord;
   string word = "";
   
   
   while(true){
      
      // ask user to input a sentence
      cout << "Enter a sentence: ";
      output = "";
      
      //using do while loop to get the whole sentance string
      do{
       word = "";
       // using while loop to get a word
       while(true){
           cin.get(nextWord); // read a word
           if(isalpha(nextWord)) // check if the word is alphabet
           {
               word += nextWord; // store the pronoun 
           }else{
               break;
           }
      }
         // call the replacePronoun(word);
        output = output + replacePronoun(word); // store the switched pronoun and other words
        output = output + nextWord; // store the next word after pronoun
   }while(nextWord!='\n'); // the next word is not a new line
   
   // show the result to the screen
   cout<<"Replaced sentence:"<< output <<endl;
   
   string ans;
   cout<<"Enter done to repeat the program (Enter exit to end program): ";
   cin >> ans;
   
   // end the program if the user doen't want to repeat it again
   if(ans != "done")
       break;
   }
   
   return 0;
}


//replace gender pronoun
string replacePronoun(string word){  
   string replaceWord = ""; // store the replace pronoun
   
   // usinf for loop to loop the pronoun inside the global string variable for pronouns 
   for(int i = 0; i <3; i++) {  
         if(sWord1[i] == word){     // if the string contains "he, his, him"
            replaceWord = sword1[i];       // then store "she or he","her or him", "hers or his" to replaceWord
         } else if(sWord2[i] == word){   // if the string contains "she, her, hers"
            replaceWord = sword1[i];      // then store "she or he","her or him", "hers or his" to replaceWord
         } else if (sWord3[i] == word) {   // if the string contains "He, His"
            replaceWord = sword2[i];       // then store "she or he","her or him", "hers or his" to replaceWord
         }else if (sWord4[i] == word) {     // if the string contains "She, Her"
            replaceWord = sword2[i];       // then store "She or He", "Hers or His" to replaceWord
         }
   }
   
   // if the words is not pronoun
   if(replaceWord.compare("") == 0)
      replaceWord = word; // save the non pronoun to word
   return replaceWord;
}


/*
   The output of the program
   
   Enter a sentence: See an adviser, talk to him, and listen to him.
   Replaced sentence:See an adviser, talk to her or him, and listen to her or him.
   
   Enter done to repeat the program (Enter exit to end program): done
   Enter a sentence: who is she
   Replaced sentence:who is she or he
   
   Enter done to repeat the program (Enter exit to end program): exit
   
*/