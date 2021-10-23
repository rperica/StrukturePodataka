#pragma once

#define SUCCESS 0
#define FAILURE 1

struct _person;
typedef struct _person* Position;
typedef struct _person
{
	char name[20];
	char lastName[20];
	int birthYear;

	Position next;
}Person;

int ListMenu();

int PrependList(Position head, const char* name, const char* lastName, int birthYear);
int AppendList(Position head, const char* name, const char* lastName, int birthYear);
int FindPersonByLastName(Position first, const char* lastName);
int RemovePerson(Position head, const char* lastName);
int PrintList(Position first);