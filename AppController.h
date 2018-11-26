#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include"AppIO.h"
#include"AccontBook.h"
#include"Wallet.h"
#include"CategoryOfExpenditure.h"
#include"CategoryOfIncome.h"
#include"StatisticCalculator.h"
#include"Cash.h"
#include "Card.h"

using namespace std;

class AppFileReaderAndWriter;
class AppController {
	public:
		AppController();
		~AppController();
		void AppController_addAccountTable(int _year, int _month, int _day, bool _isIncome, bool _isCard, double _money, string _category, string _memo);
		void AppController_showDefaultCategory(bool _isIncome);
		void AppController_printTableOfDay(int year, int month, int day);
		void AppController_printTableOfDaySimple(int year, int month, int day);
		void AppController_deleteAccountTable(int year, int month, int day, int index);
		void AppController_addExpenditureCategory(string s);
		void AppController_addIncomeCategory(string s);
		void AppController_readExpenditureCategory(string s);
		void AppController_readIncomeCategory(string s);
		void AppController_deleteExpenditureCategory(int index);
		void AppController_deleteIncomeCategory(int index);
		void Appcontroller_CalculateMonth(int year, int month);
		int AppController_run();
	private:
		AppIO* appIO;
		AppFileReaderAndWriter* appFileReaderAndWriter;
		AccountBook* accountBook;
		Wallet* wallet;
		StatisticCalculator* statisticCalculator;
		Category* categoryOfExpenditure;
		Category* categoryOfIncome;
		Cash* cash;
		Card* card;
};




class AppFileReaderAndWriter {
public:
	void AppFileReaderAndWriter_readCateGory(AppController * appcontroller);
	void AppFileReaderAndWriter_read(AppController *appcontroller);
	// 파일 읽어오기.
	void AppFileReaderAndWriter_write(int _year, int _month, int _day, bool _isIncome, bool _isCard, double _money, string _category, string _memo);
	void AppFileReaderAndWriter_write_deleteLine(int _year, int _month, int _day, bool _isIncome, bool _isCard, double _money, string _category, string _memo);
	void AppFileReaderAndWriter_writeExpenditureCategory(string s);
	void AppFileReaderAndWriter_writeIncomeCategory(string s);
	void AppFileReaderAndWriter_write_deleteExpenditureCategory(string deletedCategory);
	void AppFileReaderAndWriter_write_deleteIncomeCategory(string deletedCategory);
	// 파일 쓰기.
private:
};

#endif // !APPCONTROLLER_H




