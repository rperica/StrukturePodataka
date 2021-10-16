#include "Assert.h"

int reportAssertionFault(const char* message, const char* file, int line)
{
	printf("ERROR: %s return NULL at line: %d in %s", message, line, file);

	return 0;
}