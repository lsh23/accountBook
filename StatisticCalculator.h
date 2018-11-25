#ifndef STATISTICCALCULATOR_H
#define STATISTICCALCULATOR_H
#include<string>
#include"AccontBook.h"
#include"Wallet.h"

using namespace std;

class StatisticCalculator {
	public:
		// 
		int StatisticCalculator_totalOfIncomeBalance(vector<AccountTable> outputTables);
		int StatisticCalculator_totalOfExpenditureBalance(vector<AccountTable> outputTables);
		int StatisticCalculator_totalOfIncomeCardBalance(vector<AccountTable> outputTables);
		int StatisticCalculator_totalOfExpenditureCardBalance(vector<AccountTable> outputTables);
		int StatisticCalculator_totalOfIncomeCashBalance(vector<AccountTable> outputTables);
		int StatisticCalculator_totalOfExpenditureCashBalance(vector<AccountTable> outputTables);

		int StatisticCalculator_totalOfIncomeCategoryBalance(vector<AccountTable> outputTables, string category);
		int StatisticCalculator_totalOfExpenditureCategoryBalance(vector<AccountTable> outputTables, string category);

		int StactisticCalculator_percenteOfPartOfTotal(int part, int total);


		// 1이면 수입에대한 통계 2면 지출에대한 통계
													 
	    //calculator는 수입 총액 / 지출 총액 / 각각 수입 및 지출 카테고리별 총액 / 퍼센테이지 / 계산해주면 됨.
		//Appcontroller에서 AccountTable을 넘겨서 줄꺼임.
	private:
		int StactisticCalculator_percentageOfX(); // x에 대한 퍼센테이지 계산하여 리턴
												 // distribution에 대한 비공개 함수
};
#endif // !STATISTICCALCULATOR_H
