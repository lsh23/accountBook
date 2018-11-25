#ifndef CARD_H
#define CARD_H

#include "Wallet.h"

class Card: public Wallet
{

	public :
		Card();
		Card(double cardbalance);

	private:
		double cardbalance;
};


#endif // !CARD_H
