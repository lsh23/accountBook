#ifndef DAY_H
#define DAY_H
#include"AccountTable.h"
#include<vector>
class Day {
	public:
		Day();
		Day(const Day& copy);
		~Day();
		vector<AccountTable>* Day_getAccountTablesOfDay();
		void Day_addAccountTable(AccountTable newAccountTable);
		void Day_editAccountTable(int numberOftable, AccountTable editedAccountTable); // 테이블 번호 입력 수정
		void Day_deleteAccountTable(int numberOftable);// 테이블 번호 삭제 
	private:
		vector<AccountTable> accountTablesOfDay;
};
#endif // !DAY_H
