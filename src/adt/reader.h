#if !defined(__reader_h__)
#define __reader_h__

#include "selector_adt.h"

#include <stdio.h>
#include "boolean.h"

typedef struct {
    FILE* stream;
    char readChar;
} Reader;

Reader new_Reader();
Reader new_FileReader(char* fileName);
void Reader_startFile(Reader* p, char* fileName);
void Reader_ignoreBlank(Reader* p);
void Reader_adv(Reader* p);
char* Reader_readString(Reader* p);
int Reader_readInt(Reader* p);
boolean Reader_isNonReadableCharacter(Reader* p);

#endif // __reader_h__
