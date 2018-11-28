#ifndef APPFILEREADERANDWRITER_H
#define APPFILEREADERANDWRITER_H

#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class AppFileReaderAndWriter {
	public:
		void AppFileReaderAndWriter_read(AppController *appcontroller);
		// 파일 읽어오기.
		void AppFileReaderAndWriter_write(int _year, int _month, int _day,bool _isIncome,bool _isCard, double _money,string _category,string _memo);// 파일 쓰기.
		void AppFileReaderAndWriter_write();
		void AppFileReaderAndWriter_Tokenize(const string & str, vector<string>& tokens, const string & delimiters);
private:
};
#endif // !APPFILEREADERANDWRITER_H

