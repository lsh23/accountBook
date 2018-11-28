#include "Cash.h"
#include "Wallet.h"

Cash::Cash()
{

}

Cash::Cash(double cashbalance)
	:Wallet(cashbalance)
{
	Wallet::Wallet_setBalance(cashbalance);
}
