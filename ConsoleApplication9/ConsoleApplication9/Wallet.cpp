#include "Wallet.h"

Wallet::Wallet()
{
}

Wallet::Wallet(double bal)
{
	Wallet_setBalance(bal);
}

double Wallet::Wallet_getBalance()
{
	
	return balance;
}

void Wallet::Wallet_setBalance(double bal)
{
	balance = bal;
}

void Wallet::Wallet_setexpenditure(double expendi)
{
	expenditure = expendi;
	balance = Wallet_getBalance() - expenditure;
}

double Wallet::Wallet_getexpenditure()
{
	return expenditure;
}

void Wallet::Wallet_setincome(double inco)
{
	income = inco;
	balance = Wallet_getBalance() + income;
}

double Wallet::Wallet_getincome()
{
	return income;
}

