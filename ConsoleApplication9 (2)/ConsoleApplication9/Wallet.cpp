#include "Wallet.h"

Wallet::Wallet()
{
}

Wallet::Wallet(int bal)
{
	balance = bal;
}

int Wallet::Wallet_getBalance() {
	return balance;
}
void Wallet::Wallet_setBalance(int bal) {
	balance = bal;
}

void Wallet::Wallet_expenditure(int expendi) {
	balance = balance - expendi;
	}

void Wallet::Wallet_income(int inco) {
	balance = balance + inco;
}
