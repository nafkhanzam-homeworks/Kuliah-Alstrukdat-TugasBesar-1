#include "skill.h"

int Skill_getType(char* v) {
    if (compareString(v, "IU")) {
        return 1;
    } else if (compareString(v, "S")) {
        return 2;
    } else if (compareString(v, "ET")) {
        return 3;
    } else if (compareString(v, "AU")) {
        return 4;
    } else if (compareString(v, "CH")) {
        return 5;
    } else if (compareString(v, "IR")) {
        return 6;
    } else if (compareString(v, "B")) {
        return 7;
    }
    return -1;
}

char* Skill_getName(int v) {
    switch (v) {
        case 1: return "Instant Upgrade";
        case 2: return "Shield";
        case 3: return "Extra Turn";
        case 4: return "Attack Up";
        case 5: return "Critical Hit";
        case 6: return "Instant Reinforcement";
        case 7: return "Barrage";
    }
    return NULL;
}

char* Skill_getAcronym(int v) {
    switch (v) {
        case 1: return "IU";
        case 2: return "S";
        case 3: return "ET";
        case 4: return "AU";
        case 5: return "CH";
        case 6: return "IR";
        case 7: return "B";
    }
    return NULL;
}


void Skill_instantUpgrade(Game* p) {
    Player* pl = Player_getCurrentPlayer(p);
    List list = buildingList(pl);
    while (list != NULL) {
        Building* b = Building_getBuilding(p, info(list));
        ++level(b);
        list = next(list);
    }
}

void Skill_shield(Game* p) {
    Player* pl = Player_getCurrentPlayer(p);
    shieldTurn(pl) = 2;
}

void Skill_extraTurn(Game* p) {
    Player* pl = Player_getCurrentPlayer(p);
    extraTurn(pl) = true;
    Player* en = Player_getEnemyPlayer(p);
    Player_addSkill(en, 5);
}

void Skill_attackUp(Game* p) {
    Player* pl = Player_getCurrentPlayer(p);
    attackUp(pl) = true;
}

void Skill_criticalHit(Game* p) {
    Player* pl = Player_getCurrentPlayer(p);
    criticalHit(pl) = true;
}

void Skill_instantReinforcement(Game* p) {
    Player* pl = Player_getCurrentPlayer(p);
    List list = buildingList(pl);
    while (list != NULL) {
        Building* b = Building_getBuilding(p, info(list));
        armyCount(b) += 5;
        list = next(list);
    }
}

void Skill_barrage(Game* p) {
    Player* en = Player_getEnemyPlayer(p);
    List list = buildingList(en);
    while (list != NULL) {
        Building* b = Building_getBuilding(p, info(list));
        armyCount(b) = max(0, armyCount(b) - 10);
        if (!armyCount(b)) {
            owner(b) = 0;
        }
        list = next(list);
    }
}

void Skill_do(Game* p, int v) {
    switch (v) {
        case 1: Skill_instantUpgrade(p);
        case 2: Skill_shield(p);
        case 3: Skill_extraTurn(p);
        case 4: Skill_attackUp(p);
        case 5: Skill_criticalHit(p);
        case 6: Skill_instantReinforcement(p);
        case 7: Skill_barrage(p);
    }
    StackOfAct_clear(actStack(p));
}
