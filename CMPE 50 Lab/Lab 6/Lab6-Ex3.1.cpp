#include <iostream>
#include <cmath>
using namespace std;

// circle class
class Circle{
private:
	// private variable
	double radius;
	double area;
	
public:
	// declare member functions
	Circle(double radius2);
	void calculate();
	void display();
};

int main(int argc, char *argv[]) {
	double radius;
	cout << "Enter the radius of a circle: ";
	cin >> radius;
	
	// create a circle object
	Circle cir(radius);
	cir.calculate(); // call the calculate()
	cir.display(); // call the display()
	
	return 0;
}

// Constrctor with double parameter
Circle::Circle(double radius2){
	radius = radius2;
}

// calculate the area 
void Circle::calculate(){
	area = M_PI * pow(radius, 2); // M_PI is the Pi constant from cmath library
}

// show the result to screen
void Circle::display(){
	cout << "The area of the circle with radius " << radius << " is " << area << endl; 
}