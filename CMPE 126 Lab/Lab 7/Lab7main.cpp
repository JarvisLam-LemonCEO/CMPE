#include <iostream>
#include <stack>

using namespace std;
int main(int argc, char *argv[]) {
	string expression;
	cout << "Enter a arithmetic expression: ";
	getline(cin, expression);
	
	
	bool isMatch = true;
	
	stack<char> expression2;
	for(int i = 0; i < expression.size(); i++){
		if( (expression.at(i) >= '0' && expression.at(i) <= '9') || expression.at(i) == '+' || expression.at(i)== '-' || expression.at(i) == '/' || expression.at(i) == '*' || expression.at(i )== ' ' ){
			continue; // use "continue" to skip if the expression has these number and operators
			
		}
		
		// check inputed expression has { and (
		if( expression.at(i)=='{' || expression.at(i)=='(' ){
			expression2.push(expression.at(i));
		} else if (!expression2.empty() && ((expression2.top() == '{' && expression.at(i) == '}') || (expression2.top() == '(' && expression.at(i) == ')'))){
			expression2.pop();
		} else {
			isMatch = false;
		}
		
	}
	
	if(!expression2.empty()) {
		cout << "The expression does not contain matching grouping symbols." << endl;
	} else {
		if(isMatch) {
			cout << "The expression contains matching grouping symbols." << endl; // isMatch is true
		} else {
			cout << "The expression does not contain matching grouping symbols." << endl; // isMatch is false
		}
	}
	return 0;
}