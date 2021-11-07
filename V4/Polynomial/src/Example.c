#include "Polynomial.h"

int Example(const char* filePath)
{
	Polynomial poly1 = { .coefficent = 0, .exponent = 0, .next = NULL };
	Polynomial poly2 = { .coefficent = 0, .exponent = 0, .next = NULL };
	Polynomial resAdd = { .coefficent = 0, .exponent = 0, .next = NULL };
	Polynomial resMul = { .coefficent = 0, .exponent = 0, .next = NULL };

	ReadFromFile(&poly1, &poly2, filePath);

	PrintPoly(&poly1);
	PrintPoly(&poly2);

	AddPoly(&resAdd, &poly1, &poly2);
	PrintPoly(&resAdd);

	MultiplyPoly(&resMul, &poly1, &poly2);
	PrintPoly(&resMul);

	ClearPoly(&poly1);
	ClearPoly(&poly2);
	ClearPoly(&resAdd);
	ClearPoly(&resMul);

	return SUCCESS;
}