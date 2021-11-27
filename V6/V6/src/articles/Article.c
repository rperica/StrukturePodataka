#include "Article.h"

#include "stdio.h"
#include "string.h"

int ArticleConstructor(ArticlePointer _this, const char* name, int quantity, float price)
{
	strcpy(_this->name, name);
	_this->quantity = quantity;
	_this->price = price;
	
	return 0; // !
}

int ArticleConstructorClear(ArticlePointer _this)
{
	const char* empty = "0";

	strcpy(_this->name, empty);
	_this->quantity = 0;
	_this->price = 0.0f;

	return 0; // !
}

int ArticleDeconstructor(ArticlePointer _this)
{
	printf("Object has been destroyed\n");
	return 0; // !
}

int PrintArticleData(ArticlePointer _this)
{
	printf("P: %s  Q: %d P: %.2f kn \n", _this->name, _this->quantity, _this->price);

	return 0; // !
}