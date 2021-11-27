#pragma once 

// class Date
typedef struct _date
{
	int YY;
	int MM;
	int DD;

}Date;
typedef struct _date* DatePointer;

// Constructor and Deconstructor
int DateConstructor(DatePointer _this, int year, int month, int day);
int DateConstructorClear(DatePointer _this);
int DateDeconstructor(DatePointer _this);

// Methods
int DateCompare(DatePointer _this, DatePointer date);
int PrintDate(DatePointer _this);