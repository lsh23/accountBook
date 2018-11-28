#include "AccontBook.h"


AccountBook::AccountBook()
{
	calendar = new Calendar();
}

AccountBook::~AccountBook()
{
	delete calendar;
}

Calendar AccountBook::Account_getCalendar()
{
	return *calendar;
}

Day AccountBook::AccountBook_getDay(int _year, int _month, int _day)
{
	return (calendar->Calendar_getYear(_year).Year_getMonth(_month).Month_getDay(_day));
}

Month AccountBook::AccountBook_getMonth(int _year, int _month) {
	return (calendar->Calendar_getYear(_year).Year_getMonth(_month));
}

Year AccountBook::AccountBook_getYear(int _year) {
	return (calendar->Calendar_getYear(_year));
}

void AccountBook::AccountBook_addAccountTable(AccountTable newAccountTable, int year, int month, int day)
{
	calendar->Calendar_addAccountTable(newAccountTable, year, month, day);
}
void AccountBook::AccountBook_deleteAccountTable(int year, int month, int day , int index)
{
	calendar->Calendar_deleteAccountTable( year, month, day , index);
}

void AccountBook::AccountBook_editAccountTable()
{
}

void AccountBook::AccountBook_removeAccountTable()
{
	//しかいしぉいしぉい
}
