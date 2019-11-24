#if !defined(__array_h__)
#define __array_h__

#include "../headers.h"

typedef struct _Array {
    int length;
    int* tab;
} Array;

Array new_Array(int length);
// I.S array belum terdefinisi, F.S array dengan panjang length

typedef struct _ArrayOfBuilding {
    int length;
    Building* tab;
} ArrayOfBuilding;

ArrayOfBuilding new_ArrayOfBuilding(int length);
// I.S array bangunan belum terdefinisi, F.S array bangunan dengan panjang length dan elemen menyimpan bangunan

typedef struct _ArrayOfPlayer {
    int length;
    Player* tab;
} ArrayOfPlayer;

ArrayOfPlayer new_ArrayOfPlayer(int length);
// I.S array player belum terdefinisi, F.S array player dengan panjang length dan elemen menyimpan player


#endif // __array_h__

