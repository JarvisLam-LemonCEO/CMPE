#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;
int main(int argc, char *argv[]) {
	// variables
	long x;
	long y;
	long length;
	long width;
	double radius;
	
	// Circle
	cout << "X coordinate of the circle's center: "; 
	cin >> x;
	cout << "Y coordinate of the circle's center: ";
	cin >> y;
	cout << "Radius of circle: ";
	cin >> radius;
	
	// Call circle object function
	Circle circle(x,y,radius);
	cout << "The area of the circle is " << circle.getArea() << endl;
	
	// Rectangle
	cout << "Length of the rectangle: ";
	cin >> length;
	cout << "Width of the rectangle: ";
	cin >> width;
	
	// Call rectangle object function
	Rectangle rectangle(width, length);
	cout << "The area of the rectangle is " << rectangle.getArea() << endl;
	
	return 0;
	
}