#include <iostream>
#include<string>
#include "myStack.h"
using namespace std;

class infixToPostfix {
private:
  string infix;
  string postfix;

public:
void showPostfix();
bool isOperator(const char ch);
int precedence(const char operator1, const char operator2);

void getInfix(string infixString);
void showInfix();

};

// getInfix function
void infixToPostfix:: getInfix(string infixString){
  infix = infixString.substr(0, infixString.length() - 1);
}

// showInfix function
void infixToPostfix::showInfix() {
  cout << "\nThe infix expression is : " << infix;
}

// isOperator function
bool infixToPostfix::isOperator(const char ch) {
  // check ch contains the following operators
  if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
    return true;
  } else {
    return false;
  }  
}   

int infixToPostfix::precedence(const char operator1, const char operator2){
  //declare variables to compare the precedence
  int pre1;
  int pre2;
  
  if ((operator1 == '+') || (operator1 == '-')) {
    //low precedence
    pre1 = 0;
  } else {
    if ((operator1 == '*') || (operator1 == '/'))
      pre1 = 1; // high precedence
  }
  
  if ((operator1 == '+') || (operator2 == '-')) {
    pre2 = 0; // low precedence
  } else {
    if ((operator2 == '*') || (operator2 == '/')) {
      pre2 = 1;
    }   
  }
  
  if (pre1 == pre2) {
    return 0;
  } else { 
    if (pre1 > pre2) {
      return 1;
    } else {
      return -1;
    }
  }
}

// Conversion of infix arithmetic exp into postfix exp
void infixToPostfix::showPostfix() {
  // create mysStack object
  stackType<char> stack;
  string pfx = "";
  
  //append a right parenthesis ')' to the end of infix
  infix.append(")");
  
  // push the left parenthesis onto the stack
  stack.push('(');
  int i = 0;
  
  do {
    // when the current element in infix is an operator
    if (isOperator(infix[i])) {
      
      // when the top of the stack is an operator
      if (isOperator(stack.top())) {
        if (precedence(infix[i], stack.top()) == 0) {
          pfx += stack.top();
          stack.pop();
        } else {
          if (precedence(infix[i],stack.top()) == 1) {
            stack.push(infix[i]);
            i++;
          } else {     
            pfx += stack.top();
            stack.pop();
          }
        }
      } else {
        stack.push(infix[i]);
        i++;
      }
    } else {
      if (infix[i] == ')') {   
        while (stack.top() != '(') {
          pfx += stack.top();
          stack.pop();
        }
        stack.pop();
        i++;
      } else {
        if (infix[i] == '(') {     
          stack.push(infix[i]);
          i++;
        } else {     
          pfx += infix[i];
          i++;
        }
      }
    }
  } while (i < infix.length());  
  
  cout << "\nThe postfix expression is : " << pfx;
}  