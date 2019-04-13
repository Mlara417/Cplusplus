#pragma once

#include "Capacitor.h"
#include "Resistor.h"
using namespace std;
class Filter
{
private:
	Capacitor cap; //Capacitor Object
	Resistor res;  //Resistor Object
	double cutoffFreq;	//CutOff frequency
	double maxCutOffFreq;	//Max CutOff Frequency
	double minCutOffFreq;	//Min Cut Off Frequency
	char* filterType;

public:
	Filter(); //Constructor
	void setCapacitor(double p_cap,double p_tol);//Set Capacitor Data members
	Capacitor getCapacitor();
	void setResistor(double p_res,double p_tol); //Set resistor Data members
	Resistor getResistor();
	void CalculateCutOffFreq(); //Calculate Cut off frequency from nominal capicitance and resistance
	void CalculateMaxCutOffFreq(); //Calculate max Cut off frequency from max tolerance
	void CalculateMinCutOffFreq(); //Calculate min Cut off frequency from min tolerance
	void setFilterType(char* p_type);
	void writeFilterToFile(); //Write all values to a file
	void ReadFromFile(); //read data from the file and display on console
	char* getFilterType();
};