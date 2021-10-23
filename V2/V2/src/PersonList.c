#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "tools/Assert.h"
#include "PersonList.h"

static Position CreatePerson(const char* name, const char* lastName, int birthYear);
static Position FindPrevious(Position head, const char* lastName);
static Position FindLast(Position first);
static int AddToList(Position position, Position newPerson);

int PrependList(Position head, const char* name, const char* lastName, int birthYear)
{
	Position newPerson = CreatePerson(name, lastName, birthYear);
	AddToList(head, newPerson);

	return SUCCESS;
}

int AppendList(Position head, const char* name, const char* lastName, int birthYear)
{
	Position last = NULL;
	Position newPerson = CreatePerson(name, lastName, birthYear);

	last = FindLast(head);

	AddToList(last, newPerson);

	return SUCCESS;
}

int FindPersonByLastName(Position first, const char* lastName)
{
	Position temp = first;

	if (temp == NULL)
	{
		printf("Sorry person with last name: %s is not in the list. \n", lastName);
		return FAILURE;
	}

	for (temp = first; temp->next != NULL && strcmp(temp->lastName, lastName) != 0; temp = temp->next) {}

	if (strcmp(temp->lastName, lastName) == 0)
	{
		printf("Person with last name: %s is founded in the list. \n", lastName);
		return SUCCESS;
	}
	else
	{
		printf("Sorry person with last name: %s is not in the list. \n", lastName);
		return FAILURE;
	}

	return SUCCESS;
}

int RemovePerson(Position head, const char* lastName)
{
	Position temp = head;
	Position prev = FindPrevious(head, lastName);

	if (!prev)
	{
		printf("%s is not in the list \n", lastName);
		return FAILURE;
	}
	else
	{
		temp = prev->next;
		prev->next = temp->next;
		free(temp);

		printf("%s is removed from the list \n", lastName);

		return SUCCESS;
	}
}

int PrintList(Position first)
{
	Position temp = NULL;

	for (temp = first; temp != NULL; temp = temp->next)
	{
		printf("%s %s %d \n", temp->name, temp->lastName, temp->birthYear);
	}

	return SUCCESS;
}

static Position CreatePerson(const char* name, const char* lastName, int birthYear)
{
	Position person = NULL;
	 
	ASSERT(person = (Position)malloc(sizeof(Person)));

	strcpy(person->name, name);
	strcpy(person->lastName, lastName);
	person->birthYear = birthYear;
	person->next = NULL;

	return person;
}

static Position FindPrevious(Position head, const char* lastName)
{
	Position temp=head;

	if (temp->next == NULL)
	{
		return NULL;
	}

	for (temp = head;temp->next->next != NULL && strcmp(temp->next->lastName,lastName)!=0; temp = temp->next) {}

	if (strcmp(temp->next->lastName, lastName) != 0)
	{
		return NULL;
	}
	
	return temp;
}

static Position FindLast(Position head)
{
	Position temp = NULL;

	for (temp = head; temp->next != NULL; temp = temp->next) {}

	return temp;
}

static int AddToList(Position position, Position newPerson)
{
	newPerson->next = position->next;
	position->next = newPerson;

	return SUCCESS;
}