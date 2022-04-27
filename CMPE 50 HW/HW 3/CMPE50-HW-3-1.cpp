#include <iostream>

using namespace std;

// CDAccount class
class CDAccount{
public:
	//Default constructor
	CDAccount();
	
	//Parameterized constructor
	CDAccount(double bal, double intRate, int T);
	
	//Declare member functions
	double InitialBalance();
	double BalanceAtMaturity();
	double InterestRate();
	int Term();
	void input(istream&);
	void output(ostream&);
	
private:
	//variables
	double balance;
	double interestRate;
	int term;
	
};

// main
int main(int argc, char *argv[]) {
	//Variables
	double balance;
	double intRate;
	int term;
	
	// Create a CDAccount class object and assign it to the ADAccount consturctor with parameters
	CDAccount account = CDAccount(100.0, 10.0, 6);
	
	// using constructor with parameters
	//Show initial balance
	cout << "Initial balance: " << account.InitialBalance() << endl;
	
	//Show balance at maturity
	cout << "Balance at maturity: " << account.BalanceAtMaturity() << endl;
	
	//Show interest rate
	cout << "Interest rate: " << account.InterestRate() << endl;
	
	//Show term
	cout << "Term in months: " << account.Term() << endl;
	
	//call output function
	account.output(cout);
	cout << endl;
	
	// using the deault constructor
	// Create a CDAccount object for default constructor
	CDAccount account2 = CDAccount();
	
	//read the input from a user
	cout << "Enter CDAccount initial balance, interest rate and term: " << endl;
	
	//call input function
	account2.input(cin);
	
	//Show initial balance
	cout << "Initial balance: " << account2.InitialBalance() << endl;
	
	//Show balance at maturity
	cout << "Balance at maturity: " << account2.BalanceAtMaturity() << endl;
	
	//Show interest rate
	cout << "Interest rate: " << account2.InterestRate() << endl;
	
	//Show term
	cout << "Term in months: " << account2.Term() << endl;
	
	//call output function
	account2.output(cout);
	
}

// Default constructor
CDAccount::CDAccount(){
	
}

//Consturctor with parameters
CDAccount::CDAccount(double bal, double intRate, int T){
	balance = bal;
	interestRate = intRate;
	term = T;
	
}

//Return Interesr Rate
double CDAccount::InterestRate(){
	return interestRate;
}

//Return initial balance
double CDAccount::InitialBalance(){
	return balance;
}

//Return balance at maturity
double CDAccount::BalanceAtMaturity(){
	return balance * (1 + (interestRate / 100) * (term/12.0));
}

//Return term
int CDAccount::Term(){
	return term;
}

// input member function
void CDAccount::input(istream& inputStream){
	inputStream >> balance;
	inputStream >> interestRate;
	inputStream >> term;
}

// output member function
void CDAccount::output(ostream& outputStream){
	outputStream.setf(ios::fixed);
	outputStream.setf(ios::showpoint);
	outputStream.precision(2);
	outputStream << "When your CDAccount matures in " << term << "months" << endl 
	<< "The balance will be " << BalanceAtMaturity() << endl;
}

/*
	The output of the program

	Initial balance: 100
	Balance at maturity: 105
	Interest rate: 10
	Term in months: 6
	When your CDAccount matures in 6months
	The balance will be 105.00
	
	Enter CDAccount initial balance, interest rate and term: 
	1000000
	500
	12
	Initial balance: 1000000.00
	Balance at maturity: 6000000.00
	Interest rate: 500.00
	Term in months: 12
	When your CDAccount matures in 12months
	The balance will be 6000000.00
*/