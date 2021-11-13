#include "Stack.h"
#include "tools/Assert.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static Position CreateElement(float number);
static int InsertAfter(Position head, Position newElement);
static int DeleteAfter(Position head);
static int ReadData(float* result, Position head, char* bufferPosition);
static int ReadFile(char** buffer, const char* filePath);

int Push(Position head, float number)
{
	Position newElement = CreateElement(number);
	InsertAfter(head, newElement);

	return SUCCESS;
}

int Pop(float* number, Position head)
{
	Position lastElement = head->next;
	ASSERT(lastElement);
	
	*number = lastElement->number;

	DeleteAfter(head);
	return SUCCESS;
}

int ClearStack(Position head)
{
	Position temp = head;

	if (temp->next == NULL)
	{
		return SUCCESS;
	}

	for (;temp->next != NULL;)
	{
		DeleteAfter(head);
	}
	
	return SUCCESS;
}

int PerformOperation(float* result, Position head, char operation)
{
	float operand1 = 0.0f;
	float operand2 = 0.0f;

	Pop(&operand2, head);
	Pop(&operand1, head);

	switch (operation)
	{
	case '-':
		*result = operand1 - operand2;
		Push(head, *result);
		break;

	case '+':
		*result = operand1 + operand2;
		Push(head, *result);
		break;

	case '*':
		*result = operand1 * operand2;
		Push(head, *result);
		break;

	case '/':
		ASSERT(operand2 != 0);
		*result = operand1 / operand2;
		Push(head, *result);

		break;

	default:
		printf("Not supported!");
		break;
	}

	return SUCCESS;
}

int ReadFromFile(float* result, const char* filePath)
{
	StackElement head = { .number = 0.0f, .next = NULL };
	char* buffer = NULL;

	ReadFile(&buffer, filePath);
	ReadData(result, &head, buffer);

	ClearStack(&head);
	free(buffer);
	return SUCCESS;
}

int Example(const char* filePath)
{
	float result = 0.0f;

	ReadFromFile(&result, filePath);

	printf("%.2f \n", result);

	return SUCCESS;
}

static Position CreateElement(float number)
{
	Position newElement = NULL;

	ASSERT(newElement = (Position)malloc(sizeof(StackElement)));

	newElement->number = number;
	newElement->next = NULL;

	return newElement;
}

static int InsertAfter(Position head, Position newElement)
{
	Position temp = head;

	newElement->next = temp->next;
	temp->next = newElement;

	return SUCCESS;
}

static int DeleteAfter(Position head)
{
	Position garbage = head->next;
	head->next = garbage->next;
	free(garbage);

	return SUCCESS;
}

static int ReadFile(char** buffer, const char* filePath)
{
	FILE* file = NULL;
	int length = 0;

	ASSERT(file = fopen(filePath, "rb"));

	fseek(file, 0L, SEEK_END);
	length = ftell(file);

	ASSERT(*buffer = (char*)calloc(length + 1, sizeof(char)));

	rewind(file);
	fread(*buffer, sizeof(char), length, file);
	fclose(file);

	return SUCCESS;
}

static int ReadData(float* result, Position head, char* bufferPosition)
{
	char operation = 0;

	float number = 0;
	int offset = 0;

	while (*bufferPosition != '\0')
	{
		if (sscanf(bufferPosition, " %f %n", &number, &offset) == 1)
		{
			Push(head, number);
			bufferPosition += offset;
		}
		else if (sscanf(bufferPosition, " %c %n", &operation, &offset) == 1)
		{
			PerformOperation(result, head, operation);
			bufferPosition += offset; 
		}
		else
		{
			ASSERT(0);
			return FAILURE;
		}
	}

	return SUCCESS;
}