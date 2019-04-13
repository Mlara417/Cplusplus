#pragma once

class Capacitor
{
private:
	double nominal_capacitance; //Nominal Capacitance
	double tolerance; //Tolerance
	

public:
Capacitor(double p_cap=0,double p_tol=0);
void setNominalCapacitance(double p_cap);
void setTolerance(double p_tol);
double getNominalCapacitance();
double getTolerance();
double getMinToleranceCapacitance();
double getMaxToleranceCapacitance();
~Capacitor();
};
