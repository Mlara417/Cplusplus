#include "BankAccount.h"

class SavingsAccount:public BankAccount 
{
private:
	double dailyInterestRate;
	double AnnualInterestRate;
	int NoOfDaysSinceLastTrans;
	double interestEarned;

public:

	SavingsAccount(string p_acctNumber,double p_bal);
	void setAnnualInterestRate(double p_rate);
	void setInterestEarned();
	int getNoOfDaysSinceLastTrans();
	double getInterestEarned();
	double getAccountBalance();
	
};

class CheckingAccount:public BankAccount
{
private:
	int NoOfWithdrawalTrans;

public:

	CheckingAccount(string p_acctNumber,double);
	int getNoOfWithdrawalTrans();
	bool WithdrawMoney(double p_Amt);

};