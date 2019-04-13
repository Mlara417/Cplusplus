#pragma once
class ComplexNumber
{
private:
	double realPart; //Real Part of Complex Number
	double imaginaryPart; //Imaginary Part of Complex Number

public:
	ComplexNumber(double p_r = 0.0,double p_imag = 0.0); //Constructor
	ComplexNumber(const ComplexNumber& p_comp); //Copy Constructor
	ComplexNumber	operator+(const ComplexNumber& p_num1); //+ operator Overloading
	ComplexNumber	operator-(const ComplexNumber& p_num1); //-Operator Overloading
	ComplexNumber	operator*(const ComplexNumber& p_num1); //* Operator Overloading
	ComplexNumber	operator/(const ComplexNumber& p_num1); // '/' Operator Overloading
	const ComplexNumber& operator=(const ComplexNumber& p_num1); // '=' Operator Overloading
	void PrintComplexNumber(); //Output Complex Number Object
	void InputComplexNumber(); //Takes input of Complex Number Object members.
	~ComplexNumber(); //Destructor
};