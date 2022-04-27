#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"
class Circle : public BasicShape{
public:
	// constructor with x, y and radius parameters
	Circle(long x, long y, double rad){
		centerX = x;
		centerY = y;
		radius = rad;
		calcArea();
	}
	
	long getCenterX() {
		return centerX;
	}
	
	long getCenterY() {
		return centerY;
	}
	
	void calcArea() {
		double temp = 3.14159 * radius * radius;
		BasicShape::setArea(temp);
	}
	
	double getArea() {
		return BasicShape::getArea();
	}
	
private:
	// variables
	long centerX;
	long centerY;
	double radius;
};
#endif