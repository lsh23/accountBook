#include "StatisticCalculator.h"


//calculator는 수입 총액 / 지출 총액 / 각각 수입 및 지출 카테고리별 총액 / 퍼센테이지 / 계산해주면 됨.
//Appcontroller에서 AccountTable을 넘겨서 줄꺼임.

//해당일에대한 각각통계
int StatisticCalculator::StatisticCalculator_totalOfIncomeBalance(vector<AccountTable> outputTables)
{	
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsIncome() == true) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}

int StatisticCalculator::StatisticCalculator_totalOfExpenditureBalance(vector<AccountTable> outputTables)
{
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsIncome() == false) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}
int StatisticCalculator::StatisticCalculator_totalOfIncomeCardBalance(vector<AccountTable> outputTables)
{
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsCard() && tmp.AccountTable_getIsIncome()) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}

int StatisticCalculator::StatisticCalculator_totalOfExpenditureCardBalance(vector<AccountTable> outputTables) {
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsCard()  && tmp.AccountTable_getIsIncome() == false) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}
int StatisticCalculator::StatisticCalculator_totalOfIncomeCashBalance(vector<AccountTable> outputTables)
{
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsCard() == false && tmp.AccountTable_getIsIncome()) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}

int StatisticCalculator::StatisticCalculator_totalOfExpenditureCashBalance(vector<AccountTable> outputTables) {
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsCard() == false && tmp.AccountTable_getIsIncome() == false) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}
int StatisticCalculator::StatisticCalculator_totalOfIncomeCategoryBalance(vector<AccountTable> outputTables, string category)
{
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsIncome() && tmp.AccountTable_getCategory() == category) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}

int StatisticCalculator::StatisticCalculator_totalOfExpenditureCategoryBalance(vector<AccountTable> outputTables, string category)
{
	int sum = 0;
	for (int j = 0; j < outputTables.size(); j++) {
		AccountTable tmp = outputTables[j];
		if (tmp.AccountTable_getIsIncome() == false && tmp.AccountTable_getCategory() == category) {
			sum += (int)tmp.AccountTable_getMoney();
		}
	}
	return sum;
}


/*이부분 추가*/
int StatisticCalculator::StactisticCalculator_percenteOfPartOfTotal(int part, int total)
{
	double tmp = (double)total;
	double tmp2 = (double)part;
	return (int) ((tmp2 / tmp)*100);
}
