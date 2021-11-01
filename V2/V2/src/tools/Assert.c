#include "stdio.h"
#include "Assert.h"

#define SUCCESS 0
#define FAILURE 1

int reportAssertionFault(const char* message, const char* file, int line)
{
	printf("ERROR: %s return NULL at line: %d in %s", message, line, file);

	return SUCCESS;
}