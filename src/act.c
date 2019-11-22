#include "act.h"

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
    Skill_do(p, skillType);
}

void Act_undo(Game* p) {
    Act act = StackOfAct_pop(&actStack(p));
    ListOfOps list = list(&act);
    while (list != NULL) {
        Ops ops = info(list);
        switch (type(&ops)) {
            case -1: {
                Queue_add((Queue*)target(&ops), value(&ops));
                break;
            }
            case 0: {
                *((int*)target(&ops)) = value(&ops);
            }
            case 1: {
                Queue_remove((Queue*)target(&ops));
                break;
            }
        }
        list = next(list);
    }
}

void Act_endTurn(Game* p) {
    
}

void Act_save(Game* p) {
    
}

void Act_move(Game* p, int fromBuildingId, int toBuildingId, int val) {
    
}

void Act_exit(Game* p) {
    isExiting(p) = true;
}

boolean Act_do(Game* p, char* cmd) {
    toLowerCase(cmd);
    if (compareString(cmd, "attack")) {

    } else if (compareString(cmd, "level_up")) {

    } else if (compareString(cmd, "skill")) {

    } else if (compareString(cmd, "undo")) {
        Act_undo(p);
    } else if (compareString(cmd, "end_turn")) {

    } else if (compareString(cmd, "save")) {
        
    } else if (compareString(cmd, "move")) {

    } else if (compareString(cmd, "exit")) {
        Act_exit(p);
    } else {
        printf("%s\n", "Command not found!");
        return false;
    }
    return true;
}
