#pragma once

#define SUCCESS 0
#define FAILURE 1
#define NULL ((void*)0)

typedef struct _StackElement
{
	float number;
	struct _StackElement* next;
}StackElement;
typedef struct _StackElement* Position;

int Example(const char* filePath);

int Push(Position head, float number);
int Pop(float* number, Position head);
int ClearStack(Position head);

int PerformOperation(float* result, Position head, char operation);
int ReadFromFile(float* result, const char* filePath);