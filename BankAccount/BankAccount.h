#include <string>
#include "stdafx.h"

using namespace std;
class BankAccount
{
private:
	string AccountNumber;
	double AccountBalance;
	
public:
	BankAccount(string p_acctNumber,double p_bal);
	void setAccountNumber(string p_acctNumber);
	string getAccountNumber();
	void setAccountBalance(double p_bal);
	virtual double getAccountBalance();
	virtual double DepositMoney(double p_Amt);
	virtual bool WithdrawMoney(double p_Amt);	
};