#include<fstream>
#include"myStack.h"
#include "infixToPostfix.h"
using namespace std;

int main() {
  
  infixToPostfix infix;
  string input;
  
  cout << "Enter an expression: ";
  cin >> input;
  
  infix.getInfix(input);
  infix.showInfix();
  infix.showPostfix();

}  