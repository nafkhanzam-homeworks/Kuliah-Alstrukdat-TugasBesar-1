#if !defined(__building_h__)
#define __building_h__

#include "adt/point.h"

typedef struct {
    char type;
    Point position;
    int armyCount, level, shieldCount, owner;
} Building;

Building new_Building(char c, int x, int y);

#endif // __building_h
