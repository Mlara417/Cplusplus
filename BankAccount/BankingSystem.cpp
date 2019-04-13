#include "stdafx.h"
#include <iostream>
#include "CheckingAndSavingsAccount.cpp"
#include <string>


/************************************
File: BankingSystem.cpp
Main Test Program
Lab: Exercise # 3

************************************/

int _tmain(int argc, _TCHAR* argv[])
{

	CheckingAccount chkAcct("23456",100);	//Checking Account object with Initial Balance of 100$
	SavingsAccount svngsAcct("65432",100);	//Savings Account object with Initial Balance of 100$
	svngsAcct.setAnnualInterestRate(0.03);	//Set interest Rate of 3% to Savings Account
	BankAccount *Account;

	string option;							//Variable that holds user input
	bool transFlag = false;					//Variable that holds outcome of the transaction

	cout<<"******************************************************************\n";
	cout<<"	Welcome to the Banking System\n";
	cout<<"	Here is your Menu\n";
	cout<<"	Enter \"C\" for a transaction in a Checking Account\n";
	cout<<"	Enter \"S\" for a transaction in a Savings Account\n";
	cout<<"	Enter \"E\" to Exit\n";
	cout<<"******************************************************************\n";
	cin>>option;						//Get user Input
	option = toupper(option[0]);		//Convert to upper Case

	//This loop will run until option E is entered
	while (option != "E" )				
	{

		if (option == "C" || option == "c")	//check if option entered is for Checking Account
		{
			Account = &chkAcct;				//Point base class pointer to Checking Account object
		}
		else if  (option == "S" || option == "s")	//check if option entered in Savings Account
		{
			Account = &svngsAcct;			//Point base class pointer to Savings Account object
		}


		if (option == "C" || option == "S")
		{
			//This menu will display the list of available options to carry out transactions

			cout<<"------------------------------------------------------------------\n";
			cout<<"	Enter 1 for a Deposit Transaction\n";
			cout<<"	Enter 2 for a Winthdrawal Transaction\n";
			cout<<"	Enter 3 for a Balance Enquiry\n";
			cout<<"	Enter any other key to return to main menu\n";
			cout<<"------------------------------------------------------------------\n";

			cin>>option;
			transFlag = false;

			if(option == "1")
			{
				double Amount;
				cout<<"Enter Deposit Amount:";
				cin>>Amount;

				Account->DepositMoney(Amount);			//Call Deposit Money Function
				transFlag=true;

			}
			else if (option =="2")
			{
				double Amount;
				cout<<"Enter Withdrawal Amount:";		//Call Withdrawal function
				cin>>Amount;

				transFlag=Account->WithdrawMoney(Amount);


			}
			else if (option == "3")
			{

				Account->BalanceEnquiry();				//Call BalanceEnquiry Function
				transFlag=true;
			}

			if (transFlag)
			{
				cout<< "Transaction completed Successfully - Here are the details:\n";
				cout<<"Account Number:"<<Account->getAccountNumber()<<"\n";
				cout<<"Account Type:"<<Account->getAccountType()<<"\n";
				cout<< "Account Balance:"<<Account->getAccountBalance()<<"\n";

				if (Account->getAccountType() == "Checking Account")
					cout<<"Fees Charged:"<<chkAcct.getFeesCharged()<<"\n\n"; //this will be displayed only for Checking Account
				else
				{
					// Interest Earned and No of Days Since last transaction should be displayed for Savings Account only
					cout<<"Interest Earned:"<<svngsAcct.getInterestEarned()<<"\n";
					cout<< "No. of Days Since Last Transaction:"<<svngsAcct.getNoOfDaysSinceLastTrans()<<"\n\n";

				}

			}
			else
				cout<< "Sorry - Your transaction could not be completed\n";


		}

		//Display user menu again
		cout<<"******************************************************************\n";
		cout<<"	Welcome to the Banking System\n";
		cout<<"	Here is your Menu\n";
		cout<<"	Enter \"C\" for a transaction in a Checking Account\n";
		cout<<"	Enter \"S\" for a transaction in a Savings Account\n";
		cout<<"	Enter \"E\" to Exit\n";
		cout<<"******************************************************************\n";
		cin>>option;
		option = toupper(option[0]);

	}

	return 0;
}