#include <iostream>
#include <stack>
using namespace std;

/*
	Types pf expression:
	Infix: A + B * C
	Prefix: A + (Answer 0f B*C) -> A + (*BC) -> +A*BC
	Postfix: A + (BC*) -> ABC*+

*/

/*
	Exercise: Infix to prefix conversion
	
	Infix: A + B * C
	Infix: A * B + C
	answer CB
	Prefix: A + (Answer of B*C) -> A + (*BC) -> +A*BC
	
	Prefix: C
	stack: +
	char *
	
	[1] Empty stack
	[2] Emoty string prefix
	[3] Traverse from right to left for infix string
	[4] char:
		1] Operand (Digit/Alphabet) : Append to prefix
		2] Closing parentheses: push to the stack
		3] Opening parentheses: pop the element and append to the prefix
		4] Operator:
			1] If the stack is empty -: push the char in to the stack
			2] Not empty:
				[i] If current char has the higher precedence: evaluate the expression
				[ii] If lower precedence: pop the top element from the stack, evaluate the expression, push the current char
	[5] If stack is not empty: pop the element and append to the prefix
	[6] Reverse the prefix
*/
	
bool isOperand(char c){
	return isalpha(c) || isdigit(c);
}

int getPrecedence(char c){
	if (c == '-' || c == '+') {
		return 1;
	} else if (c == '*' || c =='/') {
		return 2;
	}
	
	return 0;
}

string infixToPrefix(string infix){
	string prefix = "";
	stack<char> st;
	
	for (int i = infix.size()-1; i >= 0; i--) {
		// operand
		if (isOperand(infix[i])) {
			prefix += infix[i];
		} else if (infix[i] == ')') {
			st.push(infix[i]);
		} else if (infix[i] == '(') {
			while (!st.empty() && !st.top() == ')') {
				prefix += st.top();
				st.pop();
			}
		} else {
			if (!st.empty() && getPrecedence(infix[i]) < getPrecedence(st.top())) {
				prefix += st.top();
				st.pop();
			}
			st.push(infix[i]);
		}
	}
	
	while (!st.empty()) {
		prefix += st.top();
		st.pop();
	}
	
	reverse(prefix.begin(), prefix.end());
	return prefix;
}

/*
	string : "111.12"
	double : 111.12
	
*/

int main(int argc, char *argv[]) {
	
}