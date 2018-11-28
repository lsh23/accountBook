#include "Year.h"
using namespace stdext;
Year::~Year()
{
	
}
Year::Year() {
	
}

Year::Year(const Year& copy) {
	this->months = copy.months;
}

Month Year::Year_getMonth(int _month)
{
	unordered_map<int, Month>::iterator Iter = months.find(_month);
	if (Iter != months.end())
		return Iter->second;
}

void Year::Year_addAccountTable(AccountTable newAccountTable, int _month, int day)
{
	unordered_map<int, Month>::iterator Iter = months.find(_month);
	if (Iter != months.end())
		Iter->second.Month_addAccountTable(newAccountTable, day);
	else {
		Month newMonths;
		months.insert(unordered_map<int, Month>::value_type(_month, newMonths));
		unordered_map<int, Month>::iterator Iter = months.find(_month);
		Iter->second.Month_addAccountTable(newAccountTable, day);
	}
	//[_month-1].Month_addAccountTable(newAccountTable, day);
}

void Year::Year_deleteAccountTable(int _month, int day, int index)
{	

	unordered_map<int, Month>::iterator Iter = months.find(_month);
	if (Iter != months.end())
	Iter->second.Month_deleteAccountTable(day, index);
	
}
