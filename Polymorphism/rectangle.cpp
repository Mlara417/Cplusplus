#include "Rectangle.h"
#include <iostream>
using namespace std;
	Rectangle::Rectangle(int l,int w)										//Constructor for rectangle
	{
		length = l;
		width =w;
	}

	void Rectangle::setDimensions(int l,int w)
	{
		length = l;
		width =w;
	}

	double Rectangle::getLength()
	{
		return length;
	}

	double Rectangle::getWidth()
	{
		return width;
	}
	
	double Rectangle::area()													//Area function for rectangle
	{
		return length * width;
	}
	
	double Rectangle::perimeter()												//perimeter function for rectangle
	{
		return 2 * (length + width);										
	}
	
	void Rectangle::display()													//Display function for rectangle.
	{
		cout<<"\n------------------------------\n";
		cout<<"Rectangle Display Function:\n";
		cout<<"Dimensions: "<<length<<" X "<<width<<"\n";
		cout<<"Area: "<<area()<<"\t";
		cout<<"Perimeter: "<<perimeter();
		cout<<"\n------------------------------\n";
	}