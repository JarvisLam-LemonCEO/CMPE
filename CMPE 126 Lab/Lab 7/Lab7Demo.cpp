#include <iostream>
#include "mystack.hpp"
#include <stack>

using namespace std;


// exercise 1 : to check the vailidity of expression
// input : ()
// (()) (2*(2+5))
// () ( , ), )(
// (2 * (2 + 5))


bool inValidExpression(string expression){
	int length = expression.size();
	stackType<char> stack(length);
	
	for (int i = 0; i < length; i++) {
		char c = expression.at(i);
		if (c == '(') {
			stack.push(c);
		} else if (c == ')') {
			if (stack.isEmptyStack()) {
				return false;
			}
			stack.pop();
		}
	}
	
	return stack.isEmptyStack() ? true : false;
}


// exercise 2 : find out the previous gretaer element

// input : [5, 4, 6, 2]
// output : [-1, 5, -1, 6]

// input : [6, 10, 12, 8, 0, 7]
// output : [-1, -1, -1, 12, 8, 8]

// stack -> 12 8 7
int[] findPreviousGreaterElement(int arr[], int n){
	int answer[n];
	
	stack<int> st;
	answer[0] = -1;
	st.push(arr[0]);
	
	for (int i = 1; i < n; i++) {
		while(!st.empty() && st.top() < arr[i]) {
			st.pop();
		}
		
		int val = st.empty() ? -1 : st.top();
		answer[i] = val;
		st.push(arr[i]);
	}
	
	return answer;
}

int main(int argc, char *argv[]) {
	
}