#if !defined(__act_h__)
#define __act_h__

#include "selector.h"
#include "adt/selector_adt.h"

#include "adt/boolean.h"
#include "adt/list.h"
#include "game.h"

typedef struct {
    void* target;
    int value, type; // type: -1 = removed from queue, 0 = old value, 1 added to queue
} Ops;

Ops new_Ops(void* target, int value);
Ops new_OpsQueue(void* target, int value);

typedef struct {
    ListOfOps list;
} Act;

Act new_Act();
void Act_addOps(Act* p, Ops v);

void Act_attack(Game* p, int attackerBuildingId, int defenceBuildingId, int val);
void Act_levelUp(Game* p, int buildingId);
void Act_skill(Game* p, int skillType);
void Act_undo(Game* p);
void Act_endTurn(Game* p);
void Act_save(Game* p);
void Act_move(Game* p, int fromBuildingId, int toBuildingId, int val);
void Act_exit(Game* p);
void Act_do(Game* p, char* cmd);

#endif // __act_h__
