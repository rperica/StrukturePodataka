#pragma once

#include "Bill.h"
#include "errors/Error.h"

struct _billList;
typedef struct _billList* BillPosition;
typedef struct _billList
{
	Bill bill;
	BillPosition nextBill;
}BillElement;

int InitializeBill(BillPosition billHead);

int ClearBills(BillPosition head);
int InsertBillSorted(BillPosition head, BillPosition newElement);
int CreateAndInsertBill(BillPosition head, const char* filepath);

int PrintBills(BillPosition head);

int CreateFromFile(BillPosition head, const char* filepath); //from file sheet
int WriteBillToFile(BillPointer _this, const char* filePath);