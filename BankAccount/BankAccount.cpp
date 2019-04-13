#include "stdafx.h"
#include <string>
using namespace std;



class BankAccount
{
private:
	string AccountNumber;	//Holds Account Number
	
	double AccountBalance;	//Holds Account Balance
	
public:
	BankAccount(string p_acctNumber = "",double p_bal = 0) //Constructor
	{
		AccountNumber = p_acctNumber;
		AccountBalance = p_bal;

	}

	void setAccountNumber(string p_acctNumber)
	{
		AccountNumber = p_acctNumber;
	}

	string getAccountNumber()
	{
		return AccountNumber;
	}

	void setAccountBalance(double p_bal)
	{
		AccountBalance = p_bal;
	}

	double getAccountBalance()
	{
		return AccountBalance;
	}

	virtual double BalanceEnquiry()
	{
		return AccountBalance;

	}
	

	void DepositMoney(double p_Amt)  
	{
		if (p_Amt > 0)
		AccountBalance = AccountBalance + p_Amt;

	}

	virtual bool WithdrawMoney(double p_Amt) //this function will be overridden by Checking Account class
	{
		if (p_Amt>0 && p_Amt <=AccountBalance)
		{
			AccountBalance = AccountBalance - p_Amt;
			return true;
		}
		else 
			return false;

		
	}

	virtual string getAccountType()=0; //Abstract function making base class an abstract class.
};