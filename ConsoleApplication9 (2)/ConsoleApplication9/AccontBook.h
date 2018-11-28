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

		//통계칼큘 AppController로 넣을지 , 외부로 뺼지 외부로 빼면 
		//accountBook 가져와야 되는데 그러면 Appcontroller를 알아야 되는데 어떻게 해결할지
};
#endif // !ACCOUNTBOOK_H
