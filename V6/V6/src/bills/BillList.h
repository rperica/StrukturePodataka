#pragma once

#include "Bill.h"

struct _billList;
typedef struct _billList* BillPosition;
typedef struct _billList
{
	Bill bill;
	BillPosition nextBill;
}BillElement;

int InitializeBill(BillPosition billHead);

int ClearBills(BillPosition head);
int CreateAndInsertBill(BillPosition head, const char* filepath);

int PrintBills(BillPosition head);

int CreateFromFile(BillPosition head, const char* filepath); //from file sheet