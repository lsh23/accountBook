#ifndef ACCOUNTBOOK_H
#define ACCOUNTBOOK_H
#include"Calendar.h"
#include"AccountTable.h"
class AccountBook {
	public:
		AccountBook();
		~AccountBook();
		Calendar Account_getCalendar();
		Day AccountBook_getDay(int _year, int _month, int _day);
		Month AccountBook_getMonth(int _year, int _month);
		Year AccountBook_getYear(int _year);
		void AccountBook_addAccountTable(AccountTable newAccountTable,int year, int month, int day);
		void AccountBook_deleteAccountTable(int year, int month, int day, int index);
		void AccountBook_editAccountTable();
		void AccountBook_removeAccountTable();
	private:
		Calendar* calendar;


};
#endif // !ACCOUNTBOOK_H
