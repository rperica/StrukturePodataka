#include "stdio.h"

#include "PersonList.h"

static int AddOnTheBeginning(Position head);
static int AddOnTheEnd(Position head);
static int SearchList(Position head);
static int RemoveFromList(Position head);
static int Print(Position head);

static int AddAfterLastName(Position head);
static int AddBeforeLastName(Position head);

int ListMenu()
{
	Person head = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };

	char choose = 0;
	int exit = 1;

	while (exit)
	{
		printf("Welcome To List Menu, please choose operation: \n");
		printf("A. Add Person at the beginning of the list. \n");
		printf("B. Add Person at the end of the list. \n");
		printf("C. Search the list by last name. \n");
		printf("D. Remove person from the list. \n");
		printf("E. Print the list. \n");
		printf("F. Add after specific last name. \n");
		printf("G. Add before specific last name. \n");
		printf("S. Sort list. \n");
		printf("W. Write to file. \n");
		printf("R. Read from file. \n");
		printf("X. Exit Menu. \n");

		printf("Please choose upper letter from above menu for operation: ");
		scanf(" %c", &choose);

		switch (choose)
		{
		case 'A':
			AddOnTheBeginning(&head);
			break;

		case 'B':
			AddOnTheEnd(&head);
			break;

		case 'C':
			SearchList(&head);
			break;

		case 'D':
			RemoveFromList(&head);
			break;

		case 'E':
			Print(&head);
			break;
		
		case 'F':
			AddAfterLastName(&head);
			break;
		
		case 'G':
			AddBeforeLastName(&head);
			break;

		case 'S':
			SortList(&head);
			break;

		case 'W':
			WriteToFile("res/Persons.txt", &head);
			break;

		case 'R':
			ReadFromFile("res/ReadPersons.txt", &head);
			break;

		case 'X':
			exit = 0;
			break;

		default:
			printf("Wrong option, please choose again. \n");
			break;
		}

		printf("###########################################################\n \n");
	}

	ClearList(&head);
	return SUCCESS;
}

static int AddOnTheBeginning(Position head)
{
	Person person = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };

	printf("Enter name: ");
	scanf(" %s", person.name);
	printf("Enter last name: ");
	scanf(" %s", person.lastName);
	printf("Enter year of birth: ");
	scanf("%d", &person.birthYear);

	PrependList(head, person.name, person.lastName, person.birthYear);

	return SUCCESS;
}

static int AddOnTheEnd(Position head)
{
	Person person = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };

	printf("Enter name: ");
	scanf(" %s", person.name);
	printf("Enter last name: ");
	scanf(" %s", person.lastName);
	printf("Enter year of birth: ");
	scanf("%d", &person.birthYear);

	AppendList(head, person.name, person.lastName, person.birthYear);

	return SUCCESS;
}

static int SearchList(Position head)
{
	Person person = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };

	printf("Enter last name: ");
	scanf(" %s", person.lastName);

	FindPersonByLastName(head->next, person.lastName);

	return SUCCESS;
}

static int RemoveFromList(Position head)
{
	Person person = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };

	printf("Enter last name of person to delete: ");
	scanf(" %s", person.lastName);

	RemovePerson(head, person.lastName);
	
	return SUCCESS;
}

static int Print(Position head)
{
	PrintList(head->next);

	return SUCCESS;
}

static int AddAfterLastName(Position head)
{
	Person person = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };
	char lastName[20] = { 0 };

	printf("Enter name: ");
	scanf(" %s", person.name);
	printf("Enter last name: ");
	scanf(" %s", person.lastName);
	printf("Enter year of birth: ");
	scanf("%d", &person.birthYear);

	printf("Enter last name: ");
	scanf(" %s", lastName);

	AddAfter(head, lastName, person.name, person.lastName, person.birthYear);

	return SUCCESS;
}

static int AddBeforeLastName(Position head)
{
	Person person = { .name = {0}, .lastName = {0}, .birthYear = 0, .next = NULL };
	char lastName[20] = { 0 };

	printf("Enter name: ");
	scanf(" %s", person.name);
	printf("Enter last name: ");
	scanf(" %s", person.lastName);
	printf("Enter year of birth: ");
	scanf("%d", &person.birthYear);

	printf("Enter last name: ");
	scanf(" %s", lastName);

	AddBefore(head, lastName, person.name, person.lastName, person.birthYear);

	return SUCCESS;
}