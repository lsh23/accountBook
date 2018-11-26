#define _SILENCE_STDEXT_unordered_DEPRECATION_WARNINGS
#include "AppController.h"
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
using namespace stdext;
vector<string> split(string target, string delimiter);

AppController::AppController()
{
	appIO = new AppIO();
	appFileReaderAndWriter = new AppFileReaderAndWriter();
	accountBook = new AccountBook();
	wallet = new Wallet();
	statisticCalculator = new StatisticCalculator();
	categoryOfExpenditure = new Category();
	categoryOfIncome = new Category();
	cash = new Cash();
	card = new Card();
}

AppController::~AppController()
{
	delete appIO;
	delete appFileReaderAndWriter;
	delete wallet;
	delete statisticCalculator;
	delete categoryOfExpenditure;
	delete categoryOfIncome;
	delete accountBook;

}

void AppController::AppController_addAccountTable(int _year, int _month, int _day, bool _isIncome, bool _isCard, double _money, string _category, string _memo)
{
	AccountTable newAccountTable = AccountTable(_isIncome, _isCard, _money, _category, _memo);
	accountBook->AccountBook_addAccountTable(newAccountTable, _year, _month, _day);
}

void AppController::AppController_showDefaultCategory(bool _isIncome)
{
	int numberOfLoop ;
	if (_isIncome) {
		numberOfLoop = categoryOfIncome->Category_getNumberOfDefaultCategory();
		for (int i = 0; i < numberOfLoop; i++) {
			string nameOfCategory = categoryOfIncome->Category_whatIsCategory(i);
			appIO->AppIO_printCategory(i, nameOfCategory);
		}
		appIO->AppIO_printEnter();
	}
	else {
		numberOfLoop = categoryOfExpenditure->Category_getNumberOfDefaultCategory();
		for (int i = 0; i < numberOfLoop; i++) {
			string nameOfCategory = categoryOfExpenditure->Category_whatIsCategory(i);
			appIO->AppIO_printCategory(i, nameOfCategory);
		}
		appIO->AppIO_printEnter();
	}
}

void AppController::AppController_printTableOfDay(int year, int month, int day) {
	//해당날짜 노드들 다 출력
	Day outputDate = Day(accountBook->AccountBook_getDay(year, month, day));
	vector<AccountTable> outputTables = *(outputDate.Day_getAccountTablesOfDay());
		for (int i = 0; i < outputTables.size(); i++) {
		AccountTable tmp = outputTables[i];
		bool isIncome = tmp.AccountTable_getIsIncome();
		bool isCard = tmp.AccountTable_getIsCard();
		double money = tmp.AccountTable_getMoney();
		string category = tmp.AccountTable_getCategory();
		string memo = tmp.AccountTable_getMemo();
		appIO->AppIO_printTableOfDay(year, month, day, isIncome, isCard, money, category, memo);
	}

}

void AppController::AppController_printTableOfDaySimple(int year, int month, int day) {
	//해당날짜 노드들 다 출력
	Day outputDate = Day(accountBook->AccountBook_getDay(year, month, day));
	vector<AccountTable> outputTables = *(outputDate.Day_getAccountTablesOfDay());
	for (int i = 0; i < outputTables.size(); i++) {
		AccountTable tmp = outputTables[i];
		bool isIncome = tmp.AccountTable_getIsIncome();
		bool isCard = tmp.AccountTable_getIsCard();
		double money = tmp.AccountTable_getMoney();
		string category = tmp.AccountTable_getCategory();
		string memo = tmp.AccountTable_getMemo();
		appIO->AppIO_printTableOfDay(i,isIncome, isCard, money, category, memo);
	}

}

void AppController::AppController_deleteAccountTable(int year , int month , int day ,int index) {
	Day outputDate = Day(accountBook->AccountBook_getDay(year, month, day));
	vector<AccountTable> outputTables = *(outputDate.Day_getAccountTablesOfDay());
	AccountTable tmp = outputTables[index];
	bool isIncome = tmp.AccountTable_getIsIncome();
	bool isCard = tmp.AccountTable_getIsCard();
	double money = tmp.AccountTable_getMoney();
	string category = tmp.AccountTable_getCategory();
	string memo = tmp.AccountTable_getMemo();
	accountBook->AccountBook_deleteAccountTable(year, month, day, index);
	appFileReaderAndWriter->AppFileReaderAndWriter_write_deleteLine(year, month, day, isIncome, isCard, money, category, memo);
}
/*추가추가*/
void AppController::AppController_addExpenditureCategory(string s) {
	categoryOfExpenditure->Category_add(s);
	appFileReaderAndWriter->AppFileReaderAndWriter_writeExpenditureCategory(s);
}

void AppController::AppController_addIncomeCategory(string s)
{
	categoryOfIncome->Category_add(s);
	appFileReaderAndWriter->AppFileReaderAndWriter_writeIncomeCategory(s);
}
void AppController::AppController_readExpenditureCategory(string s) {
	categoryOfExpenditure->Category_add(s);

}

void AppController::AppController_readIncomeCategory(string s)
{
	categoryOfIncome->Category_add(s);

}
void AppController::AppController_deleteExpenditureCategory(int index) {
	string deleteCategory = categoryOfExpenditure->Category_whatIsCategory(index);
	appFileReaderAndWriter->AppFileReaderAndWriter_write_deleteExpenditureCategory(deleteCategory);
	categoryOfExpenditure->Category_delete(index);
}

void AppController::AppController_deleteIncomeCategory(int index) {
	string deleteCategory = categoryOfIncome->Category_whatIsCategory(index);
	appFileReaderAndWriter->AppFileReaderAndWriter_write_deleteIncomeCategory(deleteCategory);
	categoryOfIncome->Category_delete(index);
}


void AppController::Appcontroller_CalculateMonth(int year, int month) {
	Month outputMonth = Month(accountBook->AccountBook_getMonth(year, month));
	int totalOfIncome = 0;
	int totalOfCardIncome = 0;
	int totalOfCashIncome = 0;
	int totalOfExpenditure = 0;
	int totalOfCardExpendture = 0;
	int totalOfCashExpendture = 0;
	vector<int> sumOfCategoryOfIncome;	
	vector<int> sumOfCategoryOfExpenditure;
	for (int i = 0; i < categoryOfIncome->Category_getNumberOfDefaultCategory(); i++)
		sumOfCategoryOfIncome.push_back(0);
	for (int i = 0; i < categoryOfExpenditure->Category_getNumberOfDefaultCategory(); i++)
		sumOfCategoryOfExpenditure.push_back(0);

	for (int i = 0; i < 31 ; i++) {
		if (outputMonth.Month_isDay(i)) {
			Day outputDay = Day(outputMonth.Month_getDay(i));
			vector<AccountTable> outputTables = *(outputDay.Day_getAccountTablesOfDay());
			totalOfIncome += statisticCalculator->StatisticCalculator_totalOfIncomeBalance(outputTables);
			totalOfCardIncome += statisticCalculator->StatisticCalculator_totalOfIncomeCardBalance(outputTables);
			totalOfCashIncome += statisticCalculator->StatisticCalculator_totalOfIncomeCashBalance(outputTables);
			for (int j = 0; j < categoryOfIncome->Category_getNumberOfDefaultCategory(); j++) 
			{
				string category = categoryOfIncome->Category_whatIsCategory(j);
				int sum = statisticCalculator->StatisticCalculator_totalOfIncomeCategoryBalance(outputTables, category);
				sumOfCategoryOfIncome[j] = sumOfCategoryOfIncome[j] + sum; /*+= -> = 로*/
			}

			totalOfExpenditure += statisticCalculator->StatisticCalculator_totalOfExpenditureBalance(outputTables);
			totalOfCardExpendture += statisticCalculator->StatisticCalculator_totalOfExpenditureCardBalance(outputTables);
			totalOfCashExpendture += statisticCalculator->StatisticCalculator_totalOfExpenditureCashBalance(outputTables);
			for (int j = 0; j < categoryOfExpenditure->Category_getNumberOfDefaultCategory(); j++) 
			{
				string category = categoryOfExpenditure->Category_whatIsCategory(j);
				int sum = statisticCalculator->StatisticCalculator_totalOfExpenditureCategoryBalance(outputTables, category);
				sumOfCategoryOfExpenditure[j] = sumOfCategoryOfExpenditure[j] + sum; /*+= -> = 로*/
			}
		}
		//디폴트 카테고리수만큼의 각각 카테고리의 썸이 결과로 나와야함 .

			//call calculator 
			//calculator는 수입 총액 / 지출 총액 / 각각 수입 및 지출 카테고리별 총액 / 퍼센테이지 / 계산해주면 됨.
	}
	//cout << "총수입 : " << totalOfIncome << " 총카드수입 : " << totalOfCardIncome << " 총현금수입 :  " << totalOfCashIncome << endl;
	//cout << "총지출 : " << totalOfExpenditure << " 총카드지출 : " << totalOfCardExpendture << " 총현금지출 : " << totalOfCashExpendture << " " << endl;
	appIO->AppIO_prnitTotalIncome(totalOfIncome, totalOfCardIncome, totalOfCashIncome);
	for (int i = 0; i < sumOfCategoryOfIncome.size(); i++) {
		//cout << categoryOfIncome->Category_whatIsCategory(i) << "의 총 수입 : " << sumOfCategoryOfIncome[i] << endl;
		appIO->AppIO_printDistributionOfIncomeOfCategory(categoryOfIncome->Category_whatIsCategory(i), sumOfCategoryOfIncome[i],0);
	}

	appIO->AppIO_printTotalExpenditure(totalOfExpenditure, totalOfCardExpendture, totalOfCashExpendture);
	for (int i = 0; i < sumOfCategoryOfExpenditure.size(); i++) {
		//cout << categoryOfExpenditure->Category_whatIsCategory(i) << "의 총 지출 : " << sumOfCategoryOfExpenditure[i] << endl;
		appIO->AppIO_printDistributionOfIExpenditureOfCategory(categoryOfExpenditure->Category_whatIsCategory(i), sumOfCategoryOfExpenditure[i], 0);
	}
	
}



int AppController::AppController_run()
{
	int c;
	int _year;
	int _month;
	int _day;
	bool _isIncome;
	bool _isCard;
	double _money;
	string _category;
	string _memo;
	appFileReaderAndWriter->AppFileReaderAndWriter_readCateGory(this); // 추가
	appFileReaderAndWriter->AppFileReaderAndWriter_read(this);
	//appFileReaderAndWirter->AppFileReaderAndWriter_write();
	appIO->AppIO_mainUI();

	cin >> c;

	while (c != 5)
	{

		if (c == 1)
		{
			//수정** while문 추가
			while (c == 1) {
				//1.쓰기
				//ㄱ.날짜를 입력하세요 예 2018 03 14
				// 토큰해서 _year , _month , _day 넣어주기

				cin.ignore();
				appIO->AppIO_inputDate();
				string dateInput;
				getline(cin, dateInput);
				vector<string> tokens = split(dateInput, " ");
				_year = stoi(tokens[0]);
				_month = stoi(tokens[1]);
				_day = stoi(tokens[2]);

				//ㄴ.1.수입/2.지출
				appIO->AppIO_inputExpenditureOrIncome();
				cin >> c;
				if (c == 1)
					_isIncome = true;
				else
					_isIncome = false;
				//ㄷ.1.카드/2.현금
				appIO->AppIO_inputCardOrCash();
				cin >> c;
				if (c == 1)
					_isCard = true;
				else
					_isCard = false;
				//ㄹ.금액을 입력하세요 :
				appIO->AppIO_inputBalance();
				cin >> _money;
				//Default 수입/지출 카테고리 ...

				// 카테고리 추가 / 삭제
				//ㅁ.카테고리를 설정하세요 :
				appIO->AppIO_inputCategory();
				string tmp;
				cin >> tmp;

				while (tmp != "1") {
					if (tmp == "+") {
						//추가
						AppController_showDefaultCategory(_isIncome);
						cout << "추가할 카테고리를 입력하세요 : " << endl;;
						cin >> tmp;
						cout << tmp << "를 카테고리에 추가합니다." << endl;
						if (_isIncome)
							AppController_addIncomeCategory(tmp);
						else
							AppController_addExpenditureCategory(tmp);

					}
					else if (tmp == "-") {
						AppController_showDefaultCategory(_isIncome);
						cout << "삭제할 카테고리를 입력하세요 : ";
						int deletedIndex;
						cin >> deletedIndex;
						
						if (_isIncome) {
							string s = categoryOfIncome->Category_whatIsCategory(deletedIndex);
							cout << s << "를 카테고리에서 삭제 합니다." << endl;
							AppController_deleteIncomeCategory(deletedIndex);
						}
						else {
							string s = categoryOfExpenditure->Category_whatIsCategory(deletedIndex);
							cout << s << "를 카테고리에서 삭제 합니다." << endl;
							AppController_deleteExpenditureCategory(deletedIndex);
						}
						//삭제
					}
					appIO->AppIO_inputCategory();
					cin >> tmp;
				}

				if (tmp == "1") {
					AppController_showDefaultCategory(_isIncome);
					appIO->AppIO_selectCategory();

				}
				int seletedIndex;
				cin >> seletedIndex;
				// 선택한 카테고리 인덱스
				if (_isIncome) {
					_category = categoryOfIncome->Category_whatIsCategory(seletedIndex);
					if (_isCard)
						card->Wallet_setincome(_money);
					else
						cash->Wallet_setincome(_money);
				}
				else {
					_category = categoryOfExpenditure->Category_whatIsCategory(seletedIndex);
					if (_isCard)
						card->Wallet_setexpenditure(_money);
					else
						cash->Wallet_setexpenditure(_money);
				}
				appIO->AppIO_inputMemo();
				cin.ignore(); /*추가함*/
				getline(cin, _memo); /*추가함*/

				AppController_addAccountTable(_year, _month, _day, _isIncome, _isCard, _money, _category, _memo);
				appFileReaderAndWriter->AppFileReaderAndWriter_write(_year, _month, _day, _isIncome, _isCard, _money, _category, _memo);
				//추가 한 해당날 프린트
				appIO->AppIO_printTableOfDay(_year, _month, _day);
				AppController_printTableOfDaySimple(_year, _month, _day);//수입 / 지출 카드 / 현금 10000 카테고리 메모

																		 //수정** while문 추가
				while (c != 4) {
					cout << "1.메인화면으로 돌아가기 2.추가하기 3.삭제하기" << endl;
					cin >> c;

					if (c == 1) {
						c = 10; //메인화면으로 돌아가기
						break;
					}
					if (c == 2) {
						c = 1; //계속쓰기
						break;

					}
					if (c == 3) {
						cout << "삭제할 인덱스 번호를 입력 하세요 : " << endl;
						cin >> c;
						AppController_deleteAccountTable(_year, _month, _day, c);
						appIO->AppIO_printTableOfDay(_year, _month, _day);
						AppController_printTableOfDaySimple(_year, _month, _day);

					}
				}
				//if (c == 4) {

				//}
				//if (c == 5) {

				//}
				//1.메인화면으로 돌아가기 2.계속쓰기 3. 삭제 ..
				//
			}
		}
		else if (c == 2) {
			//수정** while문 추가
			while (c == 2) {
				//2.보기 
				//ㄱ.날짜를 입력하세요 예 2018 03 14
				// 토큰해서 _year , _month , _day 넣어주기
				appIO->AppIO_inputDate();
				cin >> _year;
				cin >> _month;
				cin >> _day;
				appIO->AppIO_printTableOfDay(_year, _month, _day);
				AppController_printTableOfDay(_year, _month, _day);//수입 / 지출 카드 / 현금 10000 카테고리 메모
				while (c != 3) {
					cout << "1.메인화면으로 돌아가기 2.다른날짜 보기" << endl;
					cin >> c;

					if (c == 1) {
						c = 10; //메인화면으로 돌아가기
						break;
					}
					if (c == 2) {
						c = 2; //계속보기
						break;
					}
				}

			}
		}
		else if (c == 3) {
			//3.통계
			//1.월병 통계하기
			Appcontroller_CalculateMonth(2018, 11);
			//2.기간별 통계하기
			//----------------
			//ㄱ.전체 통계하기 ㄴ.카테고리별 통계하기
		}

		else if (c == 4) {
			//4.잔고확인
			double balance;
			balance = card->Wallet_getBalance() + cash->Wallet_getBalance();
			cout << "총 잔고 : " << balance << endl;
			cout << "카드 잔액 : " << cash->Wallet_getBalance() << endl;
			cout << "현금 잔액 : " << card->Wallet_getBalance() << endl;
		}
		appIO->AppIO_mainUI();
		cin >> c;
	}


	appIO->AppIO_programEixt();

	return 0;
}

vector<string> split(string target, string delimiter) {
	vector<string> result;
	int position = target.find(delimiter);

	while (position != -1) {
		string str1 = target.substr(0, position);
		result.push_back(str1);
		target = target.substr(position + 1);
		position = target.find(delimiter);
	}
	result.push_back(target);

	return result;
}

void AppFileReaderAndWriter::AppFileReaderAndWriter_readCateGory(AppController* appcontroller) 
{
	ifstream in("CategoryOfExpenditure.txt");
	ifstream in2("CategoryOfIncome.txt");
	string s;

	if (in.is_open()) {
		string line;
		getline(in, line);
		while (getline(in, line)) {
			
			appcontroller->AppController_readExpenditureCategory(line);
		}
	}
	else {
		cout << " 파일을 찾을 수 없습니다.!" << endl;
	}

	in.close();

	if (in2.is_open()) {
		string line;
		getline(in2, line);
		while (getline(in2, line)) {

			appcontroller->AppController_readIncomeCategory(line);
		}
	}
	else {
		cout << " 파일을 찾을 수 없습니다.!" << endl;
	}

	in2.close();

}







void AppFileReaderAndWriter::AppFileReaderAndWriter_read(AppController* appcontroller)
{
	ifstream in("data.txt");
	string s;

	if (in.is_open()) {
		string line;
		getline(in, line);
		while (getline(in, line)) {
			vector<string> tokens = split(line, " ");
			int year = stoi(tokens[0]);
			int month = stoi(tokens[1]);
			int day = stoi(tokens[2]);
			bool isIncome = false;
			if (tokens[3] == "수입")
				isIncome = true;
			bool isCard = false;
			if (tokens[4] == "카드")
				isCard = true;
			double money = (double)stoi(tokens[5]);
			string category = tokens[6];
			string memo = tokens[7];
			appcontroller->AppController_addAccountTable(year, month, day, isIncome, isCard, money, category, memo);
		}
	}
	else {
		cout << " 파일을 찾을 수 없습니다.!" << endl;
	}

	in.close();
}


void AppFileReaderAndWriter::AppFileReaderAndWriter_write(int _year, int _month, int _day, bool _isIncome, bool _isCard, double _money, string _category, string _memo)
{
	string year = to_string(_year);
	string month = to_string(_month);
	string day = to_string(_day);
	string isIncome;
	if (_isIncome)
		isIncome = "수입";
	else
		isIncome = "지출";
	string isCard;
	if (_isCard)
		isCard = "카드";
	else
		isCard = "현금";

	string money = to_string((int)_money);

	string addedData = year + " " + month + " " + day + " " + isIncome + " " + isCard + " " + money + " " + _category + " " + _memo;

	ofstream out("test.txt", ios::app);

	if (out.is_open()) {
		out << endl << addedData;
	}

	out.close();

}

void AppFileReaderAndWriter::AppFileReaderAndWriter_write_deleteLine(int _year, int _month, int _day, bool _isIncome, bool _isCard, double _money, string _category, string _memo)
{
	ofstream tmp;
	tmp.open("temp.txt");

	string year = to_string(_year);
	string month = to_string(_month);
	string day = to_string(_day);
	string isIncome;
	if (_isIncome)
		isIncome = "수입";
	else
		isIncome = "지출";
	string isCard;
	if (_isCard)
		isCard = "카드";
	else
		isCard = "현금";

	string money = to_string((int)_money);

	string deletedLine = year + " " + month + " " + day + " " + isIncome + " " + isCard + " " + money + " " + _category + " " + _memo;

	ifstream in;
	in.open("data.txt");


	if (in.is_open()) {
		string line;
		getline(in, line);
		tmp << "년도 월 일 수 / 지 카 / 현 금액 카테고리 메모";
		while (getline(in, line))
		{
			if (!(line == deletedLine))
			{
				tmp << endl << line;
			}// 이거하면 새로운파일에 엔터하나 박힘 수정해야됨.
		}
	}

		in.close();
		tmp.close();
		remove("data.txt");
		rename("temp.txt", "data.txt");

}

void AppFileReaderAndWriter::AppFileReaderAndWriter_writeExpenditureCategory(string s)
{

	ofstream out("CategoryOfExpenditure.txt", ios::app);

	if (out.is_open()) {
		out << endl << s;
	}

	out.close();

}

void AppFileReaderAndWriter::AppFileReaderAndWriter_writeIncomeCategory(string s)
{

	ofstream out("CategoryOfIncome.txt", ios::app);

	if (out.is_open()) {
		out << endl << s;
	}

	out.close();

}

void AppFileReaderAndWriter::AppFileReaderAndWriter_write_deleteExpenditureCategory(string deletedCategory)
{
	ofstream tmp;
	tmp.open("temp.txt");

	

	ifstream in;
	in.open("CategoryOfExpenditure.txt");


	if (in.is_open()) {
		string line;
		getline(in, line);
		tmp << "CategoryOfExpenditure";
		while (getline(in, line))
		{
			if (!(line == deletedCategory))
			{
				tmp << endl << line;
			}// 이거하면 새로운파일에 엔터하나 박힘 수정해야됨.
		}
	}

	in.close();
	tmp.close();
	remove("CategoryOfExpenditure.txt");
	rename("temp.txt", "CategoryOfExpenditure.txt");

}
void AppFileReaderAndWriter::AppFileReaderAndWriter_write_deleteIncomeCategory(string deletedCategory)
{
	ofstream tmp;
	tmp.open("temp.txt");



	ifstream in;
	in.open("CategoryOfIncome.txt");


	if (in.is_open()) {
		string line;
		getline(in, line);
		tmp << "CategoryOfIncome";
		while (getline(in, line))
		{
			if (!(line == deletedCategory))
			{
				tmp << endl << line;
			}// 이거하면 새로운파일에 엔터하나 박힘 수정해야됨.
		}
	}

	in.close();
	tmp.close();
	remove("CategoryOfIncome.txt");
	rename("temp.txt", "CategoryOfIncome.txt");

}

//reader랑 writer 랑 분리해서 read는 main 에서 쓰고 writer는 Appcontroller 에서 쓰기 