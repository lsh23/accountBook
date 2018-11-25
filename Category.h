#ifndef CATEGORY_H
#define CATEGORY_H
#include<unordered_map>
#include<string>

using namespace std;
using namespace stdext;

class Category {
	public:
		Category();
		~Category();
		void Category_add(string);
		void Category_delete(int index);
		int Category_whatIsCategory(string);

		string Category_whatIsCategory(int i);

		int Category_getNumberOfDefaultCategory();

	private:
		vector<string> DefaultCategory;
};

#endif // !CATEGORY_H
