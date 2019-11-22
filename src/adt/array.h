#if !defined(__array_h__)
#define __array_h__

#include "../headers.h"

typedef struct _Array {
    int length;
    int* tab;
} Array;

Array new_Array(int length);

typedef struct _ArrayOfBuilding {
    int length;
    Building* tab;
} ArrayOfBuilding;

ArrayOfBuilding new_ArrayOfBuilding(int length);

typedef struct _ArrayOfPlayer {
    int length;
    Player* tab;
} ArrayOfPlayer;

ArrayOfPlayer new_ArrayOfPlayer(int length);

#endif // __array_h__
