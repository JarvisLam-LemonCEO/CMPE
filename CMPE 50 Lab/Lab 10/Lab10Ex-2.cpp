#include <iostream>
#include "figure.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

void myDraw(Figure *fig)
{
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();	
}

int main(){
	Figure *fig;
	Triangle *tri = new Triangle;
	
	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();
	
	myDraw(tri);
	
	Circle *cir = new Circle;
	fig = cir;
	fig->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	fig->center();
	
	myDraw(cir);
	
	return 0;
	
}


/*
Triangle::draw()

Derived class Triangle object calling center(). 
Triangle::erase()
Triangle::draw()
Triangle::draw()

myDraw: Derived class object calling center(). 
Triangle::erase()
Triangle::draw()
Circle::draw()

Derived class Circle object calling center(). 
Circle::erase()
Circle::draw()
Circle::draw()

myDraw: Derived class object calling center(). 
Circle::erase()
Circle::draw()


*/