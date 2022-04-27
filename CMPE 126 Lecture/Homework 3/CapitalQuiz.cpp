#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#include <time.h>

using namespace std;

// function prototype
void quizMenu();

int main(int argc, char *argv[]) {
	// use map to store state capitals
	map<string, string> state;
	state["Alabama"] = "Montgomery";
	state["Alaska"] = "Juneau";
	state["Arizona"] = "Phoenix";
	state["Arkansas"] = "Little Rock";
	state["California"] = "Sacramento";
	state["Colorado"] = "Denver";
	state["Connecticut"] = "Hartford";
	state["Delaware"] = "Dover";
	state["Florida"] = "Tallahassee";
	state["Georgia"] = "Atlanta";
	state["Hawaii"] = "Honolulu";
	state["Idaho"] = "Boise";
	state["Illinois"] = "Springfield";
	state["Indiana"] = "Indianapolis";
	state["Iowa"] = "Des Moines";
	state["Kansas"] = "Topeka";
	state["Kentucky"] = "Frankfort";
	state["Louisiana"] = "Baton Rouge";
	state["Maine"] = "Augusta";
	state["Maryland"] = "Annapolis";
	state["Massachusetts"] = "Boston";
	state["Michigan"] = "Lansing";
	state["Minnesota"] = "Saint Paul";
	state["Mississippi"] = "Jackson";
	state["Missouri"] = "Jefferson City";
	state["Montana"] = "Helena";
	state["Nebraska"] = "Lincoln";
	state["Nevada"] = "Carson City";
	state["New Hampshire"] = "Concord";
	state["New Jersey"] = "Trenton";
	state["New Mexico"] = "Santa Fe";
	state["New York"] = "Albany";
	state["North Carolina"] = "Raleigh";
	state["North Dakota"] = "Bismarck";
	state["Ohio"] = "Columbus";
	state["Oklahoma"] = "Oklahoma City";
	state["Oregon"] = "Salem";
	state["Pennsylvania"] = "Harrisburg";
	state["Rhode Island"] = "Providence";
	state["South Carolina"] = "Columbia";
	state["South Dakota"] = "Pierre";
	state["Tennessee"] = "Nashville";
	state["Texas"] = "Austin";
	state["Utah"] = "Salt Lake City";
	state["Vermont"] = "Montpelier";
	state["Virginia"] = "Richmond";
	state["Washington"] = "Olympia";
	state["West Virginia"] = "Charleston";
	state["Wisconsin"] = "Madison";
	state["Wyoming"] = "Cheyenne";
	
	// use vector to generate random states
	vector<string> states = {
		"Alabama",
		"Alaska",
		"Arizona",
		"Arkansas",
		"California",
		"Colorado",
		"Connecticut",
		"Delaware",
		"Florida",
		"Georgia",
		"Hawaii",
		"Idaho",
		"Illinois",
		"Indiana",
		"Iowa",
		"Kansas",
		"Kentucky",
		"Louisiana",
		"Maine",
		"Maryland",
		"Massachusetts",
		"Michigan",
		"Minnesota",
		"Mississippi",
		"Missouri",
		"Montana",
		"Nebraska",
		"Nevada",
		"New Hampshire",
		"New Jersey",
		"New Mexico",
		"New York",
		"North Carolina",
		"North Dakota",
		"Ohio",
		"Oklahoma",
		"Oregon",
		"Pennsylvania",
		"Rhode Island",
		"South Carolina",
		"South Dakota",
		"Tennessee",
		"Texas",
		"Utah",
		"Vermont",
		"Virginia",
		"Washington",
		"West Virginia",
		"Wisconsin",
		"Wyoming",
	};
	
	// size of vector
	int num = state.size();
	
	// random function
	srand(time(0));
	
	// count for correct answer
	int correctAns = 0;
	
	//Quiz Start
	quizMenu();
	
	// loop 5 questions with random state
	for (int i = 0; i < 5; i++) {
		// generate random states
		string randomState = states[rand()%num];
		cout << i + 1 << ". What is the name of capital of "<< randomState << "? ";
		
		
		string answer;
		// get answer from user
		getline(cin, answer);
		
		if (answer == state[randomState]) { // check if inputed anwser match the state in the map
			correctAns++; // correct answer count +1
		}
	}
	
	if (correctAns < 3) {
		cout << "Your score is " << correctAns << " out of 5." << endl;
	} else {
		cout << "Congratulations! Your score is " << correctAns << " out of 5"<< endl;
	}
	
	
}

void quizMenu() {
	cout << "States Capital Quiz" << endl;
	cout << "There are 5 questions for this quiz" << endl;
	cout << "You need to input state capital" << endl;
}