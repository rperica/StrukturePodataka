#include "Date.h"

#include "stdio.h"

int DateConstructor(DatePointer _this, int year, int month, int day)
{
	_this->YY = year;
	_this->MM = month;
	_this->DD = day;

	return 0; // !
}

int DateConstructorClear(DatePointer _this)
{
	_this->YY = 0;
	_this->MM = 0;
	_this->DD = 0;

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
	printf("%d-%d-%d\n", _this->YY, _this->MM, _this->DD);
	return 0; // !
}