#if !defined(__building_h__)
#define __building_h__

#define MAX_LEVEL 4

#include "headers.h"

typedef struct _Building {
    Point* position;
    int armyCount, level, owner;
    char type;
} Building;

Building new_Building(char c, int x, int y, int owner);
boolean Building_levelUp(Building* p);
void Building_printStatus(Building* p, int number);
void Building_setOwner(Building* p, Game* gp, int toOwner);

int Building_getArmyAddition(char type, int level);
int Building_getMaxArmy(char type, int level);
char* Building_getName(char type);
boolean Building_isShielded(char type, int level);
int Building_getStartingArmy(char type);

#endif // __building_h
