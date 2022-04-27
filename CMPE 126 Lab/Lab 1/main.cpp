#include <iostream>
#include <stdio.h>
#include "cashRegister.h"
#include "dispenserType.h"

using namespace std;
int main(int argc, char *argv[]) {
	// function prototype
	void showMenu();
	void sellProduct(dispenserType& product, cashRegister& pCounter);
	
	cashRegister counter;
	dispenserType appleJuice(5, 50);
	dispenserType orangeJuice(4, 65);
	dispenserType mangoLassi(3, 35);
	dispenserType fruitPunch(0, 76);
	dispenserType lemonade(5, 35);
	dispenserType pineappleJuice(6, 80);
	dispenserType lemonTea(1, 20);
	
	int selection;
	
	showMenu();
	cin >> selection;
	
		switch (selection) {
			case 1:
				sellProduct(appleJuice, counter);
				break;
			case 2:
				sellProduct(orangeJuice, counter);
				break;
			case 3:
				sellProduct(mangoLassi, counter);
				break;
			case 4:
				sellProduct(fruitPunch, counter);
				break;
			case 5:
				sellProduct(lemonade, counter);
				break;
			case 6:
				sellProduct(pineappleJuice, counter);
				break;
			case 7:
				sellProduct(lemonTea, counter);
				break;
			default:
				cout << "Invalid!" << endl;
		}

	
}

void showMenu() {
	cout << "Fruit Juice Machine" << endl;
	cout << "1. Apple Juice" << endl;
	cout << "2. Orange Juice" << endl;
	cout << "3. Mango Lassi" << endl;
	cout << "4. Fruit Punch" << endl;
	cout << "5. Lemonade" << endl;
	cout << "6. Pineapple Juice" << endl;
	cout << "7. Lemon Tea" << endl;
	cout << "Your Selection: ";
}

void sellProduct(dispenserType& product, cashRegister& pCounter) {
	// variable amount hole the entered amount and amount2 hold the extra amount needed
	int amount;
	int amount2;
	
	if (product.getNoOfItems() > 0) {
		cout << "Please insert money " << product.getCost() << " cents" << endl;
		cin >> amount;
		
		if (amount < product.getCost()) {
			cout << amount << " has been deposited" << endl;
			cout << "Please insert more money " << product.getCost() - amount << " cents" << endl;
			cin >> amount2;
			amount = amount + amount2;
		}
		
		if (amount >= product.getCost()) {
			pCounter.accceptAmount(amount);
			product.makeSale();
			
			cout << "Your change: " << amount - product.getCost() << endl;
			cout << "Take your drink below and enjoy" << endl;
		} else {
			cout << "The amount is not enough. Take back your money." << endl;
		}
	} else {
		cout << "Sorry, this drink is sold out." << endl;
	}

}