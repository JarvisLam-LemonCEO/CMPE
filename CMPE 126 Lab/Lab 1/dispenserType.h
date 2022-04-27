//
//  dispenserType.h
//  Fruit Juice Machine
//
//  Created by Jarvis Lam on 2/2/22.
//

#ifndef dispenserType_h
#define dispenserType_h
#include <stdio.h>

class dispenserType{
public:
	// show the number of items in the machine
	int getNoOfItems() const;
	
	// show the cost of the item
	int getCost() const;
	
	// reduce the number of items by 1
	void makeSale();
	
	// default constructor 
	dispenserType();
	
	// constructor with paramters which set the cost and number of items in the disenser to the values specified by user
	dispenserType(int setNoOfItems, int setCost);
private:
	// store the number of items in the machine
	int numberOfItems;
	// store the cost of an item
	int cost;
};

#endif /* dispenserType_h */
