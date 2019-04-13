#pragma once
class Shape
{
public:
	Shape();									//Constructor
	virtual double area()=0;					//total virtual function making the class abstract
	virtual double permimeter();		//virtual function of permieter()
	virtual void display();					//virtual display function
	
};
