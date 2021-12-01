#include "Filters.h"

#define NULL ((void*)0)


int FilterConstructorClear(FilterPointer _this)
{
	DateConstructorClear(&_this->dateFrom);
	DateConstructorClear(&_this->dateTo);

	return 0;
}

int FilterDeconstructor(FilterPointer _this)
{
	printf("Object deleted\n");
	return 0;
}

int CreateFilter(FilterPointer _this)
{
	printf("Enter date from: ");
	EnterDate(&_this->dateFrom);
	printf("Enter date to: ");
	EnterDate(&_this->dateTo);
	return 0;
}


int CaluclateTotalEarningsFromDateRange(BillPosition head, Date fromDate, Date toDate, float* sumPrice)
{
	BillPosition temp = head->nextBill;
	ArticlePosition articletemp = NULL;

	for (; temp != NULL; temp = temp->nextBill)
	{
		if (DateCompare(&temp->bill.date, &fromDate) >= 0 && DateCompare(&temp->bill.date, &toDate) <= 0)
		{
			articletemp = &temp->bill.head;
			for (articletemp = articletemp->nextArticle; articletemp != NULL; articletemp = articletemp->nextArticle)
			{
				*sumPrice += (float) articletemp->article.price * articletemp->article.quantity;
			}
		}
	}

	return 0; // !
}