#if !defined(__building_h__)
#define __building_h__

#define MAX_LEVEL 4

typedef struct _Building Building;
#include "headers.h"

typedef struct _Building {
    char type;
    Point position;
    int armyCount, level, owner;
} Building;

Building new_Building(char c, int x, int y);
boolean Building_levelUp(Building* p);
int Building_getArmyAddition(char type, int level);
int Building_getMaxArmy(char type, int level);
char* Building_getName(char type);
boolean Building_isShielded(char type, int level);
int Building_getStartingArmy(char type);

#endif // __building_h
