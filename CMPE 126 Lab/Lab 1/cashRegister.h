//
//  cashRegister.h
//  Fruit Juice Machine
//
//  Created by Jarvis Lam on 2/2/22.
//

#ifndef cashRegister_h
#define cashRegister_h
#include <stdio.h>

class cashRegister{
public:
    
    // show the current amount in the cash register
    int getCurrentBalance() const;
    
    // receve the amount from user
    void accceptAmount(int amountIn);
    
    // default cnstructor
    cashRegister();
    
    // constructor with parameter which set the register to specific amount.
    cashRegister(int cashIn);
private:
    // variable to store the cash in the register
    int cashOnHand;
};

#endif /* cashRegister_h */
