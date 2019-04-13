#pragma once

class Resistor
{
private:
	double nominal_resistance; //Nominal Resistance
	double tolerance; //Resistor Tolerance
	
public:
	Resistor(double p_cap=0,double p_tol=0);
	void setNominalResistance(double p_cap);
	void setTolerance(double p_tol);
	double getNominalResistance();
	double getTolerance();
	double getMinToleranceresistance();
	double getMaxToleranceresistance();
	~Resistor();
};