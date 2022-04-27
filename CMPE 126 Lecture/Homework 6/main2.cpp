#include <iostream>
#include "myStack.h"
#include "myQueue1.h"

using namespace std;
int main(int argc, char *argv[]) {
	
	// create linkedQueueType and linkedStackType objects
	linkedStackType<char> stack;
	linkedQueueType<char> queue;
	char str[200];
	
	cout << "Checking the line of text whether is a palindrome or not" << endl;
	cout << "Enter a line of text: ";
	cin.getline(str, 200);
	
	int i = 0;
	char ch;
	
	do {
		// acquire the current char into ch for comparing 
		ch = str[i];
		
		// check alphabet and number
		if (ch > 47 && ch < 123) {
			// convert to lower case
			if (ch > 64 && ch < 91) {
				ch += 32;
			}
			
			// insert into stack and queue
			queue.addQueue(ch);
			stack.push(ch);
		}
		
		// go to next character
		i++;
	} while (str[i] != '\0');
	
	while (!stack.isEmptyStack()) {
		//compare the elements for palidrome
		if (stack.top() != queue.front()) {
			break;
		}
		
		// remove the compared elements and go to next position
		stack.pop();
		queue.deleteQueue();
	}
	
	if (stack.isEmptyStack() && queue.isEmptyQueue()) {
		cout << "The text is Palindrome." << endl;
	} else {
		cout << "The text is not Palindrome." << endl;
	}
	
	return 0;
}