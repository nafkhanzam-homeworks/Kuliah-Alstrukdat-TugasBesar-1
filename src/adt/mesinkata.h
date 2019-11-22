#if !defined(__mesinkata_h__)
#define __mesinkata_h__

#include <stdio.h>
#include "../headers.h"

typedef struct _MesinKata {
    FILE* stream;
    char readChar;
} MesinKata;

MesinKata new_MesinKata();
MesinKata new_FileMesinKata(char* fileName);
void MesinKata_startFile(MesinKata* p, char* fileName);
void MesinKata_ignoreBlank(MesinKata* p);
void MesinKata_adv(MesinKata* p);
char* MesinKata_readString(MesinKata* p);
int MesinKata_readInt(MesinKata* p);
boolean MesinKata_isNonReadableCharacter(MesinKata* p);

#endif // __mesinkata_h__
