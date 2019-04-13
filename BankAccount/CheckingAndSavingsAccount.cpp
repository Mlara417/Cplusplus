#include "stdafx.h"
#include <string>
using namespace std;
#include "BankAccount.cpp"


/************************************
File: CheckingAndSavingsAccount.cpp
CheckingAccount Class Definition
Lab: Exercie # 3

************************************/
class CheckingAccount:public BankAccount
{
private:
	int NoOfWithdrawalTrans;
	double feesCharged;

public:

/*
Constructor for CheckingAccount Class.
*/

	CheckingAccount(string p_acctNumber = "",double p_bal = 0):BankAccount(p_acctNumber,p_bal) 
	{
		
		
		NoOfWithdrawalTrans=0;
		feesCharged=0;
	}
	
	
	int getNoOfWithdrawalTrans()
	{
		return NoOfWithdrawalTrans;
	}

bool WithdrawMoney(double p_Amt) //Overridden base class function
	{
		NoOfWithdrawalTrans++;

		if (p_Amt <=0) return false;

		if (NoOfWithdrawalTrans <=3)	//Check No of transactions
		{
			if (p_Amt <= BankAccount::getAccountBalance())
			{
				setAccountBalance(getAccountBalance()-p_Amt);
				feesCharged=0;

			return true;
			}
			else 
				return false;
		}
		else
		{
			if ((p_Amt+0.5) <=getAccountBalance())				//Check if amount can be withdrawn or not
			{
				setAccountBalance(getAccountBalance()-(p_Amt+0.5)); //deduction of 5 cents from the avaiable balance
				feesCharged=0.5;

			return true;
			}
			else 
				return false;


		}
	}

double getFeesCharged()
{
	return feesCharged;
}

string getAccountType()
	{
		return "Checking Account";
	}


};


/************************************
File: CheckingAndSavingsAccount.cpp
SavingsAccount Class Definition
Lab: Exercie # 3

************************************/

class SavingsAccount:public BankAccount 
{
private:
	double dailyInterestRate;
	double AnnualInterestRate;
	int NoOfDaysSinceLastTrans;
	double interestEarned;

	//Private method since it is not required outside the scope of class
	void setInterestEarned()
	{
		NoOfDaysSinceLastTrans = rand()%7;	//call randon number
		dailyInterestRate = AnnualInterestRate / 365;	//Divide Annual Interest by 365
		interestEarned = (dailyInterestRate * getAccountBalance()) * getNoOfDaysSinceLastTrans()   ; //Calculate total interest Since the last transaction
	}

public:

	//SavingsAccount Constructor - Base class constructor called here
	SavingsAccount(string p_acctNumber = "",double p_bal = 0):BankAccount(p_acctNumber,p_bal) 
	{
		
		NoOfDaysSinceLastTrans=0;
		dailyInterestRate=0;
		AnnualInterestRate=0;
		interestEarned=0;
	}
	

	void setAnnualInterestRate(double p_rate)
	{
		AnnualInterestRate = p_rate;

	}

	

	int getNoOfDaysSinceLastTrans()
	{
		
		return NoOfDaysSinceLastTrans;
	}

	double getInterestEarned()
	{
		return interestEarned;
	}

	double BalanceEnquiry() //Overriddent balance enquiry function
	{
		setInterestEarned();

		setAccountBalance(getAccountBalance() + interestEarned ); //Add interest earned to the balance

		return getAccountBalance();
	}


	string getAccountType()
	{
		return "Savings Account";
	}



};