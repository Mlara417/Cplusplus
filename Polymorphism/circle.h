#pragma once
#include "Shape.h"

class Circle:public Shape						//Circle Class inherits Shape class publically
{
private:
	double radius;								//radius data member
public:
	Circle(int p_r=0);							//Constructor for Circle class
	double getRadius();							
	void setRadius(int p_r);
	double area();										//Circle area() function
	double perimeter();
	void display();												//Circle Display Function
	
};
