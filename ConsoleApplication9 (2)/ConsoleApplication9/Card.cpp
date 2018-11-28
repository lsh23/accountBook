#include "Card.h"
#include "Wallet.h"

Card::Card()
{
}

Card::Card(double cardbalance)
	:Wallet(cardbalance)
{
	Wallet::Wallet_setBalance(cardbalance);

}
