#if !defined(__building_h__)
#define __building_h__

#define MAX_LEVEL 4

#include "headers.h"

typedef struct _Building {
    Point* position;
    int armyCount, level, owner;
    char type;
    boolean hasAttacked;
} Building;

Building new_Building(char c, int x, int y, int owner);
void Building_printStatus(Building* p, int number);
void Building_printList(Game* p, List list, char* title);
Building* Building_getBuilding(Game* p, int id);

int Building_getArmyAddition(char type, int level);
int Building_getMaxArmy(char type, int level);
char* Building_getName(char type);
boolean Building_isShielded(char type, int level);
int Building_getStartingArmy(char type);

#endif // __building_h
