#ifndef MONTH_H
#define MONTH_H
#include"Day.h"
#include<unordered_map>

using namespace stdext;
class Month {
	public:
		Month();
		Month(const Month &copy);
		~Month();
		//Day* Month_getDays();
	
		Day Month_getDay(int _day);
		bool Month_isDay(int _day);
		void Month_addAccountTable(AccountTable newAccountTable,int day);
		void Month_deleteAccountTable(int day, int index);
	private:
		unordered_map<int, Day> days;
};
#endif // !MONTH_H
