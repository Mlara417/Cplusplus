#include "Resistor.h"
#include <iostream>
using namespace std;

//Constructor
Resistor::Resistor(double p_res,double p_tol,char *p_name,bool bDisplay)
{
	
	this->nominal_resistance = p_res;
	this->tolerance=p_tol;
	this->ResistorName = p_name;
	
	if (bDisplay)
		cout<<"***\tFunction called:Resistor Constructor\n";
}

//Getters and setters

void Resistor::setResistorName(char *p_name,bool bDisplay)
{
	this->ResistorName = p_name;
	if (bDisplay)
		cout<<"***\tFunction called:setResistorName\n";
}

char* Resistor::getResistorName(bool bDisplay)
{
	if (bDisplay)
		cout<<"***\tFunction called:getResistorName\n";

	return this->ResistorName;
}
	
void Resistor::setNominalResistance(double p_res,bool bDisplay)
{

	this->nominal_resistance=p_res;

	
	if (bDisplay)
		cout<<"***\tFunction called:setNominalResistance()\n";
}

void Resistor::setTolerance(double p_tol,bool bDisplay)
{
	this->tolerance=p_tol/100.0;
	
	if (bDisplay)
		cout<<"***\tFunction called:setTolerance()\n";
}


double Resistor::getNominalResistance(bool bDisplay)
{
	
	if (bDisplay)
		cout<<"***\tFunction called:getNominalResistance()\n";

	return this->nominal_resistance;
	
}

double Resistor::getTolerance(bool bDisplay)
{
	
	if (bDisplay)
		cout<<"***\tFunction called:getTolerance()\n";

	return this->tolerance*100;
	
}


//Get Min Tolerance Resistance
double Resistor::getMinToleranceResistance(bool bDisplay)
{
	if (bDisplay)
		cout<<"***\tFunction called:getMinToleranceResistance()\n";

	return nominal_resistance - (tolerance*nominal_resistance);
	
	
}

//Get max Tolerance Resistance
	
double Resistor::getMaxToleranceResistance(bool bDisplay)
{
	if (bDisplay)
		cout<<"***\tFunction called:getMaxToleranceResistance()\n";
	return nominal_resistance+(tolerance*nominal_resistance);
	
	
}

void Resistor::displayResistor(bool bDisplay)
{
	if (bDisplay)
		cout<<"***\tFunction called:displayResistor()\n";

	cout<<"Nominal Resistance:"<<nominal_resistance<<endl;
	cout<<"Tolerance:"<<tolerance<<endl;
	cout<<"Maximum Tolerance Resistance:"<<getMaxToleranceResistance(bDisplay)<<endl;
	cout<<"Minimum Tolerance Resistance:"<<getMinToleranceResistance(bDisplay)<<endl<<endl;
	
	
}
	

Resistor::~Resistor()
{
}
//};