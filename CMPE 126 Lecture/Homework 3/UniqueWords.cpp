#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
	// variables
	string fileName;
	ifstream file;
	string word;
	
	// use map to store all words of the file
	map<string, int> storeWords;
	
	// use set to store all unque words
	set<string> uniqueWords;
	
	// find the specific file
	fileName = "words.txt";
	
	cout << endl;
	
	// open the file
	file.open(fileName);
	
	// use is_open() to check file whether it can open or not
	
	// if word is not in the map, then make the count as 1
	// else increase by 1
	if(file.is_open()){
		// read all the words in the file
		while (file>>word) {
			if(storeWords.find(word) == storeWords.end()){
				storeWords[word] = 1;
			} else {
				storeWords[word]++;
			}
		}
		
		// add unique words to set
		for (auto i = storeWords.begin(); i != storeWords.end(); i++) {
			if (i->second == 1) {
				uniqueWords.insert(i->first);
			}
		}
		
		// print all unique words
		cout << "The unique words: " << endl;
		for (auto i = uniqueWords.begin(); i != uniqueWords.end(); i++) {
			cout << *i << endl;
		}
		
		// close the file
		file.close();
		
	} else {
		cout << "File cannot be opened!" << endl;
	}
	
}