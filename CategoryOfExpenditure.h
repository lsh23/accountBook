#ifndef CATEGORYOFEXPENDITURE_H
#define CATEGORYOFEXPENDITURE_H
#include "Category.h"

class CategoryOfExpenditure : public Category
{
public:
	CategoryOfExpenditure();
	~CategoryOfExpenditure();
	void Category_add(char* text); //목록에 추가
	void Category_delete(char* text); //목록에서 삭제
	char* Category_whatIsCategory(int index); //인덱스에 따라 카테고리명 리턴
	int Category_getNumberOfDefaultCategory();
private:
	int numberOfDefaultCategory = 6;
	char* Category_Expenditure[30]; //지출 카테고리 목록
};

#endif // !CATEGORYOFEXPENDITURE_H