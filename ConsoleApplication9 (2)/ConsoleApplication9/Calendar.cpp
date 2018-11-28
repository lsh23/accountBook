#include "Calendar.h"
using namespace stdext;
Calendar::Calendar()
{

}

Calendar::~Calendar()
{

}

Year Calendar::Calendar_getYear(int _year)
{
	unordered_map<int, Year>::iterator Iter = years.find(_year);
	if (Iter != years.end())
		return Iter->second;
}

void Calendar::Calendar_addAccountTable(AccountTable newAccountTable, int year, int month, int day)
{
//	if(year==2018)
	//years[0].Year_addAccountTable(newAccountTable, month, day);
	//if (year == 2019)
		//years[1].Year_addAccountTable(newAccountTable, month, day);
	//if (year == 2020)
		//years[2].Year_addAccountTable(newAccountTable, month, day);
	unordered_map<int,Year>::iterator Iter = years.find(year);
	if (Iter != years.end())
		Iter->second.Year_addAccountTable(newAccountTable, month, day);
	else {
		Year newYears;
		years.insert(unordered_map<int, Year>::value_type(year, newYears));
		unordered_map<int, Year>::iterator Iter = years.find(year);
		Iter->second.Year_addAccountTable(newAccountTable, month, day);
	}
}

void Calendar::Calendar_deleteAccountTable(int year, int month, int day, int index)
{
	//if (year == 2018)
		//years[0].Year_deleteAccountTable(month, day , index);
	//if (year == 2019)
		//years[1].Year_deleteAccountTable(month, day, index);
	//if (year == 2020)
		//years[2].Year_deleteAccountTable(month, day, index);
	unordered_map<int, Year>::iterator Iter = years.find(year);
	if (Iter != years.end())
		Iter->second.Year_deleteAccountTable(month, day, index);
}