#include "Resistor.h"
#include <string>
using namespace std;

//Constructor
Resistor::Resistor(double p_cap,double p_tol)
{
	this->nominal_resistance = p_cap;
	this->tolerance=p_tol;
}

//Getters and setters

void Resistor::setNominalResistance(double p_cap)
{
	this->nominal_resistance=p_cap;
}

void Resistor::setTolerance(double p_tol)
{
	this->tolerance=p_tol;
}


double Resistor::getNominalResistance()
{
	return this->nominal_resistance;
}

double Resistor::getTolerance()
{
	return this->tolerance;
}


//Get Min Tolerance Resistance
double Resistor::getMinToleranceresistance()
{
	return nominal_resistance - tolerance;
}

//Get max Tolerance Resistance
	
double Resistor::getMaxToleranceresistance()
{
	return nominal_resistance+tolerance;
}

Resistor::~Resistor()
{
}