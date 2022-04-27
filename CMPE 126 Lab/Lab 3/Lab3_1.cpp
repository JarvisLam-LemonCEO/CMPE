
#include <iostream>
#include <vector>
//#include <iomanip>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main(int argc, char *argv[]){
  
  // create vector accounts
  vector <Account*> accounts(2);
  
  // assign vectors to different Accounts
  accounts[0] = new SavingsAccount(1000.34, 0.03);
  accounts[1] = new CheckingAccount(209280.0, 1.0);
  
//cout << fixed << setprecision(2);

  // the loop is for asking user to input debit and credit amounts
  for (size_t i = 0; i < accounts.size(); i++){
    cout << "Account " << i + 1 << " balance: $" << accounts[i]->getBalance();
    
    // Call the getBalance function at the Account pointer
    double withdrawalAmount = 0.0;
    cout << "\nEnter an amount to withdraw from Account " << i + 1 << ": ";
    cin >> withdrawalAmount;
    
    // show the updated balance
    cout << "Account " << i + 1 << " balance: $" << accounts[i]->getBalance() << endl;
    
    // Call the debit function ath the Account pointer
    accounts[i]->debit(withdrawalAmount);
    double depositAmount = 0.0;
    cout << "Enter an amount to deposit into Account " << i + 1 << ": ";
    cin >> depositAmount;
    accounts[i]->credit(depositAmount);
    
    // show the updated balance
    cout << "Account " << i + 1 << " balance: $" << accounts[i]->getBalance() << endl;
    cout << endl;
  }
  
  return 0;

}