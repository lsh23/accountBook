#ifndef ACCOUNTTABLE_H
#define ACCOUNTTABLE_H

#include<string>
#include<vector>
using namespace std;

class AccountTable {
	public:
		AccountTable();
		AccountTable(bool _isIncome,bool _isCard, double _money , string _category , string _memo);
		void AccountTable_setIsIncome(bool isIncome);
		void AccountTable_setIsCard(bool isCard);
		void AccountTable_setMoney(double money);
		void AccountTable_setCategory(string category);
		void AccountTable_setMemo(string memo);

		bool AccountTable_getIsIncome();
		bool AccountTable_getIsCard();
		double AccountTable_getMoney();
		string AccountTable_getCategory();
		string AccountTable_getMemo();

private:
		bool isIncome;
		bool isCard;
		double money;
		string category;
		string memo;
		

};
#endif // !ACCOUNTTABLE_H
