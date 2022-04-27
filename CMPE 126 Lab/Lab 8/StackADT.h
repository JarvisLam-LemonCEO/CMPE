// Header files section
#ifndef H_StackADT
#define H_StackADT

//define stackADT template class
template <class Type>
class stackADT
{
public:
   //define pure virtual functions.
   virtual void initializeStack() = 0;
   virtual bool isEmptyStack() const = 0;
   virtual bool isFullStack() const = 0;
   virtual void push(const Type& newItem) = 0;
   virtual Type top() const = 0;
   virtual void pop() = 0;
};
#endif