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

boolean Act_isEmpty(Act* p) {
    return ListOfOps_isEmpty(list(p));
}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_attack(Game* p, Act* act, int attackerBuildingId, int defenceBuildingId, int val) {
    
}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_levelUp(Game* p, Act* act, int buildingId) {
    
}

boolean Act_skill(Game* p, int skillType) {
    Skill_do(p, skillType);
    return true;
}

boolean Act_undo(Game* p) {
    Act act = StackOfAct_pop(actStack(p));
    ListOfOps list = list(&act);
    while (list != NULL) {
        Ops* ops = info(list);
        switch (type(ops)) {
            case -2: {
                List_addFirst((List*)target(ops), value(ops));
                break;
            }
            case -1: {
                Queue_add((Queue*)target(ops), value(ops));
                break;
            }
            case 0: {
                *((int*)target(ops)) = value(ops);
            }
            case 1: {
                Queue_remove((Queue*)target(ops));
                break;
            }
            case 2: {
                List_removeFirst((List*)target(ops));
                break;
            }
        }
        list = next(list);
    }
}

boolean Act_endTurn(Game* p) {
    Game_endTurn(p);
    return true;
}

boolean Act_save(Game* p, char* fileName) {

}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_move(Game* p, Act* act, int fromBuildingId, int toBuildingId, int val) {
    Building from = ListOfBuilding_getAt(buildingList(p), fromBuildingId);
    Building to = ListOfBuilding_getAt(buildingList(p), fromBuildingId);

}

boolean Act_exit(Game* p) {
    return isExiting(p) = true;
}

boolean Act_do(Game* p, char* cmd) {
    boolean success = true;
    Act act = new_Act();
    toLowerCase(cmd);
    Player pl = Player_getCurrentPlayer(p);
    if (compareString(cmd, "attack")) {
        List list = buildingList(&pl);

        int attackId = Game_readCommandInt(p, "Choose building number to use: ", 1, List_getLength(&list));
        attackId = List_getAt(&list, attackId);

        List bIndexList = Game_getAdjencyBuildings(p, attackId, true);
        int i = 0;
        printf("Building List:\n");
        while (bIndexList != NULL) {
            Building b = ListOfBuilding_getAt(&buildingList(p), info(bIndexList));
            Building_printStatus(&b, ++i);
            bIndexList = next(bIndexList);
        }

        int defenceId = Game_readCommandInt(p, "Choose building number to attack: ", 1, List_getLength(&bIndexList));
        defenceId = List_getAt(&bIndexList, defenceId);

        int val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        Building attacker = ListOfBuilding_getAt(buildingList(p), attackId);
        while (val < 0 || val > armyCount(&attacker)) {
            printf(val < 0 ? "Army count have to be above zero!" : "You only have %d army in that building!\n", armyCount(&attacker));
            val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        }
        success = Act_attack(p, &act, attackId, defenceId, val);
    } else if (compareString(cmd, "level_up")) {
        
    } else if (compareString(cmd, "skill")) {
        Queue* skillQueue = skillQueue(&pl);
        if (Queue_isEmpty(skillQueue)) {
            printf("You don't have any skill left!");
            return true;
        }
        success = Act_skill(p, Queue_remove(skillQueue));
    } else if (compareString(cmd, "undo")) {
        success = Act_undo(p);
    } else if (compareString(cmd, "end_turn")) {
        success = Act_endTurn(p);
    } else if (compareString(cmd, "save")) {
        char* fileName = Game_readCommand(p, "Input filename (without space): ");
        success = Act_save(p, fileName);
    } else if (compareString(cmd, "move")) {
        List list = buildingList(&pl);

        int fromId = Game_readCommandInt(p, "Choose building number to move from: ", 1, List_getLength(&list));
        fromId = List_getAt(&list, fromId);

        List bIndexList = Game_getAdjencyBuildings(p, fromId, false);
        int i = 0;
        while (bIndexList != NULL) {
            Building b = ListOfBuilding_getAt(&buildingList(p), info(bIndexList));
            Building_printStatus(&b, ++i);
            bIndexList = next(bIndexList);
        }

        int toId = Game_readCommandInt(p, "Choose building number to move to: ", 1, List_getLength(&bIndexList));
        toId = List_getAt(&bIndexList, toId);

        int val = Game_readCommandInt(p, "Input the amount of army to move: ", 0, -1);
        Building from = ListOfBuilding_getAt(buildingList(p), fromId);
        while (val < 0 || val > armyCount(&from)) {
            printf(val < 0 ? "Army count have to be above zero!" : "You only have %d army in that building!\n", armyCount(&from));
            val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        }
        success = Act_move(p, &act, fromId, toId, val);
    } else if (compareString(cmd, "exit")) {
        printf("Bye-bye!\n");
        success = Act_exit(p);
    } else {
        printf("%s\n", "Command not found!");
        success = false;
    }
    if (!Act_isEmpty(&act)) {
        StackOfAct_push(&actStack(p), act);
    }
    return success;
}
