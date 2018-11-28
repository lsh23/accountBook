#ifndef APPIO_H
#define APPIO_H

#include<iostream>
#include<string>
using namespace std;

class AppIO {
	public:
		AppIO();//Default 생성자 java 와 다른건 main에서 그냥 AppIO(); 하면 끝임;
		~AppIO();//Default 소멸자 Delete x ; 와 같은거 c++에선 소멸자 호출시에도 function을 넣을 수 있음. 
		// 소멸자에 동적할당했던거 delete 해주는거 넣으면 됨 . 또는 종료문 넣으면 될듯
		void AppIO_mainUI(); //mainUI 출력
		void AppIO_inputDate(); //날짜를 입력하세요:
		void AppIO_inputExpenditureOrIncome();// 지출인지 수입인지 입력하세요:
		void AppIO_inputBalance();// 금액을 입력하세요.
		void AppIO_inputCategory();
		void AppIO_selectCategory();
		void AppIO_print(string s);
		void AppIO_print(int i);
		void AppIO_printTableOfDay(int year, int month, int day , bool isIcome , bool isCard, double money , string category ,string memoe);
		void AppIO_printTableOfDay(bool isIcome, bool isCard, double money, string category, string memoe);
		void AppIO_printTableOfDay(int index, bool isIcome, bool isCard, double money, string category, string memo);
		void AppIO_printTableOfDay(int year, int month, int day);
		void AppIO_printCategory(int i, string s);
		void AppIO_inputMemo();
		void AppIO_printEnter();
		// category 선택하세요. / 추가/  삭제할떄
		void AppIO_inputCardOrCash();

		void AppIO_programEixt(); // 종료문
		void AppIO_prnitTotalIncome(int totalOfIncome, int totalOfCardIncome, int totalOfCashIncome);
		void AppIO_printTotalExpenditure(int totalOfExpenditure, int toalOfCardExenditure, int totalOfCashExpenditure);
		void AppIO_printDistributionOfIncomeOfCategory(string _category, int sumOfCategory, int percentage);
		void AppIO_printDistributionOfIExpenditureOfCategory(string _category, int sumOfCategory, int percentage);
		void AppIO_printGraph(string _category, int percentage);
	private:
};

#endif // !APPIO_H

