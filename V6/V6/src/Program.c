#include "database/DataBase.h"
#include "filters/Filters.h"

#include "tools/Assert.h"

#include "stdio.h"
#include "string.h"

int Program()
{
	DataBase billsBase;
	DataBaseConstructor(&billsBase);

	DataBaseInterface(&billsBase);

	DataBaseDeconstructor(&billsBase);
	return 0; // !
}