#include "DataBase.h"
#include "filters/Filters.h"

#include "stdio.h"
#include "stdlib.h"

#define MAX_FILE_NAME 128

static int PrintMenu();

int DataBaseInterface(DataBasePointer _this)
{
	char fileName[MAX_FILE_NAME] = { 0 };
	int status = EXIT_FAILURE;

	int choose;

	printf("\t\t\tWelcome to DataBase Interface\n\n");
	do
	{
		printf("Please insert sheet file to initialize you database->\t");
		scanf(" %s", fileName);

		status = CreateFromFile(&_this->baseHead, fileName);
	} while (status > EXIT_SUCCESS);

	strcpy(_this->sheetPath, fileName);

	printf("\r\n" "\t ** Successfully read %s:\r\n\r\n", fileName);
	PrintAllDataBase(_this);
	printf("\n");

	do
	{
		PrintMenu();
		printf("Choose: ");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1:
			PrintAllDataBase(_this);
			break;
		case 2:
			break;
		case 3:// TODO
			break;
		case 0:
			break;
		default:
			printf("Wrong option\n");
			break;
		}

	} while (choose != 0);

	return 0; // !
}

static int PrintMenu()
{
	printf("Choose one of operations:\n");
	printf("1. Print bills \n");
	printf("2. Add new bill\n");
	printf("3. Filter data\n");
	printf("0. EXIT\n");

	return 0; // !
}