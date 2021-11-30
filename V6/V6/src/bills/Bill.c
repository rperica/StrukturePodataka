#include "Bill.h"

int BillConstructor(BillPointer _this, int year, int month, int day)
{
	DateConstructor(&_this->date, year, month, day);// !
	
	ArticleConstructorClear(&_this->head.article);
	_this->head.nextArticle = (void*) 0;

	return 0; // !
}

int BillConstructorClear(BillPointer _this)
{
	DateConstructorClear(&_this->date);
	InitializeArticle(&_this->head);

	return 0; // !
}

int BillDeconstructor(BillPointer _this)
{
	ClearArticles(&_this->head); //

	//printf("Object has been destroyed\n");
	return 0; // !
}

int PrintBillData(BillPointer _this)
{
	PrintDate(&_this->date);
	PrintArticles(&_this->head);

	return 0; // !
}