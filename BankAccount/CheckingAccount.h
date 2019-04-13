#include "CheckingAccount.h"

class CheckingAccount:public BankAccount
{
private:
	int NoOfWithdrawalTrans;

public:

	CheckingAccount(string p_acctNumber,double);
	int getNoOfWithdrawalTrans();
	bool WithdrawMoney(double p_Amt);

};
