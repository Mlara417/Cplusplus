#pragma once
class Resistor
{
private:
	char *ResistorName;
	double nominal_resistance;
	double tolerance;
	
public:

	Resistor(double p_res=0,double p_tol=0,char* p_name="",bool bDisplay=false);
	void setNominalResistance(double p_res,bool bDisplay=false);
	void setResistorName(char *p_name,bool bDisplay=false);
	void setTolerance(double p_tol,bool bDisplay=false);
	double getMinToleranceResistance(bool bDisplay=false);
	double getMaxToleranceResistance(bool bDisplay=false);
	double getNominalResistance(bool bDisplay=false);
	double getTolerance(bool bDisplay=false);
	char* getResistorName(bool bDisplay=false);	
	void displayResistor(bool bDisplay = false);
	~Resistor();

};