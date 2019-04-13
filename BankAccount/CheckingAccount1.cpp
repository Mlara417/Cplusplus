#include "stdafx.h"
#include <string>


using namespace std;

double getAccountBalance, setAccountBalance;
class CheckingAccount1 : public BankAccount
{
private:
	int NoOfWithdrawalTrans;

public:

	CheckingAccount1(string p_acctNumber = "",double p_bal = 0):BankAccount(p_acctNumber,p_bal)
	{
		
		
		NoOfWithdrawalTrans=0;
	}
	
	
	int getNoOfWithdrawalTrans()
	{
		return NoOfWithdrawalTrans;
	}

bool WithdrawMoney(double p_Amt)
	{
		NoOfWithdrawalTrans++;

		if (p_Amt <=0) return false;

		if (NoOfWithdrawalTrans <=3)
		{
			if (p_Amt <= BankAccount::getAccountBalance())
			{
				setAccountBalance(getAccountBalance()-p_Amt);
				

			return true;
			}
			else 
				return false;
		}
		else
		{
			if ((p_Amt+0.5) <=getAccountBalance())
			{
				setAccountBalance(getAccountBalance()-(p_Amt+0.5));
				

			return true;
			}
			else 
				return false;


		}
	}


};