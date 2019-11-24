#if !defined(__utils_h__)
#define __utils_h__

#include "../headers.h"

#define MAX_LENGTH 1 << 7

boolean compareString(char* a, char* b);
void append(char* a, char* b);
void copyString(char* a, char* b);
void toLowerCase(char* p, char* res);
int max(int a, int b);
int min(int a, int b);

#endif // __utils_h__
