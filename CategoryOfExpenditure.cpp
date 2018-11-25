#include "CategoryOfExpenditure.h"
#include <string.h>

CategoryOfExpenditure::CategoryOfExpenditure()
{
	Category_Expenditure[0] = "식비";
	Category_Expenditure[1] = "교통비";
	Category_Expenditure[2] = "마트/편의점";
	Category_Expenditure[3] = "생활용품";
	Category_Expenditure[4] = "패션/미용";
	Category_Expenditure[5] = "유흥비";

}

CategoryOfExpenditure::~CategoryOfExpenditure()
{
}

void CategoryOfExpenditure::Category_add(char * text)
{
	for (int i = 0; i < 30; i++)
		if (Category_Expenditure[i] != nullptr)//'\0'으로 쓸지 nullptr로 쓸지
			Category_Expenditure[i] = text;
}

void CategoryOfExpenditure::Category_delete(char * text)
{
	for (int i = 0; i < 30; i++)
		if (!strcmp(Category_Expenditure[i], text))
			Category_Expenditure[i] = nullptr;

}

char * CategoryOfExpenditure::Category_whatIsCategory(int index)
{
	for (int i = 0; i < 30; i++)
		if (i == index)
			return Category_Expenditure[i];
	return nullptr;
}

int CategoryOfExpenditure::Category_getNumberOfDefaultCategory()
{
	return numberOfDefaultCategory;
}