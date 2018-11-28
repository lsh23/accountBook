#include "Month.h"
using namespace stdext;
Month::Month()
{
	
}

Month::Month(const Month& copy)
{
	this->days = copy.days;
}
	//this->days = new Day[31];
	//for (int i = 0 ; i < 31; i++) {
	//	days[i] = copy->Month_getDays[i + 1];
	//}


Month::~Month()
{
	
}


Day Month::Month_getDay(int _day)
{	
	unordered_map<int, Day>::iterator Iter = days.find(_day);
	if (Iter != days.end())
		return Iter->second;
}

bool Month::Month_isDay(int _day) {
	unordered_map<int, Day>::iterator Iter = days.find(_day);
	if (Iter != days.end())
		return true;
	else
		return false;
}

void Month::Month_addAccountTable(AccountTable newAccountTable, int day)
{
	unordered_map<int, Day>::iterator Iter = days.find(day);
	if (Iter != days.end())
		Iter->second.Day_addAccountTable(newAccountTable);
	else {
		Day newdays;
		days.insert(unordered_map<int, Day>::value_type(day, newdays));
		unordered_map<int, Day>::iterator Iter = days.find(day);
		Iter->second.Day_addAccountTable(newAccountTable);
	}
	//days[day-1].Day_addAccountTable(newAccountTable);
}

void Month::Month_deleteAccountTable(int day, int index)
{
	unordered_map<int, Day>::iterator Iter = days.find(day);
	if (Iter != days.end())
	Iter->second.Day_deleteAccountTable(index);
}
