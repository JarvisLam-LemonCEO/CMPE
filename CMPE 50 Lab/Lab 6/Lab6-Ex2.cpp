#include <iostream>

using namespace std;

// class Counter
class Counter{
private:
	
	//private variables
	int count;
	int counter = 0;

public:
	
	// Declare member functions
	Counter();
	Counter(int count2);
	void increseCounter();
	int decreaseCounter();
	int getCount();
	int getCounter();
	void printValue(ostream&);
};


int main(int argc, char const *argv[]) {
	
	int number;
	cout << "Enter a number for counting: ";
	cin >> number;
	
	// create a counter object
	Counter counter(number);
	
	// using while loop to print the count number and counter
	while (1){ // if the statement is true, keep counting the number and counter 
		
		// call the print values function
		counter.printValue(cout);
		// call the increase counter function
		counter.increseCounter();
		
		// assign a terminating number variable to counter decrease counter function
		int tNum = counter.decreaseCounter();
		
		// The if statement is to stop counting
		if (tNum == 0) { // if the tNum equals to zero
			exit(1);     // then stop counting and end the program
		}
	}
	return 0;
}

//member functions
// Default consturctor
Counter::Counter(){ 
	// set count to zero
	count = 0;
}

// Consturctor with int type parameter
Counter::Counter(int count2){ 
	count = count2; 
}

// function used to increase the count by one 
void Counter::increseCounter(){ 
	counter++; 
}

// function used to decrease the count by one 
int Counter::decreaseCounter() {
	if (count == 0){ // if the count is exactly equal to zero
		return 0;    // the return false
	}
	
	count--; // decrease the count by 1
	return 1; // then return true
}

// get count function
int Counter::getCount(){ 
	return count; 
}

// get counter function
int Counter::getCounter(){ 
	return counter; 
}

// function to print values
void Counter::printValue(ostream& cout){
	cout << "Count: " << getCount() << "\n";
	cout << "Counter: " << getCounter() << "\n\n";
}


/*
	The output of the program

	Enter a number for counting: 5
	Count: 5
	Counter: 0
	
	Count: 4
	Counter: 1
	
	Count: 3
	Counter: 2
	
	Count: 2
	Counter: 3
	
	Count: 1
	Counter: 4
	
	Count: 0
	Counter: 5
*/