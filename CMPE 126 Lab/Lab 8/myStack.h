#ifndef H_StackType
#define H_StackType
#include <iostream>
#include <cassert>
#include "StackADT.h"
using namespace std;
//define the class stackType
template <class Type>
class stackType : public stackADT<Type>
{
public:
   //declare the public functions.
   const stackType<Type>& operator=(const stackType<Type>&);
   void initializeStack();
   bool isEmptyStack() const;
   bool isFullStack() const;
   void push(const Type& newItem);
   Type top() const;
   void pop();
   stackType(int stackSize = 100);
   stackType(const stackType<Type>& otherStack);
   ~stackType();
private:
   //declare the variables
   int maxStackSize;
   int stackTop;
   Type *list;
              
   void copyStack(const stackType<Type>& otherStack);
};
//initialize the stack top with 0
template <class Type>
void stackType<Type>::initializeStack()
{
   stackTop = 0;
}
//checks whether the stack is empty.
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
   return (stackTop == 0);
}
//checks whether the stack is full.
template <class Type>
bool stackType<Type>::isFullStack() const
{
   return (stackTop == maxStackSize);
}
//inserts a value into the stack.
//increments the stackTop value.
//if stack is full, prints an error message.
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
   if (!isFullStack())
   {
       list[stackTop] = newItem;
       stackTop++;
   }
   else
       cout << "Cannot add to a full stack." << endl;
}
//returns the top value of the stack
template <class Type>
Type stackType<Type>::top() const
{
   assert(stackTop != 0);
   return list[stackTop - 1];
}
//deletes the top value into the stack.
//decrements the stackTop value.
//if stack is empty, prints an error message.
template <class Type>
void stackType<Type>::pop()
{
   if (!isEmptyStack())
       stackTop--;
   else
       cout << "Cannot remove from an empty stack." << endl;
}
//sets the size of the stack
template <class Type>
stackType<Type>::stackType(int stackSize)
{
   if (stackSize <= 0)
   {
       cout << "Size of the array to hold the stack must " << "be positive." << endl;
       cout << "Creating an array of size 100." << endl;
       maxStackSize = 100;
   }
   else
       maxStackSize = stackSize;
   stackTop = 0;
   list = new Type[maxStackSize];
}
//destructor
template <class Type>
stackType<Type>::~stackType()
{
   delete[] list;
}
//copy the stack content into the other stack.
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
   delete[] list;
   maxStackSize = otherStack.maxStackSize;
   stackTop = otherStack.stackTop;
   list = new Type[maxStackSize];
   for (int j = 0; j < stackTop; j++)
       list[j] = otherStack.list[j];
}
//constructors
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
   list = NULL;
   copyStack(otherStack);
}
template <class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
   if (this != &otherStack)
       copyStack(otherStack);
   return *this;
}
#endif