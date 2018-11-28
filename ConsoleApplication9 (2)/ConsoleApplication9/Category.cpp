#include "Category.h"
#include <string>
using namespace std;
Category::Category()
{
}

Category::~Category()
{
}

void Category::Category_add(string s)
{

	DefaultCategory.push_back(s);
}

void Category::Category_delete(int index)
{
	DefaultCategory.erase(DefaultCategory.begin() + index);
}

int Category::Category_whatIsCategory(string s)
{
	vector<string>::iterator itr = find(DefaultCategory.begin(), DefaultCategory.end(),s);

	if (itr != DefaultCategory.cend()) {
		return distance(DefaultCategory.begin(), itr);
	}

	else throw - 1;
}

string Category::Category_whatIsCategory(int i) {
	if (0 <= i < DefaultCategory.size())
		return DefaultCategory[i];
	else
		throw i;
}

int Category::Category_getNumberOfDefaultCategory() {
	return DefaultCategory.size();
}

//void AddCategory(Category *ctg) {ctg->Category_add;}
//void DeleteCategory(Category *ctg) {ctg->Category_delete;}
//void WhatIsCategory(Category *ctg) {ctg->Category_whatIsCategory;}
