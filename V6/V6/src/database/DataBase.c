#include "DataBase.h"

int DataBaseConstructor(DataBasePointer _this)
{
	InitializeBill(&_this->baseHead);
	return 0;// !
}

int DataBaseDeconstructor(DataBasePointer _this)
{
	ClearBills(&_this->baseHead);
	return 0;// !
}

int AddNewBill(DataBasePointer _this)
{

	return 0;//
}

int PrintAllDataBase(DataBasePointer _this)
{
	PrintBills(&_this->baseHead);

	return 0;//
}