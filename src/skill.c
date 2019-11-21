#include "skill.h"

#include <stdlib.h>
#include "utils/utils.h"

int Skill_getType(char* v) {
    if (strcmp(v, "IU")) {
        return 1;
    } else if (strcmp(v, "S")) {
        return 2;
    } else if (strcmp(v, "ET")) {
        return 3;
    } else if (strcmp(v, "AU")) {
        return 4;
    } else if (strcmp(v, "CH")) {
        return 5;
    } else if (strcmp(v, "IR")) {
        return 6;
    } else if (strcmp(v, "B")) {
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

char* Skill_getvonym(int v) {
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
    
}

void Skill_shield(Game* p) {
    
}

void Skill_extraTurn(Game* p) {
    
}

void Skill_attackUp(Game* p) {
    
}

void Skill_criticalHit(Game* p) {
    
}

void Skill_instantReinforcement(Game* p) {
    
}

void Skill_barrage(Game* p) {
    
}

void Skill_do(Game* p, int v) {
    switch (v) {
        case 1: return instantUpgrade_Skil(p);
        case 2: return shield_Skil(p);
        case 3: return extraTurn_Skil(p);
        case 4: return attackUp_Skil(p);
        case 5: return criticalHit_Skil(p);
        case 6: return instantReinforcement_Skil(p);
        case 7: return barrage_Skil(p);
    }
}
