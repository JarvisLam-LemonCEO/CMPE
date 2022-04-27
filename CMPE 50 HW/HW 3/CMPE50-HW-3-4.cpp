#include<iostream>
using namespace std;

class Duple
{
public:
   // declare member functions
   Duple();
   Duple(int first, int second);
   friend istream& operator >>(istream &ins, Duple &second);
   friend ostream& operator <<(ostream &outs, Duple &second);
   Duple operator + (Duple& oth);
   Duple operator - (Duple& oth);
private:
   int f;
   int s;
};

int main()
{
   Duple x;
   Duple y;
   
   // read the input
   cin >> x >> y;
   
   // disply to screen
   cout << x << y;

   Duple z = x + y;
   cout<<z;
   Duple a = x - y;
   cout<<a;
}

// default constructor
Duple::Duple(){

}

// constructor with two int parameters
Duple::Duple(int first, int second){
   f = first;
   s = second;
}

// input function 
istream& operator >>(istream &ins, Duple &second){
   ins >> second.f >> second.s; // the input from f and s
   return ins;
}

// output function
ostream& operator <<(ostream &outs, Duple &second){
   outs << "(" << second.f << ", " << second.s << ")" << endl; // show f and s to the screen
   return outs;
}

Duple Duple::operator + (Duple& oth){
   return * (new Duple (this->f + oth.f, this->s + oth.s)); // add the two duples 
}

Duple Duple::operator - (Duple& oth){
   return * (new Duple (this->f - oth.f, this->s - oth.s)); // subtract the two duples 
}


/*
   The output of the program

   2 4
   1 4
   (2, 4)
   (1, 4)
   (3, 8)
   (1, 0)
*/