#if !defined(__reader_h__)
#define __reader_h__

#include <stdio.h>

typedef struct {
    FILE* in;
    char cin;
} Reader;

Reader new_Reader();
Reader new_Reader(char* fileName);
void Reader_adv(Reader* p);
char Reader_read(Reader* p);
char* Reader_readLine(Reader* p);
int Reader_readInt(Reader* p);

#endif // __reader_h__
