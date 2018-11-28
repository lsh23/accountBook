#include"AppIO.h"

using namespace std;

AppIO::AppIO()
{
}

AppIO::~AppIO()
{
}

void AppIO::AppIO_mainUI() {
	cout << endl;
	cout << " --------------------------------------------------------------" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << "|			Account Book				|" << endl;
	cout << "|			(ver1.0)				|" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << "|			1.가계부 쓰기				|" << endl;
	cout << "|			2.가계부 보기				|" << endl;
	cout << "|			3.소비패턴 파악				|" << endl;
	cout << "|			4.종료					|" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << "|								|" << endl;
	cout << " --------------------------------------------------------------" << endl;
	cout << endl;
}

void AppIO::AppIO_inputDate()
{
	cout << "\n날짜를 입력하세요 (예시 2018 12 07 ) : ";
}

void AppIO::AppIO_inputExpenditureOrIncome()
{
	cout << "\n1.수입 / 2.지출을 선택하세요 : ";
}

void AppIO::AppIO_inputBalance()
{
	cout << "\n금액을 입력하세요 : ";
}

void AppIO::AppIO_inputCategory()
{	
	cout << "1.카테고리 선택" << endl;
	cout << "+.카테고리 추가 / -.카테고리 삭제" << endl;

}

void AppIO::AppIO_selectCategory() {
	cout << "카테고리를 선택하세요 : " << endl;
}

void AppIO::AppIO_print(string s)
{
	cout << s << endl;
}

void AppIO::AppIO_print(int i)
{
	cout << i << endl;
}

void AppIO::AppIO_printTableOfDay(int year, int month, int day, bool isIcome, bool isCard, double money, string category, string memo)
{
	string _isIncome, _isCard;
	if (isIcome) _isIncome = "수입";
	else _isIncome = "지출";
	if (isCard) _isCard = "카드";
	else _isCard = "현금";
	cout << year << " " << month << " " << day << " " << _isIncome << " " << _isCard << " " << (int)money << " " << category << " " << memo << endl;
}

void AppIO::AppIO_printTableOfDay(bool isIcome, bool isCard, double money, string category, string memo)
{
	string _isIncome, _isCard;
	if (isIcome) _isIncome = "수입";
	else _isIncome = "지출";
	if (isCard) _isCard = "카드";
	else _isCard = "현금";
	cout << _isIncome << " " << _isCard << " " << (int)money << " " << category << " " << memo << endl;

}

void AppIO::AppIO_printTableOfDay(int index ,bool isIcome, bool isCard, double money, string category, string memo)
{
	string _isIncome, _isCard;
	if (isIcome) _isIncome = "수입";
	else _isIncome = "지출";
	if (isCard) _isCard = "카드";
	else _isCard = "현금";
	cout << index <<" " <<_isIncome << " " << _isCard << " " << (int)money << " " << category << " " << memo << endl;

}


void AppIO::AppIO_printTableOfDay(int year, int month, int day) {
	cout << year << "년 " << month << "월 " << day << "일 의 가계부기록" << endl;
}
void AppIO::AppIO_printCategory(int i, string s)
{
	cout << i << "."<<s<<" ";
}

void AppIO::AppIO_inputMemo()
{
	cout << "\n메모할 내용을 입력 하세요 : ";
}

void AppIO::AppIO_printEnter() {
	cout << endl;
}
void AppIO::AppIO_inputCardOrCash()
{
	cout << "\n1.카드 / 2.현금을 선택하세요 : ";
}

void AppIO::AppIO_programEixt()
{
	cout << "프로그램을 종료합니다." << endl;
}
/*추가한것들 아래 4개*/
void AppIO::AppIO_prnitTotalIncome(int totalOfIncome, int totalOfCardIncome, int totalOfCashIncome) {
	cout << "총수입 : " << totalOfIncome << " 총카드수입 : " << totalOfCardIncome << " 총현금수입 :  " << totalOfCashIncome << endl;
}
void AppIO::AppIO_printTotalExpenditure(int totalOfExpenditure, int toalOfCardExpenditure, int totalOfCashExpenditure) {
	cout << "총지출 : " << totalOfExpenditure << " 총카드지출 : " << toalOfCardExpenditure << " 총현금지출 : " << totalOfCashExpenditure << " " << endl;
}

void AppIO_printpercentage(int percentage) {
	for (int i = 0; i < percentage/7; i++) {
		cout << "ㅁ";
	}
	
	cout <<" " <<percentage << "%"<< endl;
}

void AppIO::AppIO_printDistributionOfIncomeOfCategory(string _category, int sumOfCategory, int percentage) {
	cout << _category << "의 총 수입 : " << sumOfCategory << endl;
	AppIO_printpercentage(percentage);
	
}
void AppIO::AppIO_printDistributionOfIExpenditureOfCategory(string _category, int sumOfCategory, int percentage) {
	cout << _category << "의 총 지출 : " << sumOfCategory << endl;
	AppIO_printpercentage(percentage);
}

