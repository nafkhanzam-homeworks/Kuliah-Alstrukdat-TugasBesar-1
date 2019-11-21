#include "act.h"

#include <stdlib.h>

Ops new_Ops(void* target, int value) {
    Ops res;
    target(&res) = target;
    value(&res) = value;
    type(&res) = false;
    return res;
}

Ops new_OpsQueue(void* target, int value, boolean add) {
    Ops res = new_Ops(target, value);
    type(&res) = add ? 1 : -1;
    return res;
}

Act new_Act() {
    Act res;
    list(&res) = NULL;
    return res;
}

void Act_addOps(Act* p, Ops v) {
    ListOfOps_addFirst(&list(p), v);
}

void Act_attack(Game* p, int attackerBuildingId, int defenceBuildingId, int val) {
    
}

void Act_levelUp(Game* p, int buildingId) {
    
}

void Act_skill(Game* p, int skillType) {
    
}

void Act_undo(Game* p) {
    
}

void Act_endTurn(Game* p) {
    
}

void Act_save(Game* p) {
    
}

void Act_move(Game* p, int fromBuildingId, int toBuildingId, int val) {
    
}

void Act_exit(Game* p) {
    
}

void Act_do(Game* p, char* cmd) {
    
}
