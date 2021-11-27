#pragma once

#include "Bill.h"

struct _billList;
typedef struct _billList* BillPosition;
typedef struct _billList
{
	Bill bill;
	BillPosition nextBill;
}BillElement;

int ClearBills(BillPosition head);
int CreateAndInsertBill(BillPosition head, const char* filepath);

int PrintBills(BillPosition head);