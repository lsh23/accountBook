#include "AccountTable.h"

AccountTable::AccountTable()
{
}

AccountTable::AccountTable(bool _isIncome, bool _isCard, double _money, string _category, string _memo)
{
	isIncome = _isIncome;
	isCard = _isCard;
	money = _money;
	category = _category;
	memo = _memo;
}

void AccountTable::AccountTable_setIsIncome(bool _isIncome)
{
	isIncome = isIncome;
}

void AccountTable::AccountTable_setIsCard(bool _isCard)
{
	isCard = _isCard;
}

void AccountTable::AccountTable_setMoney(double _money)
{
	money = _money;
}

void AccountTable::AccountTable_setCategory(string _category)
{
	category = _category;
}



void AccountTable::AccountTable_setMemo(string _memo)
{
	memo = _memo;
}

bool AccountTable::AccountTable_getIsIncome()
{
	return this->isIncome;
}

bool AccountTable::AccountTable_getIsCard()
{
	return this->isCard;
}

double AccountTable::AccountTable_getMoney()
{
	return this->money;
}

string AccountTable::AccountTable_getCategory()
{
	return this->category;
}

string AccountTable::AccountTable_getMemo()
{
	return this->memo;
}
