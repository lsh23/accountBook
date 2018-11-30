#ifndef WALLET_H
#define WALLET_H

class Wallet {
	public:
		Wallet(); //defualt 생성자 
		Wallet(int bal); //잔고 받는 생성자
		int Wallet_getBalance(); //잔고 정보 가져오기
		void Wallet_setBalance(int bal);

		void Wallet_expenditure(int expendi);
		void Wallet_income(int inco);

	
	private:
		int balance; //수입, 지출, 잔고
};
#endif // !WALLET_H

