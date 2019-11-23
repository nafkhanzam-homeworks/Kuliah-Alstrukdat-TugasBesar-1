#include "act.h"

Ops new_Ops(void* target, int value) {
    Ops res;
    target(&res) = target;
    value(&res) = value;
    type(&res) = false;
    return res;
}

Ops new_OpsDefault(void* target) {
    return new_Ops(target, *(int*)target);
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
    return ListOfOps_isEmpty(&list(p));
}

void Act_changeTheOwnership(Game* p, Act* act, int buildingId) {
    Building b = Building_getBuilding(p, buildingId);
    Act_addOps(act, new_OpsDefault(&owner(&b))); owner(&b) = owner(&b)%2 + 1;
}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_attack(Game* p, Act* act, int attackerBuildingId, int defenderBuildingId, int val) {
    Building attacker = Building_getBuilding(p, attackerBuildingId);
    Building defender = Building_getBuilding(p, defenderBuildingId);

    // TODO: Still a pure attack, no implementation of shield or attack up or etc
    Act_addOps(act, new_OpsDefault(&armyCount(&attacker))); armyCount(&attacker) -= val;
    Act_addOps(act, new_OpsDefault(&armyCount(&defender))); armyCount(&defender) -= val;
    if (armyCount(&defender) <= 0) {
        armyCount(&defender) = -armyCount(&defender);
        Act_changeTheOwnership(p, act, defenderBuildingId);
    }
}

boolean Act_levelUp(Game* p, Act* act, int buildingId) {
    Building b = Building_getBuilding(p, buildingId);
    Act_addOps(act, new_OpsDefault(&armyCount(&b))); armyCount(&b) <<= 2;
    Act_addOps(act, new_OpsDefault(&level(&b))); ++level(&b);
    return true;
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
    FILE* file = fopen(fileName, "w");
    fprintf(file, "%d %d\n", ROW(p), COL(p));
    fprintf(file, "%d\n", N(p));
    for (int i = 1; i <= N(p); ++i) {
        Building b = Building_getBuilding(p, i);
        fprintf(file, "%c %d %d\n", type(&b), x(position(&b)), y(position(&b)));
    }
    for (int i = 1; i <= N(p); ++i) {
        List list = ListOfList_getAt(&list(buildingGraph(p)), i);
        for (int j = 1; j <= N(p); ++j) {
            fprintf(file, "%d%s", List_contains(&list, j) ? 1 : 0, j == N(p) ? "\n" : " ");
        }
    }
    fprintf(file, "%d\n", turn(p));
    for (int i = 1; i <= N(p); ++i) {
        Building b = Building_getBuilding(p, i);
        fprintf(file, "%d %d %d\n", owner(&b), level(&b), armyCount(&b));
    }
    fclose(file);
    return true;
}

boolean Act_move(Game* p, Act* act, int fromBuildingId, int toBuildingId, int val) {
    Building from = ListOfBuilding_getAt(&buildingList(p), fromBuildingId);
    Building to = ListOfBuilding_getAt(&buildingList(p), fromBuildingId);

    Act_addOps(act, new_OpsDefault(&armyCount(&from)));
    armyCount(&from) -= val;

    Act_addOps(act, new_OpsDefault(&armyCount(&to)));
    armyCount(&to) += val;

    return true;
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

        Building_printList(p, list, "Building List:");
        int attackId = Game_readCommandInt(p, "Choose building number to use: ", 1, List_getLength(&list));
        attackId = List_getAt(&list, attackId);

        List bIndexList = Game_getAdjencyBuildings(p, attackId, true);
        if (List_isEmpty(&bIndexList)) {
            printf("You don't have any adjency enemy building!\n");
            return false;
        }
        Building_printList(p, bIndexList, "Building List:");

        int defenceId = Game_readCommandInt(p, "Choose building number to attack: ", 1, List_getLength(&bIndexList));
        defenceId = List_getAt(&bIndexList, defenceId);

        int val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        Building attacker = ListOfBuilding_getAt(&buildingList(p), attackId);
        while (val < 0 || val > armyCount(&attacker)) {
            printf(val < 0 ? "Army count have to be above zero!" : "You only have %d army in that building!\n", armyCount(&attacker));
            val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        }

        success = Act_attack(p, &act, attackId, defenceId, val);
    } else if (compareString(cmd, "level_up")) {
        List list = buildingList(&pl);

        Building_printList(p, list, "Building List:");
        int buildingId = Game_readCommandInt(p, "Choose building number to level up: ", 1, List_getLength(&list));
        buildingId = List_getAt(&list, buildingId);

        Building b = Building_getBuilding(p, buildingId);
        if (level(&b) >= MAX_LEVEL) {
            printf("That building is already at max level!\n");
            return false;
        }

        success = Act_levelUp(p, &act, buildingId);
    } else if (compareString(cmd, "skill")) {
        Queue* skillQueue = skillQueue(&pl);
        if (Queue_isEmpty(skillQueue)) {
            printf("You don't have any skill!");
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

        Building_printList(p, list, "Building List:");
        int fromId = Game_readCommandInt(p, "Choose building number to move from: ", 1, List_getLength(&list));
        fromId = List_getAt(&list, fromId);

        List bIndexList = Game_getAdjencyBuildings(p, fromId, false);
        if (List_isEmpty(&bIndexList)) {
            printf("You don't have any adjency building!\n");
            return false;
        }
        Building_printList(p, bIndexList, "Building List:");

        int toId = Game_readCommandInt(p, "Choose building number to move to: ", 1, List_getLength(&bIndexList));
        toId = List_getAt(&bIndexList, toId);

        Building from = ListOfBuilding_getAt(&buildingList(p), fromId);
        int val = Game_readCommandInt(p, "Input the amount of army to move: ", 0, -1);
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
        StackOfAct_push(actStack(p), act);
    }
    if (success) {
        printf("The command has been done successfully!\n");
    }
    return success;
}
