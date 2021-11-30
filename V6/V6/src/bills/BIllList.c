#include "BillList.h"
#include "tools/Assert.h"

#include "stdio.h"
#include "stdlib.h"

static BillPosition NewBillElement(int year, int month, int day);
static int ClearAfterBill(BillPosition position);
static int InsertBillSorted(BillPosition head, BillPosition newElement);
static int InsertAfterBill(BillPosition position, BillPosition newElement);

static BillPosition ReadBillFromFile(const char* filepath); 


int InitializeBill(BillPosition billHead)
{
	BillConstructorClear(&billHead->bill);
	billHead->nextBill = NULL;

	return 0; // !
}

int CreateAndInsertBill(BillPosition head, const char* filepath)
{
	BillPosition bill = NULL;
	bill=ReadBillFromFile(filepath);
	InsertBillSorted(head, bill);

	return 0; // !
}

int ClearBills(BillPosition head)
{
	for (; head->nextBill != NULL;)
	{
		ClearAfterBill(head);
	}

	return 0; // !
}


int PrintBills(BillPosition head)
{
	BillPosition first = head->nextBill;

	for (; first != NULL; first = first->nextBill)
	{
		PrintBillData(&first->bill);
	}
	printf("\n");
	return 0; //!
}

int CreateFromFile(BillPosition head, const char* filepath)
{
	FILE* file = NULL;
	char buffer[1024] = { 0 };
	char path[1024] = { 0 };

	ASSERT(file = fopen(filepath, "r"));

	while (!feof(file))
	{
		fscanf(file," %s", buffer);
		CreateAndInsertBill(head, buffer);
	}

	fclose(file);

	return 0; // !
}

static BillPosition NewBillElement(int year, int month, int day)
{
	BillPosition newElement = NULL;

	ASSERT(newElement = (BillPosition)malloc(sizeof(BillElement)));

	BillConstructor(&newElement->bill, year, month, day);
	newElement->nextBill = NULL;

	return newElement; 
}

static int ClearAfterBill(BillPosition position)
{
	BillPosition garbage = position->nextBill;
	position->nextBill = garbage->nextBill;

	BillDeconstructor(&garbage->bill); 
	free(garbage);

	return 0; // !
}

static int InsertBillSorted(BillPosition head, BillPosition newElement)
{
	BillPosition temp = head;

	for(;temp->nextBill != NULL && DateCompare(&temp->nextBill->bill.date, &newElement->bill.date) < 0; temp=temp->nextBill) {} //

	InsertAfterBill(temp, newElement);

	return 0; // !
}

static int InsertAfterBill(BillPosition position, BillPosition newElement)
{
	newElement->nextBill = position->nextBill;
	position->nextBill = newElement;

	return 0; // !
} 

static BillPosition ReadBillFromFile(const char* filepath)
{
	BillPosition newBill = NULL;

	FILE* file = NULL;
	char buffer[1024] = { 0 };

	int year = 0;
	int month = 0;
	int day = 0;

	char productName[20] = { 0 };
	int quantity = 0;
	float price = 0.0f;

	ASSERT(file = fopen(filepath, "r"));

	fgets(buffer, 1024, file);

	ASSERT(sscanf(&buffer, " %d-%d-%d", &year, &month, &day) == 3);
	newBill = NewBillElement(year, month, day);

	while (!feof(file))
	{
		fgets(buffer, 1024, file);
		
		if (sscanf(buffer, " %s %d %f", productName, &quantity, &price) == 3)
		{
			CreateAndInsertArticle(&newBill->bill.head, productName, quantity, price);
		}
	}

	fclose(file);

	return newBill; // !
}