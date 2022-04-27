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
	// consturctor with int parameter
	Circle(double radius2){
		radius = radius2;
	}
	
	// calculate the area 
	void calculate(){
		area = M_PI * pow(radius, 2); // M_PI is the Pi constant from cmath library
	}
	
	// show the result to screen
	void display(){
		cout << "The area of the circle with radius " << radius << " is " << area << endl; 
	}
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

/*
	The output of the program 

	Enter the radius of a circle: 32.5
	The area of the circle with radius 32.5 is 3318.31
*/