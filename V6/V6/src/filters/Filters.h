#pragma once
#include "bills/BillList.h"

//class Filter
typedef struct _filter
{
	Date dateFrom;
	Date dateTo;

	char name[MAX_ARTICLE_NAME];
}Filter;
typedef struct _filter* FilterPointer;

int FilterConstructorClear(FilterPointer _this);
int FilterDeconstructor(FilterPointer _this);

int CreateFilter(FilterPointer _this);

int CaluclateTotalEarningsFromDateRange(BillPosition head, Date fromDate, Date toDate, float* sumPrice);
