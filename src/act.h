#if !defined(__act_h__)
#define __act_h__

typedef struct _Ops Ops;
typedef struct _Act Act;
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
void Act_attack(Game* p, int attackerBuildingId, int defenceBuildingId, int val);
void Act_levelUp(Game* p, int buildingId);
void Act_skill(Game* p, int skillType);
void Act_undo(Game* p);
void Act_endTurn(Game* p);
void Act_save(Game* p);
void Act_move(Game* p, int fromBuildingId, int toBuildingId, int val);
void Act_exit(Game* p);
boolean Act_do(Game* p, char* cmd);

#endif // __act_h__
