#include "Day.h"

Day::Day()
{
}

Day::Day(const Day& copy)
{
	this->accountTablesOfDay = copy.accountTablesOfDay;
}
Day::~Day()
{
}

vector<AccountTable>* Day::Day_getAccountTablesOfDay()
{
	return &accountTablesOfDay;
}


void Day::Day_addAccountTable(AccountTable newAccountTable)
{
	accountTablesOfDay.push_back(newAccountTable);
}

void Day::Day_editAccountTable(int numberOftable, AccountTable editedAccountTable)
{
	
}

void Day::Day_deleteAccountTable(int numberOftable)
{
	accountTablesOfDay.erase(accountTablesOfDay.begin() + numberOftable);
}
