#ifndef Car_h
#define Car_h
#include<iostream>

using namespace std;

class Car
{
private:
    string make;
    int year;
    double price;
    
public:
    Car();
    Car(string, int, double);
    bool operator> (int);


    double operator+(Car c){
        return price + c.price;
    }

    bool operator==(const Car& c);

    friend ostream & operator<<(ostream & osObject, Car & c);
};

#endif /* Car_h */