#ifndef YEAR_H
#define TEAR_H
#include"Month.h"
#include<unordered_map>

using namespace stdext;

class Year {
	public:
		~Year();
		Year();
		Year(const Year& copy);
		Month Year_getMonth(int _month);
		void Year_addAccountTable(AccountTable newAccountTable, int _month, int day);
		void Year_deleteAccountTable(int _month, int day, int index);

	private:
		unordered_map<int, Month> months;
};
#endif // !YEAR_H
