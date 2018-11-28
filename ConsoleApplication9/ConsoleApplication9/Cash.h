#ifndef CASH_H
#define CASH_H


#include "Wallet.h"

class Cash:public Wallet {

	public:
		Cash();
		Cash(double cashbalance);

	private:
		double cashbalance;
};
#endif // !CASH_H
