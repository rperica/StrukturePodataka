#pragma once 

#define YEAR_STRING_LENGTH (4)           // 1999
#define DAY_STRING_LENGTH (2)            // 08
#define MONTH_STRING_LENGTH (2)          // 12
#define DASH_LENGTH (1)                  // -
#define NULL_TERMINATING_CHAR_LENGTH (1) // \0
#define MAX_DATE_AS_STRING (YEAR_STRING_LENGTH + DASH_LENGTH + MONTH_STRING_LENGTH + DASH_LENGTH + DAY_STRING_LENGTH + NULL_TERMINATING_CHAR_LENGTH)

// class Date
typedef struct _date
{
	int YY;
	int MM;
	int DD;

	char DateString[MAX_DATE_AS_STRING];

}Date;
typedef struct _date* DatePointer;

// Constructor and Deconstructor
int DateConstructor(DatePointer _this, int year, int month, int day);
int DateConstructorFromString(DatePointer _this, const char* dateString);
int DateConstructorClear(DatePointer _this);
int DateDeconstructor(DatePointer _this);

// Methods
int DateCompare(DatePointer _this, DatePointer date);
int PrintDate(DatePointer _this);
int EnterDate(DatePointer _this);