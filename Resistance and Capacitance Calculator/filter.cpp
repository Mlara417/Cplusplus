#include <string>
#include <iostream>
#include <fstream>
#include "Capacitor.h"
#include "Resistor.h"
#include "Filter.h"
#include <cmath>
#include <iomanip>

using namespace std;

	Filter::Filter() //Constructor
	{

		cutoffFreq=0;
		maxCutOffFreq=0;
		minCutOffFreq=0;
		this->filterType = new char[2];

	}
	
	void Filter::setCapacitor(double p_cap,double p_tol) //Set Capacitor Data members
	{
		cap.setNominalCapacitance(p_cap);
		cap.setTolerance(p_tol);
	}

	Capacitor Filter::getCapacitor()
	{
		return cap;
	}
	
	void Filter::setResistor(double p_res,double p_tol) //Set resistor Data members
	{
		res.setNominalResistance(p_res);
		res.setTolerance(p_tol);
	}
	
	Resistor Filter::getResistor()
	{
		return res;
	}
	void Filter::CalculateCutOffFreq() //Calculate Cut off frequency from nominal capicitance and resistance
	{
		cutoffFreq = 1/(2*3.14*cap.getNominalCapacitance()*res.getNominalResistance());
	}
	void Filter::CalculateMaxCutOffFreq() //Calculate max Cut off frequency from max tolerance
	{
		maxCutOffFreq = 1/(2*3.14*cap.getMaxToleranceCapacitance()*res.getMaxToleranceresistance()) ;
		
	}
	
	void Filter::CalculateMinCutOffFreq() //Calculate min Cut off frequency from min tolerance
	{
		minCutOffFreq = 1/(2*3.14*cap.getMinToleranceCapacitance()*res.getMinToleranceresistance()) ;
	}
	
	void Filter::setFilterType(char* p_type)
	{
		filterType = p_type;

	}
	
	void Filter::writeFilterToFile() //Write all values to a file
	{
		cout<<"Enter Filename:";
		char filename[100];
		cin>>filename;
		cout<<"Adding values to File\n\n";
		ofstream fout;
		fout.open(filename);
		fout<<"Capacitor Capicitance:"<<cap.getNominalCapacitance()<<" farad";
		fout<<"\nCapacitor Tolerance:"<<cap.getTolerance()<<" farad";
		fout<<"\nCapacitor Max Tolerance Capicitance:"<<cap.getMaxToleranceCapacitance()<<" farad";
		fout<<"\nCapacitor Min Tolerance Capicitance:"<<cap.getMinToleranceCapacitance()<<" farad";
		fout<<"\n\nResistor Resistance:"<<res.getNominalResistance()<<" ohm";
		fout<<"\nResistor Tolerance:"<<res.getTolerance()<<" ohm";
		fout<<"\nResistor Max Tolerance Resistance:"<<res.getMaxToleranceresistance()<<" ohm";
		fout<<"\nResistor Min Tolerance Resistance:"<<res.getMinToleranceresistance()<<" ohm";
		fout<<"\n\nFilter Type:"<<filterType ;
		fout<<"\nFilter Cutoff Frequency:"<<cutoffFreq<< " Hertz";
		fout<<"\nFilter Max Cutoff Frequency:"<<setprecision(3)<<maxCutOffFreq << " Hertz";
		fout<<"\nFilter Min Cutoff Frequency:"<<setprecision(3)<<minCutOffFreq<<" Hertz\n";
		fout.close();

	}

	void Filter::ReadFromFile() //read data from the file and display on console
	{
		cout<<"Enter Filename to read values from:";
		char filename[100];
		cin>>filename;
		ifstream fin;
		fin.open(filename);
		if(!fin) //Check if file exists
		{
			cout<<"The specified File is not found\n";
			return;
		}

		while(!fin.eof()) //Loop to check end of file
		{
			string text;
			getline(fin,text);
			cout<<"\n"<<text;
		}
		cout<<"\n";

		fin.close();

	}
	char* Filter::getFilterType()
	{
		return filterType;
	}