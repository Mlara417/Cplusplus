#include "stdafx.h"
#include "SavingsAccount.h"

#include <string>
using namespace std;

class SavingsAccount:public BankAccount 
{
private:
	double dailyInterestRate;
	double AnnualInterestRate;
	int NoOfDaysSinceLastTrans;
	double interestEarned;

public:

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

	void setInterestEarned()
	{
		
		dailyInterestRate = AnnualInterestRate / 365;
		interestEarned = (dailyInterestRate * getAccountBalance()) * getNoOfDaysSinceLastTrans()   ;
	}

	int getNoOfDaysSinceLastTrans()
	{
		NoOfDaysSinceLastTrans = rand()%7;
		return NoOfDaysSinceLastTrans;
	}

	double getInterestEarned()
	{
		return interestEarned;
	}

	double getAccountBalance()
	{
		setInterestEarned();

		setAccountBalance(getAccountBalance() + interestEarned );

		return getAccountBalance();

	}




};