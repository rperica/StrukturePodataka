#pragma once

#include "date/Date.h"
#include "articles/ArticleList.h"

// class Bill
typedef struct _bill
{
	Date date;
	ArticleElement head; //

}Bill;
typedef struct _bill* BillPointer;

// Constructor and Deconstructor
int BillConstructor(BillPointer _this, int year, int month, int day);
int BillConstructorClear(BillPointer _this);
int BillDeconstructor(BillPointer _this);

// Methods
int PrintBillData(BillPointer _this);
