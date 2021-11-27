#include "bills/BillList.h"
#include "articles/Article.h"
#include "filters/Filters.h"

#include "tools/Assert.h"

#include "stdio.h"
#include "string.h"

int CreateFromFile(BillPosition head, const char* filepath);
int ReadPath(char* path, const char* buffer);

int Program(const char* filepath)
{
	float earnings = 0.0f;
	Date from;
	DateConstructor(&from, 2021, 9, 1);
	Date to;
	DateConstructor(&to, 2021, 9, 6);

	// BILL HEAD ELEMENT
	BillElement billHead;
	BillConstructorClear(&billHead.bill); // Clear head values
	billHead.nextBill = NULL;

	CreateFromFile(&billHead, filepath);

	PrintBills(&billHead);

	//TODO MENU HERE
	CaluclateTotalEarningsFromDateRange(&billHead, from, to, &earnings);
	printf("%.2f\n", earnings);

	ClearBills(&billHead);
	return 0; // !
}

int CreateFromFile(BillPosition head, const char* filepath)
{
	FILE* file = NULL;
	char buffer[1024] = { 0 };
	char path[1024] = { 0 };

	ASSERT(file = fopen(filepath, "r"));

	while (!feof(file))
	{
		fgets(buffer, 1024, file);
		ReadPath(path, buffer);
		CreateAndInsertBill(head, path);
	}

	fclose(file);

	return 0; // !
}

int ReadPath(char* path, const char* buffer)
{
	while (*buffer!='\n' && *buffer != '\0')
	{
		*path = *buffer;

		buffer++;
		path++;
	}
	
	return 0; // !
}