#pragma once
#include "Shape.h"


class Rectangle:public Shape
{
private:
	double length;													//Length Data member
	double width;													//Width Data member
public:
	Rectangle(int l=0,int w=0);										//Constructor for rectangle
	void setDimensions(int l,int w);
	double getLength();
	double getWidth();
	double area();													//Area function for rectangle
	double perimeter();												//perimeter function for rectangle
	void display();													//Display function for rectangle.
};