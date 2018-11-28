#ifndef CALENDAR_H
#define CALENDAR_H
#include "Year.h"
#include<unordered_map>

using namespace stdext;

class Calendar {
	public:
		Calendar();
		~Calendar();
		Year Calendar_getYear(int _year);
		void Calendar_addAccountTable(AccountTable newAccountTable, int year, int month, int day);
		void Calendar_deleteAccountTable(int year, int month, int day, int index);
	private:
		unordered_map<int, Year> years;

};
#endif // !CALENDAR_H

