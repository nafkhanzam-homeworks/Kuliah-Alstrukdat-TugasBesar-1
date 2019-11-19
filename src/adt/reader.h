#if !defined(__reader_h__)
#define __reader_h__

#include <stdio.h>

#define BLANK ' '
#define ENTER '\n'

typedef struct {
    FILE* in;
    char cin;
} Reader;

#define Reader_in(P) (P)->in
#define Reader_cin(P) (P)->cin

Reader new_Reader();
Reader new_FileReader(char* fileName);
void Reader_ignoreBlank(Reader* p);
void Reader_adv(Reader* p);
char Reader_read(Reader* p);
char* Reader_readString(Reader* p);
int Reader_readInt(Reader* p);

#endif // __reader_h__
