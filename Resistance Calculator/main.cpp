#include "Resistor.h"
#include <math.h>

#include <iostream>

using namespace std;

const int E12 = 12;
const int E24 = 24;
const int E48 = 48;
const int E96 = 96;

const int nominalE12Values[E12] = {100,120,150,180,220,270,330,390,470,560,680,820};
const int nominalE24Values[E24] = {100,110,120,130,150,160,180,200,220,240,
								   270,300,330,360,390,430,470,510,560,620,
								   680,750,820,910};
const int nominalE48Values[E48] = {100,105,110,115,121,127,133,140,147,154,
								   162,169,178,187,196,205,215,226,237,249,
								   261,274,287,301,316,332,348,365,383,402,
								   422,442,464,487,511,536,562,590,619,649,
								   681,715,750,787,825,866,909,953,};
const int nominalE96Values[E96] = {100,102,105,107,110,113,115,118,121,124,
								   127,130,133,137,140,143,147,150,154,158,
								   162,165,169,174,178,182,187,191,196,200,
								   205,210,215,221,226,232,237,243,249,255,
								   261,267,274,280,287,294,301,309,316,324,
								   332,340,348,357,365,374,383,392,402,412,
								   422,432,442,453,464,475,487,499,511,523,
								   536,549,562,576,590,604,619,634,649,665,
								   681,698,715,732,750,768,787,806,825,845,
								   866,887,909,931,953,976};


bool Validate(int value,int allowedValues[], int size)
{
	for (int i=0; i<size;++i)
	{
		if(value == allowedValues[i])
		{
			return true;
		}
	}
	return false;
}



void GetUserInputsForResistor(Resistor &p_rObj,bool bDisplay=false)
{

	double nominalResistance=0,tolerance=0;
	cout<<"Resistor being edited:" <<p_rObj.getResistorName()<<endl<<endl;
	cout<<"\n\nCurrent resistance tolerance = "<<p_rObj.getTolerance(bDisplay)<<"%"<<endl;
	cout<<"Valid tolerances are 1%, 2%, 5% or 10%\n";
	do{
	cout<<"\nEnter 1,2,5 or 10:";
	cin>>tolerance;
	}while(tolerance!=1 && tolerance != 2 && tolerance != 5 && tolerance != 10);

	cout<<"\nCurrent nominal Resistance = "<<p_rObj.getNominalResistance(bDisplay)<<" ohms"<<endl;
	
	int iEIA = 0;
	int *iEIAValues;

	if(tolerance == 1)
	{
		iEIA = E96;	
		iEIAValues = new int[96];
		for(int i =0;i<iEIA;++i)
			iEIAValues[i] = nominalE96Values[i];

	}
	else if (tolerance == 2)
	{
		iEIA = E48;
		iEIAValues = new int[48];
		for(int i =0;i<iEIA;++i)
			iEIAValues[i] = nominalE48Values[i];
	}
	else if (tolerance == 5)
	{
		iEIA = E24;
		iEIAValues = new int[24];
		for(int i =0;i<iEIA;++i)
			iEIAValues[i] = nominalE24Values[i];
	}
	else 
	{
		iEIA = E12;
		iEIAValues = new int[12];
		for(int i =0;i<iEIA;++i)
			iEIAValues[i] = nominalE12Values[i];
	}

	

	do{
		cout<<"\nStandard "<<tolerance<<"% Resistance values, First three Digits"<<endl<<endl;
		for (int i=0; i<iEIA;++i)
		{
			cout<<iEIAValues[i]<<"\t";
			if((i+1)%10 == 0 )
			{
				cout<<endl;
			}
		}
		cout<<endl<<endl;
		
		cout<<"\nEnter first three digits: ";
		cin>>nominalResistance;
		cout<<"You entered "<<nominalResistance;
		}while(!Validate(nominalResistance,iEIAValues,iEIA));
		
	cout<<"\nValid EIA value entered\n\n";

	int multiplier;
	
	do{
	cout<<"Enter a power of 10 multiplier between -2(0.01) and 3(1000):";
	cin>>multiplier;
	}while(!(multiplier>=-2 && multiplier<=3));

	cout<<"You entered "<<multiplier<<endl<<endl;
	pow(10.0,multiplier);
	p_rObj.setNominalResistance(nominalResistance*pow(10.0,multiplier),bDisplay);
	p_rObj.setTolerance(tolerance,bDisplay);


}

void main()
{

	//Execution with the test messages displayed
	bool fnDisp = true;
	Resistor r1(4700.0,0.10,"Res1",fnDisp);
	Resistor r2(330.0,0.05,"Res2",fnDisp);
	

	cout<<"***\t*******************************\t***\n";
	cout<<"***\tWelcome to the Resistor Program\t***\n";
	cout<<"***\tFirst the program will be executed ***\n***\twith test messages displayed\n";
	cout<<"***\t*******************************\t***\n";


	cout<<"--------------------------------------\n";
	cout<<"Getting input for Resistor1"<<endl;
	GetUserInputsForResistor(r1,fnDisp);
	cout<<"--------------------------------------\n\n";
	
	cout<<"--------------------------------------\n";
	cout<<"Resistor Object Name is "<<r1.getResistorName(fnDisp)<<"\n";	
	r1.displayResistor(fnDisp);
	cout<<"--------------------------------------\n\n";

	cout<<"--------------------------------------\n";
	cout<<"\nGetting input for Resistor2"<<endl;
	GetUserInputsForResistor(r2,fnDisp);
	cout<<"--------------------------------------\n\n";
	
	
	cout<<"--------------------------------------\n";
	cout<<"Resistor Object Name is "<<r2.getResistorName(fnDisp)<<"\n";	
	r2.displayResistor(fnDisp);
	cout<<"--------------------------------------\n\n";

	char chr;
	
	cout<<"Enter any key to run the program without the test messages:";
	cin>>chr;
	//Execution without the test messages displayed
	cout<<"***\t*******************************\t***\n";
	cout<<"***\tNow the program will be executed ***\n***\twithout test messages displayed\n";
	cout<<"***\t*******************************\t***\n";

	fnDisp=false;
	cout<<"--------------------------------------\n";
	cout<<"Getting input for Resistor1"<<endl;
	GetUserInputsForResistor(r1,fnDisp);
	cout<<"--------------------------------------\n\n";
	
	cout<<"--------------------------------------\n";
	cout<<"Resistor Object Name is "<<r1.getResistorName(fnDisp)<<"\n";	
	r1.displayResistor(fnDisp);
	cout<<"--------------------------------------\n\n";

	cout<<"--------------------------------------\n";
	cout<<"\nGetting input for Resistor2"<<endl;
	GetUserInputsForResistor(r2,fnDisp);
	cout<<"--------------------------------------\n\n";
	
	
	cout<<"--------------------------------------\n";
	cout<<"Resistor Object Name is "<<r2.getResistorName(fnDisp)<<"\n";	
	r2.displayResistor(fnDisp);
	cout<<"--------------------------------------\n\n";

	
	
	cin>>chr;
}