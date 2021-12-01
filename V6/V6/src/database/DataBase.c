#include "DataBase.h"
#include "tools/Assert.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int DataBaseConstructor(DataBasePointer _this)
{
	InitializeBill(&_this->baseHead);
	FilterConstructorClear(&_this->filter);
	memset(_this->sheetPath, 0, 128);

	return 0;// !
}

int DataBaseDeconstructor(DataBasePointer _this)
{
	ClearBills(&_this->baseHead);
	return 0;// !
}

int PrintAllDataBase(DataBasePointer _this)
{
	PrintBills(&_this->baseHead);

	return 0;//
}

// Razbiti u manje funkcije
int AddNewBill(DataBasePointer _this)
{
	BillPosition newBill = NULL;

	char filepath[128] = "res/test/";
	char txt[] = ".txt";
	char billName[MAX_BILL_NAME] = { 0 };
	char dateString[MAX_DATE_AS_STRING] = { 0 };

	int strlen = 0;
	int numberOfArticles = 0;

	ASSERT(newBill = (BillPosition)malloc(sizeof(BillElement)));
	InitializeBill(newBill);

	Date date;
	DateConstructorClear(&date);

	printf("Enter bill name: ");
	scanf(" %s", billName);

	//https://www.programiz.com/c-programming/examples/concatenate-string
	for (; filepath[strlen] != '\0'; strlen++) {}
	for (int i = 0; billName[i] != '\0'; strlen++, i++)
	{
		filepath[strlen] = billName[i];
	}
	for (int i = 0; txt[i] != '\0'; strlen++, i++)
	{
		filepath[strlen] = txt[i];
	}
	filepath[strlen] = '\0';

	printf("Enter date in format example-> 2019-12-01 :");
	scanf(" %s", dateString);
	DateConstructorFromString(&date, dateString);

	//Ovo bi moglo ici bit menu umjesto pitanja broja aritkala
	printf("How many articles: ");
	scanf("%d", &numberOfArticles);
	for (int i = 0; i < numberOfArticles; i++)
	{
		char name[128] = { 0 };
		int quantity = 0;
		float price = 0.0f;

		printf("Enter name of article:");
		scanf(" %s", name);
		printf("Enter quantity:");
		scanf("%d",&quantity);
		printf("Enter price:");
		scanf("%f",&price);

		CreateAndInsertArticle(&newBill->bill.head,name,quantity,price);
	}

	newBill->bill.date = date;

	InsertBillSorted(&_this->baseHead, newBill);

	WriteBillToFile(&newBill->bill, filepath);
	WritePathToSheet(_this, filepath);

	return 0;//
}

int WritePathToSheet(DataBasePointer _this, const char* filePath)
{
	FILE* file = NULL;
	ASSERT(file = fopen(_this->sheetPath, "a"));
	fprintf(file, "\n%s\n", filePath); //
	fclose(file);
	return 0;
}

int CalculateEarningsInRange(DataBasePointer _this)
{
	BillPosition temp = &_this->baseHead;
	ArticlePosition articletemp = NULL;

	float sumPrice=0.0f;

	CreateFilter(&_this->filter);

	for (; temp != NULL; temp = temp->nextBill)
	{
		if (DateCompare(&temp->bill.date,&_this->filter.dateFrom) >= 0 && DateCompare(&temp->bill.date, &_this->filter.dateTo) <= 0)
		{
			articletemp = &temp->bill.head;
			for (articletemp = articletemp->nextArticle; articletemp != NULL; articletemp = articletemp->nextArticle)
			{
				sumPrice += (float)articletemp->article.price * articletemp->article.quantity;
			}
		}
	}

	printf("Total earnings: %.2f \n", sumPrice);

	return 0;
}

