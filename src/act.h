#if !defined(__act_h__)
#define __act_h__

#include "headers.h"

typedef struct _Ops {
    void* target;
    int value, type; // type: -2 = removed from list, -1 = removed from queue, 0 = old value, 1 = added to queue, 2 = added to list
} Ops;

Ops new_Ops(void* target, int value);
Ops new_OpsQueue(void* target, int value, boolean add);

typedef struct _Act {
    ListOfOps list;
} Act;

Act new_Act();
void Act_addOps(Act* p, Ops v);
boolean Act_attack(Game* p, int attackerBuildingId, int defenceBuildingId, int val);
boolean Act_levelUp(Game* p, int buildingId);
boolean Act_skill(Game* p, int skillType);
boolean Act_undo(Game* p);
boolean Act_endTurn(Game* p);
boolean Act_save(Game* p);
boolean Act_move(Game* p, int fromBuildingId, int toBuildingId, int val);
boolean Act_exit(Game* p);
boolean Act_do(Game* p, char* cmd);

#endif // __act_h__
