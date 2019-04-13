#include "Capacitor.h"
#include <string>

using namespace std;


//Constructor
Capacitor::Capacitor(double p_cap,double p_tol)
{
	this->nominal_capacitance = p_cap;
	this->tolerance=p_tol;
}

//Getters and Setters
void Capacitor::setNominalCapacitance(double p_cap)
{
	this->nominal_capacitance=p_cap;
}

void Capacitor::setTolerance(double p_tol)
{
	this->tolerance=p_tol;
}


double Capacitor::getNominalCapacitance()
{
	return this->nominal_capacitance;
}

double Capacitor::getTolerance()
{
	return this->tolerance;
}

//Get min Tolerance
double Capacitor::getMinToleranceCapacitance()
{
	return nominal_capacitance - tolerance;
}
	
//Get Max Tolerance
double Capacitor::getMaxToleranceCapacitance()
{
	return nominal_capacitance+tolerance;
}

Capacitor::~Capacitor()
{
}