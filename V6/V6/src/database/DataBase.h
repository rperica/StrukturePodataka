#pragma once

#include "bills/BillList.h"

//class DataBase
typedef struct _database
{
	BillElement baseHead;
	char sheetPath[128];

}DataBase;
typedef struct _database* DataBasePointer;

int DataBaseConstructor(DataBasePointer _this);
int DataBaseDeconstructor(DataBasePointer _this);

int AddNewBill(DataBasePointer _this); //
int PrintAllDataBase(DataBasePointer _this);

int DataBaseInterface(DataBasePointer _this);
