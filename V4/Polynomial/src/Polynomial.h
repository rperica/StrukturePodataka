#pragma once

#define SUCCESS 0
#define FAILURE 1
#define NULL ((void*) 0) 

typedef struct _polynomial
{
	int coefficent;
	int exponent;
	struct _polynomial* next;
}Polynomial;
typedef Polynomial* Position;

int Example(const char* filePath);

int ReadFromFile(Position head1, Position head2, const char* filePath);
int InsertSorted(Position head, Position newElement);

int AddPoly(Position result, Position head1, Position head2);
int MultiplyPoly(Position result, Position head1, Position head2);

int PrintPoly(Position head);
int ClearPoly(Position head);