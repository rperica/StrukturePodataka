#include "Date.h"

#include "stdio.h"
#include "string.h"

static int DateToString(DatePointer _this);

int DateConstructor(DatePointer _this, int year, int month, int day)
{
	_this->YY = year;
	_this->MM = month;
	_this->DD = day;

	DateToString(_this);

	return 0; // !
}

int DateConstructorFromString(DatePointer _this, const char* dateString)
{
	if (sscanf(dateString, "%d-%d-%d", &_this->YY, &_this->MM, &_this->DD) != 3)
	{
		printf("Invalid date \"%s\", should be in format YYYY-MM-DD!\r\n", dateString);
		DateConstructorClear(_this);

		return 1; //
	}

	DateToString(_this);

	return 0; //
}

int DateConstructorClear(DatePointer _this)
{
	_this->YY = 0;
	_this->MM = 0;
	_this->DD = 0;

	memset(_this->DateString, 0, MAX_DATE_AS_STRING);

	return 0; // !
}

int DateDeconstructor(DatePointer _this)
{
	printf("Object has been destroyed\n");
	return 0; // !
}

int DateCompare(DatePointer _this, DatePointer date)
{
	int result = _this->YY - date->YY;

	if (result == 0)
	{
		result = _this->MM - date->MM;

		if (result == 0)
		{
			result = _this->DD - date->DD;
		}
	}

	return result; 
}

int PrintDate(DatePointer _this)
{
	//printf("%04d-%02d-%02d\n", _this->YY, _this->MM, _this->DD);
	printf("%s\n", _this->DateString);
	return 0; // !
}

static int DateToString(DatePointer _this)
{
	sprintf(_this->DateString, "%04d-%02d-%02d", _this->YY, _this->MM, _this->DD);

	return 0; //
}