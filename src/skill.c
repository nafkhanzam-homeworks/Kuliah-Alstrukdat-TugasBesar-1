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
    for(int i=1 ; i<=((*p).buildingList).length ; i++){
        if((((*p).buildingList).tab[i]).owner==(*p).turn && (((*p).buildingList).tab[i]).level<4){
            (((*p).buildingList).tab[i]).level+=1;
        }
    }
}

void Skill_shield(Game* p) {
    Player pl = Player_getCurrentPlayer(p);
    shieldTurn(&pl) = 2;
}

void Skill_extraTurn(Game* p) {
    Player pl = Player_getCurrentPlayer(p);
    extraTurn(&pl) = true;
}

void Skill_attackUp(Game* p) {
    Player pl = Player_getCurrentPlayer(p);
    attackUp(&pl) = true;
}

void Skill_criticalHit(Game* p) {
    Player pl = Player_getCurrentPlayer(p);
    criticalHit(&pl) = true;
}

void Skill_instantReinforcement(Game* p) {
    for(int i=1 ; i<=((*p).buildingList).length ; i++){
        if((((*p).buildingList).tab[i]).owner==(*p).turn){
            // armyCount((((*p).buildingList).tab[i]))+=5;
        }
    }
}

void Skill_barrage(Game* p) {
    int own;
    if(turn(p)==1){
        own=2;
    }
    else own=1;
    for(int i=1 ; i<=((*p).buildingList).length ; i++){
        if((((*p).buildingList).tab[i]).owner==own){
            // armyCount((((*p).buildingList).tab[i]))-=10;
            // if(armyCount((((*p).buildingList).tab[i]))==0){
            //     (((*p).buildingList).tab[i]).owner=0;
            // }
        }
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
    StackOfAct_clear(&actStack(p));
}
