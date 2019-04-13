#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main()
{
	ComplexNumber c1;	//Instantiating First ComplexNumber Object
	ComplexNumber c2;	//Instantiating Second ComplexNumber Object
	ComplexNumber c3;	//Instantiating Third ComplexNumber Object
	
	cout<<"Welcome to Complex Numbers Program\n\n"; //Welcome screen to the user
	
	cout<<"Enter First Complex Number:-\n"; //Takes user input
	c1.InputComplexNumber();

	cout<<"\nNow Enter Second Complex Number:-\n";
	c2.InputComplexNumber();

	cout<<"\nYou have entered following two complex Numbers:-\n"; //Showing output to the user
	cout<<"\nFirst Complex Number: ";
	c1.PrintComplexNumber();
	cout<<"\nSecond Complex Number: ";
	c2.PrintComplexNumber();
	
	cout<<"\nSum of two Complex Numbers is: ";
	c3=c1+c2;
	c3.PrintComplexNumber();

	cout<<"\nSubtraction of two Complex Numbers is: ";
	c3=c1-c2;
	c3.PrintComplexNumber();

	cout<<"\nMultiplication of two Complex Numbers is: ";
	c3=c1*c2;
	c3.PrintComplexNumber();

	cout<<"\nDivision of two Complex Numbers is: ";
	c3=c1/c2;
	c3.PrintComplexNumber();
	


	char ch;
	cin>>ch;

	
	return 0;
}