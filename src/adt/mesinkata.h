#if !defined(__mesinkata_h__)
#define __mesinkata_h__

#include <stdio.h>
#include "../headers.h"

typedef struct _MesinKata {
    FILE* stream;
    char readChar;
} MesinKata;

MesinKata new_MesinKata();
/*I.S struktur data mesin kata tidak terdefinisi
F.S  mesin kata baru terdefinisi*/
MesinKata new_FileMesinKata(char* fileName);
/*I.S file eksternal tidak terdefinisi dan filename terdefinisi
F.S file eksternal baru terdefinisi dengan  filename sebagai title*/
void MesinKata_startFile(MesinKata* p, char* fileName);
/*I.S file eksternal mesin kata terdefinisi
F.S  membaca mesin kata pada file eksternal siap untuk di proses (di manipulasi stringnya)*/
void MesinKata_ignoreBlank(MesinKata* p);
/*I.S mesin kata terdefinisi
F.S pembacaan mesin kata dengan blank di hapus*/
void MesinKata_adv(MesinKata* p);
/*I.S mesin kata terdefinisi
F.S  mesin kata di baca selanjutnya (next(mesinkata))*/
char* MesinKata_readString(MesinKata* p);
/*I.S mesin kata terdefinisi
F.S  membaca string/return string pada posisi relatif adv*/
int MesinKata_readInt(MesinKata* p);
/*I.S mesin kata terdefinisi
F.S  mesin kata dengan integer di proses/di return pada posisi relatif adv*/
boolean MesinKata_isNonReadableCharacter(MesinKata* p);
/*I.S mesin kata terdefinisi 
F.S  return boolean karakter yang bukan string biasa atau integer*/

#endif // __mesinkata_h__
