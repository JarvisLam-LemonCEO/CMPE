#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape {
public:
	double getArea(){
		return area;
	}
	
	virtual void calcArea() = 0;
	
	void setArea(double a){
		area = a;
	}
private:
	// variable
	double area;
};

#endif