#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

class Rectangle : public BasicShape {
public:
	// constructor with width and length parameters
	Rectangle(long w, long l){
		width = w;
		length = l;
		calcArea();
	}
	
	long getWidth() {
		return width;
	}
	
	long getLength(){
		return length;
	}
	
	void calcArea() {
		double temp = length * width;
		BasicShape::setArea(temp);
	}
	
private:
	// variables
	long width;
	long length;
};

#endif