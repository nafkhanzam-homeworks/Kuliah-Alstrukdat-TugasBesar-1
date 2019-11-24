#include "skill.h"

int Skill_getType(char* v) {
    /* ALGORITMA */
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
    /* ALGORITMA */
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
    /* ALGORITMA */
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
    /* KAMUS LOKAL */
    Player* pl;
    List list;
    Building* b;

    /* ALGORITMA */
    pl = Player_getCurrentPlayer(p); // Mendapat player yang sedang mendapat urutan main
    list = buildingList(pl);
    while (list != NULL) { // Iterasi pada setiap bangunan pada list, menambahkan level
        b = Building_getBuilding(p, info(list));
        ++level(b);
        list = next(list);
    }
}

void Skill_shield(Game* p) {
    /* KAMUS LOKAL */
    Player* pl;

    /* ALGORITMA */
    pl = Player_getCurrentPlayer(p);
    shieldTurn(pl) = 2; //Skill disiapkan untuk 2 kali putaran
}

void Skill_extraTurn(Game* p) {
    /* KAMUS LOKAL */
    Player* pl, * en;

    /* ALGORITMA */
    pl = Player_getCurrentPlayer(p);
    extraTurn(pl) = true; // Set status skill ET pada player yang sedang mendapat putaran

    en = Player_getEnemyPlayer(p);
    Player_addSkill(en, NULL, 5, turn(p)); // player lawan mendapat Critical Hit ketika player yang bermain mengaktifkan ET
}

void Skill_attackUp(Game* p) {
    /* KAMUS LOKAL */
    Player* pl;

    /* ALGORITMA */
    pl = Player_getCurrentPlayer(p);
    attackUp(pl) = true; // Mengaktifkan skill AttackUp pada player yang sedang bermain
}

void Skill_criticalHit(Game* p) {
    /* KAMUS LOKAL */
    Player* pl;

    /* ALGORITMA */
    pl = Player_getCurrentPlayer(p);
    criticalHit(pl) = true; // Mengaktifkan skill CriticalHit pada player yang sedang bermain
}

void Skill_instantReinforcement(Game* p) {
    /* KAMUS LOKAL */
    Player* pl;
    List list;
    Building* b;

    /* ALGORITMA */
    pl = Player_getCurrentPlayer(p);
    list = buildingList(pl);
    while (list != NULL) { // Menambahkan 5 pasukan pada tiap bangunan yang dimiliki
        b = Building_getBuilding(p, info(list));
        armyCount(b) += 5;
        list = next(list);
    }
}

void Skill_barrage(Game* p) {
    /* KAMUS LOKAL */
    Player* en;
    List list;
    Building* b;

    /* ALGORITMA */
    en = Player_getEnemyPlayer(p);
    list = buildingList(en);
    while (list != NULL) { // Iterasi pengurangan pasukan sebanyak 10 pada tiap bangunan yang dimiliki
        b = Building_getBuilding(p, info(list));
        armyCount(b) = max(0, armyCount(b) - 10);
        if (!armyCount(b)) {
            owner(b) = 0;
            level(b) = 1;
        }
        list = next(list);
    }
}

void Skill_do(Game* p, int v) {
    /* ALGORITMA */
    switch (v) {
        case 1: Skill_instantUpgrade(p); break;
        case 2: Skill_shield(p); break;
        case 3: Skill_extraTurn(p); break;
        case 4: Skill_attackUp(p); break;
        case 5: Skill_criticalHit(p); break;
        case 6: Skill_instantReinforcement(p); break;
        case 7: Skill_barrage(p); break;
    }
    // Setelah pemakaian skill, Batas Undo menjadi kondisi status setelah pemakaian skill
    // Stack dikosongkan
    StackOfAct_clear(actStack(p));
}
