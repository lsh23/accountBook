#include "CategoryOfIncome.h"
#include <string.h>

CategoryOfIncome::CategoryOfIncome()
{
	Category_Income[0] = "월급";
	Category_Income[1] = "용돈";
	Category_Income[2] = "상여";
}

CategoryOfIncome::~CategoryOfIncome()
{
}

void CategoryOfIncome::Category_add(char * text)
{
	for (int i = 0; i < 30; i++)
		if (Category_Income[i] != nullptr)//'\0'으로 쓸지 nullptr로 쓸지
			Category_Income[i] = text;
}

void CategoryOfIncome::Category_delete(char * text)
{
	for (int i = 0; i < 30; i++)
		if (!strcmp(Category_Income[i], text))
			Category_Income[i] = nullptr;
}

char* CategoryOfIncome::Category_whatIsCategory(int index)
{
	for (int i = 0; i < 30; i++)
		if (i == index)
			return Category_Income[i];
	return nullptr;
}

int CategoryOfIncome::Category_getNumberOfDefaultCategory()
{
	return numberOfDefaultCategory;
}