#include <iostream>
#include "figure.h"
using namespace std;


void Figure::erase()
{

	cout << "Figure::erase()" << endl;
}
void Figure::draw()
{

	cout << "Figure::draw()" << endl;
}

void Figure::center()
{
	erase();
	draw();
}