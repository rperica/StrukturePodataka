#include "database/DataBase.h"
#include "filters/Filters.h"

#include "tools/Assert.h"

#include "stdio.h"
#include "string.h"

int Program()
{
	float earnings = 0.0f;
	Date from;
	DateConstructor(&from, 2021, 9, 1);
	Date to;
	DateConstructor(&to, 2021, 9, 6);

	DataBase billsBase;
	DataBaseConstructor(&billsBase);
	DataBaseInterface(&billsBase);
	CaluclateTotalEarningsFromDateRange(&billsBase.baseHead, from, to, &earnings);

	DataBaseDeconstructor(&billsBase);

	return 0; // !
}