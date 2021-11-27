#include "Filters.h"

#define NULL ((void*)0)

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