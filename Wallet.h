#ifndef WALLET_H
#define WALLET_H

class Wallet {
	public:
		Wallet(); //defualt 생성자 
		Wallet(double bal); //잔고 받는 생성자
		double Wallet_getBalance(); //잔고 정보 가져오기
		void Wallet_setBalance(double bal); //잔고 정보 업데이트(이월된 금액으로,,??)
		//dkdk
		void Wallet_setexpenditure(double expendi); // 지출 입력
		double Wallet_getexpenditure(); // 지출 가져오기
		void Wallet_setincome(double inco); // 수입 입력
		double Wallet_getincome(); // 수입 가져오기

	private:
		double income, expenditure, balance; //수입, 지출, 잔고
};
#endif // !WALLET_H

