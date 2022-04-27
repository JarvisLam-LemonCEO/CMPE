#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> split(string target, string delimiter);

int main()
{
	vector<string> list;
	list = split("10,20,30,40", ",");
	for (int i; i < list.size(); i++){
		cout << list[i] << endl;
	}
	
	list = split("do re mi fa so la ti do", " ");
	for (unsigned int i; i < list.size(); i++){
		cout << list[i] << endl;
	}
	
	char ch;
	cin >> ch;
	return 0;
}

vector<string> split(string target, string delimeter){
	int index;
	int lastIndex;
	vector<string> list;
	lastIndex = 0;
	index = target.find(delimeter);
	while (index != string::npos){
		// Get substring between lastindex and index
		string s = target.substr(lastIndex, index - lastIndex);
		list.push_back(s);
		lastIndex = index+1;
		index = target.find(delimeter, lastIndex);
	}
	// Put the last item into the vector
	list.push_back(target.substr(lastIndex, target.length() -
		lastIndex));
	return list;
}

/*
20
30
40
re
mi
fa
so
la
ti
do

*/