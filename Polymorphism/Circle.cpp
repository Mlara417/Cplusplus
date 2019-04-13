#pragma once
#include "Circle.h"
#include <iostream>

using namespace std;

	Circle::Circle(int p_r)							//Constructor for Circle class
	{
		radius=p_r;
	}

	double Circle::getRadius()							
	{
		return radius;
	}
	void Circle::setRadius(int p_r)
	{
		radius = p_r;
	}

	double Circle::area()										//Circle area() function
	{
		return (3.142857*radius*radius);				//area = pi * r^2
	}

	double Circle::perimeter()
	{
		return (2*3.142857*radius);
	}

	void Circle::display()												//Circle Display Function
	{
		cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout<<"Circle Display Function:\n";
		cout<<"Radius: "<<radius<<"\n";
		cout<<"Area: "<<area()<<"\t";
		cout<<"Circumference: "<<perimeter();
		cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	}
