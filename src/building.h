#if !defined(__building_h__)
#define __building_h__

#include "selector.h"

#include "adt/point.h"
#include "adt/boolean.h"

#define MAX_LEVEL 4

typedef struct {
    char type;
    Point position;
    int armyCount, level, shieldCount, owner;
} Building;

Building new_Building(char c, int x, int y);
boolean Building_levelUp(Building* p);
int Building_getArmyAddition(char type, int level);
int Building_getMaxArmy(char type, int level);
char* Building_getName(char type);
boolean Building_isShielded(char type, int level);
int Building_getStartingArmy(char type);

#endif // __building_h
