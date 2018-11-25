#ifndef CATEGORYOFINCOME_H
#define CATEGORYOFINCOME_H
#include "Category.h"

class CategoryOfIncome : public Category
{
public:
	CategoryOfIncome();
	~CategoryOfIncome();
	void Category_add(char*); //목록에 추가
	void Category_delete(char*); //목록에서 삭제
	char* Category_whatIsCategory(int); //인덱스에 따라 카테고리명 리턴
	int Category_getNumberOfDefaultCategory();
private:
	int numberOfDefaultCategory = 3;
	char* Category_Income[30]; //수입 카테고리 목록
};

#endif // !CATEGORYOFINCOME_H