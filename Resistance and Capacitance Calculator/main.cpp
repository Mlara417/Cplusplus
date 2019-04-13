#include <iostream>
#include "Filter.h"

using namespace std;
int main()
{
	Filter filterObj;

	double capacitance,capacitorTolerance,resistance,resistorTolerance;
	char *FilterType = new char[2];

	//Displaying Welcome screen to the user
	cout<<"**********************************************************************\n";
	cout<<" Welcome to the Program\n";
	cout<<" Following is the input screen\n";
	cout<<"**********************************************************************\n\n";

	//Getting user inputs
	cout<<"Enter Capacitor Capicitance:";
	cin>>capacitance;
	cout<<"Enter Capacitor Tolernace:";
	cin>>capacitorTolerance;
	cout<<"Enter Resistor Resistance:";
	cin>>resistance;
	cout<<"Enter Resistor Tolerance:";
	cin>>resistorTolerance;
	cout<<"Enter Filter Type (H or L):";
	cin>>FilterType;

	FilterType[0] = toupper(FilterType[0]);
	FilterType[1]= '\0';

	

	
	//Filter type has to be h or l otherwise this loop will continue
	while(strcmp(FilterType,"H")!=0 && strcmp(FilterType,"L")!=0)
	{
		cout<<"Incorrect Filter Type\n";
		cout<<"Enter Filter Type (H or L):";
		cin>>FilterType;
		FilterType[0] = toupper(FilterType[0]);
		FilterType[1]= '\0';



	}

	filterObj.setCapacitor(capacitance,capacitorTolerance); //Setting Capacitor Values
	filterObj.setResistor(resistance,resistorTolerance);	//Setting Resistor Values
	filterObj.CalculateCutOffFreq();						// Calculate Cutoff Frequency
	filterObj.CalculateMaxCutOffFreq();						//Calculate Max CutOff Frequency
	filterObj.CalculateMinCutOffFreq();						//Calculate Min CutOff Frequency

	filterObj.setFilterType(FilterType);
	filterObj.writeFilterToFile();							//Write Values to the file

	cout<<"\nStart showing values from file\n";
	filterObj.ReadFromFile();								//Read Values from the file and Displaying the values on Console
	cout<<"\nEnd showing values from file";


	cout<<"\n**********************************************************************\n";

	char chr;
	cout<<"Press any key to exit";
	cin>>chr;

	return 0;
}