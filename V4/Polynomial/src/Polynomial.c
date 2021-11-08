#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "tools/Assert.h"
#include "Polynomial.h"

static Position CreateListElement(int coefficient, int exponent);
static int ReadData(Position head, const char* buffer);
static int Merge(Position head, Position newElement);
static int CreateAndInsert(Position position, int coefficient, int exponent);
static int InsertAfter(Position position, Position newElement);
static int DeleteAfter(Position head);

int ReadFromFile(Position head1, Position head2, const char* filePath)
{
	FILE* file = NULL;
	char buffer[1024] = { 0 };

	ASSERT(file = fopen(filePath, "r"));

	fgets(buffer, 128, file);
	ReadData(head1, buffer);

	fgets(buffer, 128, file);
	ReadData(head2, buffer);

	fclose(file);
	return SUCCESS;
}

int InsertSorted(Position head, Position newElement)
{
	Position temp = NULL;
	for (temp = head; temp->next != NULL && temp->next->exponent>newElement->exponent; temp=temp->next) {}

	Merge(temp, newElement);

	return SUCCESS;
}

int AddPoly(Position result, Position head1, Position head2)
{
	Position temp = NULL;
	Position p1 = head1->next;
	Position p2 = head2->next;

	for (; p1 != NULL && p2 != NULL;)
	{
		if (p1->exponent == p2->exponent)
		{
			CreateAndInsert(result, p1->coefficent + p2->coefficent, p1->exponent);
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exponent > p2->exponent)
		{
			CreateAndInsert(result, p1->coefficent, p1->exponent);
			p1 = p1->next;
		}
		else
		{
			CreateAndInsert(result, p2->coefficent, p2->exponent);
			p2 = p2->next;
		}
	}

	temp = (p1 != NULL) ? p1 : p2;
	for (; temp != NULL; temp = temp->next)
	{
		CreateAndInsert(result, temp->coefficent, temp->exponent);
	}

	return SUCCESS;
}

int MultiplyPoly(Position result, Position head1, Position head2)
{
	Position i = NULL;
	Position j = NULL;

	Position newElement = NULL;

	for (i = head1->next; i != NULL; i = i->next)
	{
		for (j = head2->next; j != NULL; j = j->next)
		{
			CreateAndInsert(result, i->coefficent * j->coefficent, i->exponent + j->exponent);
		}
	}
}

int PrintPoly(Position head)
{
	Position temp = head->next;

	for (temp = head->next; temp != NULL; temp = temp->next)
	{
		printf("%d*x^%d + ", temp->coefficent, temp->exponent);
	}
	printf("0 \n");

	return SUCCESS;
}

int ClearPoly(Position head)
{
	Position temp = head;

	if (!temp->next)
	{
		printf("Poly is already empty\n");
		return FAILURE;
	}

	for (temp = head; temp->next != NULL;)
	{
		DeleteAfter(head);
	}

	return SUCCESS;
}

static Position CreateListElement(int coefficient, int exponent)
{
	Position element = NULL;

	ASSERT(element = (Position)malloc(sizeof(Polynomial)));
	element->coefficent = coefficient;
	element->exponent = exponent;
	element->next = NULL;

	return element;
}

static int ReadData(Position head, const char* buffer)
{
	const char* bufferPosition = buffer;
	int offset = 0;

	int coefficient = 0;
	int exponent = 0;

	while (*bufferPosition != '\0')
	{
		ASSERT((sscanf(bufferPosition, " %d %d %n", &coefficient, &exponent, &offset)) == 2);

		if (coefficient != 0)
		{
			CreateAndInsert(head, coefficient, exponent);
		}

		bufferPosition += offset;
	}

	return SUCCESS;
}

static int Merge(Position position, Position newElement)
{
	Position temp = position;
	int result = 0;

	if (temp->next != NULL && temp->next->exponent == newElement->exponent)
	{
		result = temp->next->coefficent + newElement->coefficent;

		if (result != 0)
		{
			temp->next->coefficent = result;
		}
		else
		{
			DeleteAfter(temp);
		}
		free(newElement);
	}
	else
	{
		InsertAfter(temp, newElement);
	}

	return SUCCESS;
}

static int CreateAndInsert(Position position, int coefficient, int exponent)
{
	if (coefficient != 0)
	{
		Position newElement = CreateListElement(coefficient, exponent);
		InsertSorted(position, newElement);
	}

	return SUCCESS;
}

static int InsertAfter(Position position, Position newElement)
{
	newElement->next = position->next;
	position->next = newElement;

	return SUCCESS;
}

static int DeleteAfter(Position head)
{
	Position garbage = head->next;
	head->next = garbage->next;
	free(garbage);

	return SUCCESS;
}

