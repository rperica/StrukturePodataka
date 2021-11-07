#pragma once

#ifdef DEBUG

#define ASSERT(x)\
		if(x){}\
		else\
		{\
			reportAssertionFault(#x,__FILE__,__LINE__);\
			__debugbreak();\
		}
#else

#define ASSERT(x)

#endif 

int reportAssertionFault(const char* message, const char* file, int line);