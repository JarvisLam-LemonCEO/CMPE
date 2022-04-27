#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
	// map 1 for storing class number and room number
	map<string, int> map1;
	map1.insert(pair<string, int>("CS101", 3004));
	map1.insert(pair<string, int>("CS102", 4501));
	map1.insert(pair<string, int>("CS103", 6755));
	map1.insert(pair<string, int>("NT110", 1244));
	map1.insert(pair<string, int>("CM241", 1411));
	
	// map 2 for storing class numbers and instructor
	map<string, string> map2;
	map2.insert(pair<string, string>("CS101", "Haynes"));
	map2.insert(pair<string, string>("CS102", "Alvarado"));
	map2.insert(pair<string, string>("CS103", "Rich"));
	map2.insert(pair<string, string>("NT110", "Burke"));
	map2.insert(pair<string, string>("CM241", "Lee"));
	
	// map 3 for storing class numbers and time
	map<string, string> map3;
	map3.insert(pair<string, string>("CS101", "8:00 a.m."));
	map3.insert(pair<string, string>("CS102", "9:00 a.m."));
	map3.insert(pair<string, string>("CS103", "10:00 a.m."));
	map3.insert(pair<string, string>("NT110", "11:00 a.m."));
	map3.insert(pair<string, string>("CM241", "1:00 p.m."));
	
	// variable
	string courseNumber;
	cout << "Enter the course number to get more info: ";
	cin >> courseNumber;
	
	map<string, int>::iterator itr;
	map<string, string>::iterator itr1;
	int flag = 0;
	
	for (itr = map1.begin(); itr != map1.end(); itr++) {
		if (itr->first == courseNumber) {
			cout << "\nRoom number: " << itr -> second;
			itr1 = map2.find(itr->first);
			cout << "\nInstructor: " << itr1->second;
			itr1= map3.find(itr->first);
			cout << "\nMeeting time: " << itr1->second;
			flag = 1;
			break;
		}
	}
	
	if(!flag){
		cout << "The inputed course does not exist!" << endl;
	}
	
	return 0;
}