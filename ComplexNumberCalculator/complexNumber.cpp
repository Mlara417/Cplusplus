#include <iostream>
#include "ComplexNumber.h"
using namespace std;
ComplexNumber::ComplexNumber(double p_r,double p_imag) //Constructor
	{
		realPart = p_r;
		imaginaryPart = p_imag;
	}

	ComplexNumber::ComplexNumber(const ComplexNumber& p_comp) //Copy Constructor
	{
		realPart = p_comp.realPart;
		imaginaryPart = p_comp.imaginaryPart;
	}

	ComplexNumber	ComplexNumber::operator+(const ComplexNumber& p_num1) //+ operator Overloading
	{
		ComplexNumber tempObj;

		tempObj.realPart = realPart + p_num1.realPart ;
		tempObj.imaginaryPart = imaginaryPart + p_num1.imaginaryPart;

		return tempObj;
	}


	ComplexNumber	ComplexNumber::operator-(const ComplexNumber& p_num1) //-Operator Overloading
	{
		ComplexNumber tempObj;

		tempObj.realPart = realPart - p_num1.realPart ;
		tempObj.imaginaryPart = imaginaryPart - p_num1.imaginaryPart;

		return tempObj;
	}

	ComplexNumber	ComplexNumber::operator*(const ComplexNumber& p_num1) //* Operator Overloading
	{
		ComplexNumber tempObj;

		tempObj.realPart = realPart * p_num1.realPart - imaginaryPart * p_num1.imaginaryPart ;
		tempObj.imaginaryPart = realPart * p_num1.imaginaryPart + imaginaryPart * p_num1.realPart  ;

		return tempObj;
	}


	ComplexNumber	ComplexNumber::operator/(const ComplexNumber& p_num1) // '/' Operator Overloading
	{
		ComplexNumber tempObj;

		tempObj.realPart = (realPart * p_num1.realPart + imaginaryPart * p_num1.imaginaryPart)/ (p_num1.realPart * p_num1.realPart + p_num1.imaginaryPart * p_num1.imaginaryPart) ;
		tempObj.imaginaryPart = (imaginaryPart * p_num1.realPart  -  realPart  * p_num1.imaginaryPart)/(p_num1.realPart * p_num1.realPart + p_num1.imaginaryPart * p_num1.imaginaryPart);

		return tempObj;
	}

	const ComplexNumber& ComplexNumber::operator=(const ComplexNumber& p_num1) // '=' Operator Overloading
	{
		
		realPart =p_num1.realPart ;
		imaginaryPart = p_num1.imaginaryPart ;

		return *this;
	}


	void ComplexNumber::PrintComplexNumber() //Output Complex Number Object
	{
		cout<<realPart<<"+("<<imaginaryPart<<"i)\n"; 
	}

	void ComplexNumber::InputComplexNumber() //Takes input of Complex Number Object members.
	{
		cout<<"\nEnter Real Part:";
		cin>>realPart;
		cout<<"\nEnter Imaginary Part:";
		cin>>imaginaryPart; 
	}


	ComplexNumber::~ComplexNumber() //Destructor
	{
	}