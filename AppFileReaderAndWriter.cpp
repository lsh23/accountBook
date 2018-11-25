#include"AppFileReaderAndWriter.h"

using namespace std;

void AppFileReaderAndWriter::AppFileReaderAndWriter_read(AppController* appcontroller)
{
	ifstream in("test.txt");
	string s;

	if (in.is_open()) {
		string line;
		while (getline(in, line)) {
			vector<string> tokens;
			AppFileReaderAndWriter_Tokenize(line, tokens," ");
			int year = stoi(tokens[0]);
			int month = stoi(tokens[1]);
			int day = stoi(tokens[2]);
			bool isIncome;
			if (tokens[3] == "수입")
				isIncome = true;
			bool isCard;
			if (tokens[4] == "카드")
				isCard = true;
			double money = (double) stoi(tokens[5]);
			string category = tokens[6];
			string memo = tokens[7];
			appcontroller->AppController_addAccountTable(year, month, day, isIncome, isCard, money, category, memo);
		}
	}
	else {
		cout << " 파일을 찾을 수 없습니다.!" << endl;
	}
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

	string addedData = year + " " + month + " " + day + " " + isIncome + " "+isCard +" " + money + " " + _category + " " + _memo;

	ofstream out("test.txt", ios::app);
	if (out.is_open()) {
		out << endl << addedData;
	}
}

void AppFileReaderAndWriter::AppFileReaderAndWriter_write()
{
	ofstream out("test.txt");

	if (out.is_open()) {
		out << "ㅌㅋ";
	}
}


void AppFileReaderAndWriter::AppFileReaderAndWriter_Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	// 맨 첫 글자가 구분자인 경우 무시
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// 구분자가 아닌 첫 글자를 찾는다
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos)
	{
		// token을 찾았으니 vector에 추가한다
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		// 구분자를 뛰어넘는다.  "not_of"에 주의하라
		lastPos = str.find_first_not_of(delimiters, pos);
		// 다음 구분자가 아닌 글자를 찾는다
		pos = str.find_first_of(delimiters, lastPos);
	}
}

//reader랑 writer 랑 분리해서 read는 main 에서 쓰고 writer는 Appcontroller 에서 쓰기 