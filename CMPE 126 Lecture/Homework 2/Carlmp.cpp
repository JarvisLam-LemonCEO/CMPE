#include<iostream>
#include "Car.h"
using namespace std;


Car::Car()
{
    make = "";
    year = 1950;
    price = 10;  
}


Car::Car(string make, int year, double price)
{
    this->make = make;
    this->year = year;
    this->price = price;
}

bool Car::operator> (int p)
{
    if (price > p)
    return true;
    return false;
}

bool Car::operator==(const Car& c)
{
    return make == c.make && year == c.year && price == c.price;
}

ostream & operator<<(ostream & osObject, Car & c)
{
    osObject << "Make: " << c.make << "  ";
    osObject << "Year: " << c.year << "  ";
    osObject << "Price: " << c.price<< endl;

    return osObject;
}
