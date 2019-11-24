#include "act.h"

Ops new_Ops(void* target, int value) {
    /* KAMUS LOKAL */
    Ops res;

    /* ALGORITMA */
    target(&res) = target;
    value(&res) = value;
    type(&res) = false;
    return res;
}

Ops new_OpsDefault(void* target) {
    /* ALGORITMA */
    return new_Ops(target, *(int*)target);
}

Ops new_OpsQueue(void* target, int value, boolean add) {
    /* KAMUS LOKAL */
    Ops res;

    /* ALGORITMA */
    res = new_Ops(target, value);
    type(&res) = add ? 1 : -1; 
    return res;
}

Ops new_OpsList(void* target, int value, boolean add) {
    /* KAMUS LOKAL */
    Ops res;

    /* ALGORITMA */
    res = new_Ops(target, value);
    type(&res) = add ? 2 : -2;
    return res;
}

Act new_Act() {
    /* KAMUS LOKAL */
    Act res;

    /* ALGORITMA */
    list(&res) = NULL;
    return res;
}

void Act_addOps(Act* p, Ops v) {
    /* ALGORITMA */
    ListOfOps_addFirst(&list(p), v);
}

boolean Act_isEmpty(Act* p) {
    /* ALGORITMA */
    return ListOfOps_isEmpty(&list(p));
}

// TODO: DON'T FORGET OPS EACH OPERATION
void Act_changeTheOwnership(Game* p, Act* act, int buildingId) {
    /* KAMUS LOKAL */
    int fromBLengthBefore,toBLengthBefore;
    Building b;
    Player from, to;

    /* ALGORITMA */
    b = Building_getBuilding(p, buildingId);
    from = playersi(p, owner(&b));
    to = playersi(p, owner(&b)%2 + 1);

    fromBLengthBefore = List_getLength(&buildingList(&from));
    toBLengthBefore = List_getLength(&buildingList(&to));

    Act_addOps(act, new_OpsDefault(&owner(&b))); owner(&b) = owner(&b)%2 + 1; // Ganti owner bangunan
    Act_addOps(act, new_OpsList(&buildingList(&from), buildingId, false)); List_remove(&buildingList(&from), buildingId); // hapus bangunan di list bangunan owner
    Act_addOps(act, new_OpsList(&buildingList(&to), buildingId, true)); List_addLast(&buildingList(&to), buildingId); // tambahkan bangunan pada list owner baru

    // Penambahan skill sesuai kondisi penambahan bangunan

    if (fromBLengthBefore == 3) { // 3 -> 2
        Player_addSkill(&from, 2);
    }
    if (type(&b) == 'F') {
        Player_addSkill(&from, 3);
    }
    if (toBLengthBefore == 2) { // 2 -> 3
        Player_addSkill(&to, 4);
    }
    if (toBLengthBefore == 9) {
        Player_addSkill(&from, 7);
    }
}

void Act_getTheOwnership(Game* p, Act* act, int buildingId, int toOwner) {
    Building b = Building_getBuilding(p, buildingId);
    Player to = playersi(p, toOwner), en = playersi(p, toOwner%2 + 1);

    int toBLengthBefore = List_getLength(&buildingList(&to));

    Act_addOps(act, new_OpsDefault(&owner(&b))); owner(&b) = toOwner;
    Act_addOps(act, new_OpsList(&buildingList(&to), buildingId, true)); List_addLast(&buildingList(&to), buildingId);

    if (toBLengthBefore == 9) {
        Player_addSkill(&en, 7);
    }
}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_attack(Game* p, Act* act, int attackerBuildingId, int defenderBuildingId, int val) {
    /*  KAMUS LOKAL */
    int attackOutput, damageInput;
    boolean countDefend;
    Player pl = Player_getCurrentPlayer(p);
    Player en = Player_getEnemyPlayer(p);
    Building attacker = Building_getBuilding(p, attackerBuildingId);
    Building defender = Building_getBuilding(p, defenderBuildingId);

    /* ALGORITMA */
    Act_addOps(act, new_OpsDefault(&hasAttacked(&attacker))); hasAttacked(&attacker) = true;

    // TODO: Still a pure attack, no implementation of shield or attack up or etc
    attackOutput = val;
    damageInput = val;
    // cek kondisi pertahanan lawan
    countDefend = (owner(&defender) == 0 && Building_isShielded(type(&defender), level(&defender))
                        || shieldTurn(&en)) && !(attackUp(&pl) || criticalHit(&pl));
    if (countDefend) {
        if (damageInput*3/4 < armyCount(&defender)) {
            damageInput = damageInput - armyCount(&defender)/3;
        } else {
            damageInput = damageInput*3/4;
        }
    }
    if (criticalHit(&pl)) {
        damageInput <<= 2;
    }
    Act_addOps(act, new_OpsDefault(&armyCount(&attacker))); armyCount(&attacker) -= attackOutput;
    Act_addOps(act, new_OpsDefault(&armyCount(&defender))); armyCount(&defender) -= damageInput;
    if (criticalHit(&pl)) {
        armyCount(&defender) <<= 2;
    }

    if (armyCount(&defender) <= 0) {
        armyCount(&defender) = -armyCount(&defender);
        Act_changeTheOwnership(p, act, defenderBuildingId);
        printf("The building has just became yours!\n");
    }
    return true;
}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_levelUp(Game* p, Act* act, int buildingId) {
    /* KAMUS LOKAL */
    Building b;

    /* ALGORITMA */
    b = Building_getBuilding(p, buildingId);
    Act_addOps(act, new_OpsDefault(&armyCount(&b))); armyCount(&b) <<= 2; // Pengurangan jumlah pasukan
    Act_addOps(act, new_OpsDefault(&level(&b))); ++level(&b); // Penambahan level
    return true;
}

boolean Act_skill(Game* p, int skillType) {
    /* ALGORITMA */
    Skill_do(p, skillType); // Mengaplikasikan skill sesuai tipenya
    return true;
}

boolean Act_undo(Game* p) {
    /* KAMUS LOKAL */
    Act act;
    ListOfOps list;
    Ops* ops;

    /* ALGORITMA */
    act = StackOfAct_pop(actStack(p));
    list = list(&act);
    while (list != NULL) { // iterasi sampai list operasi habis(pemakaian skill atau endturn)
        ops = info(list);
        switch (type(ops)) {
            case -2: { // menambahkan status operasi pada list
                List_addFirst((List*)target(ops), value(ops));
                break;
            }
            case -1: { // menambahkan queue
                Queue_add((Queue*)target(ops), value(ops));
                break;
            }
            case 0: { 
                *((int*)target(ops)) = value(ops);
            }
            case 1: { // menghapus queue operasi
                Queue_remove((Queue*)target(ops));
                break;
            }
            case 2: { // menghapus list operasi
                List_removeFirst((List*)target(ops));
                break;
            }
        }
        list = next(list);
    }
}

boolean Act_endTurn(Game* p) {
    /* ALGORITMA */
    Game_endTurn(p);
    return true;
}

boolean Act_save(Game* p, char* fileName) {
    /* KAMUS LOKAL */
    FILE* file;
    Building b;
    List list;

    /* ALORITMA */
    file = fopen(fileName, "w");
    fprintf(file, "%d %d\n", ROW(p), COL(p)); // simpan ukuran map
    fprintf(file, "%d\n", N(p)); // simpan banyak bangunan
    for (int i = 1; i <= N(p); ++i) { // simpan data bangunan (jenis, posisi)
        b = Building_getBuilding(p, i);
        fprintf(file, "%c %d %d\n", type(&b), x(position(&b)), y(position(&b)));
    }
    for (int i = 1; i <= N(p); ++i) {  // simpan keterkaitan antar bangunan
        list = ListOfList_getAt(&list(buildingGraph(p)), i);
        for (int j = 1; j <= N(p); ++j) {
            fprintf(file, "%d%s", List_contains(&list, j) ? 1 : 0, j == N(p) ? "\n" : " ");
        }
    }
    fprintf(file, "%d\n", turn(p)); // simpan yang giliran permainan terakhir
    for (int i = 1; i <= N(p); ++i) { // simpan data bangunan (pemilik, level, dan jumlah pasukan)
        b = Building_getBuilding(p, i);
        fprintf(file, "%d %d %d\n", owner(&b), level(&b), armyCount(&b));
    }
    fclose(file);
    return true;
}

// TODO: DON'T FORGET OPS EACH OPERATION
boolean Act_move(Game* p, Act* act, int fromBuildingId, int toBuildingId, int val){
    /* KAMUS LOKAL */
    Building from, to;

    /* ALGORITMA */
    from = ListOfBuilding_getAt(&buildingList(p), fromBuildingId);
    to = ListOfBuilding_getAt(&buildingList(p), fromBuildingId);

    // pasukan bangunan asal berkurang
    Act_addOps(act, new_OpsDefault(&armyCount(&from)));
    armyCount(&from) -= val;

    // pasukan bangunan tujuan bertambah
    Act_addOps(act, new_OpsDefault(&armyCount(&to)));
    armyCount(&to) += val;

    return true;
}

boolean Act_exit(Game* p) {
    /* ALGORITMA */
    return isExiting(p) = true;
}

boolean Act_do(Game* p, char* cmd) {
    /* KAMUS LOKAL */
    boolean success;
    Act act;
    Player pl;
    Building b;
    List list;
    int attackId, defenceId, buildingId;

    // Inisiasi awal Aksi dan Player
    success = true;
    act = new_Act();
    pl = Player_getCurrentPlayer(p);

    toLowerCase(cmd); // mengubah element string kapital menjadi lowercase
    if (compareString(cmd, "attack")) {
        list = Game_getAttackableBuildings(p);

        // Kondisi semua bangunan yang dimiliki player telah digunakan untuk menyerang
        if (List_isEmpty(&list)) {
            printf("All of your buildings have been used to attack at least once!\n");
            return false;
        }

        // cetak list bangunan yang masih dapat digunakan untuk menyerang
        Building_printList(p, list, "Building List (haven't been used to attack):");
        // pilih nomor bangunan yang akan digunakan  menyerang, dapatkan ID bangunan yang dipilih
        attackId = Game_readCommandInt(p, "Choose building number to use: ", 1, List_getLength(&list));
        attackId = List_getAt(&list, attackId);

        // mencari bangunan yang memiliki keterhubungan dengan bangunan yang dipilih
        List bIndexList = Game_getAdjencyBuildings(p, attackId, true);
        if (List_isEmpty(&bIndexList)) {
            printf("You don't have any adjency enemy building!\n");
            return false;
        }
        // cetak list bangunan yang dapat diserang
        Building_printList(p, bIndexList, "Building List:");
        // pilih nomor bangunan yang ingin diserang, dapatkan IDnya 
        defenceId = Game_readCommandInt(p, "Choose building number to attack: ", 1, List_getLength(&bIndexList));
        defenceId = List_getAt(&bIndexList, defenceId);

        // input jumlah pasukn yang ingin dikerahkan
        int val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        Building attacker = ListOfBuilding_getAt(&buildingList(p), attackId);
        while (val < 0 || val > armyCount(&attacker)) {
            printf(val < 0 ? "Army count have to be above zero!" : "You only have %d army in that building!\n", armyCount(&attacker));
            val = Game_readCommandInt(p, "Input the amount of army to attack: ", 0, -1);
        }

        // Serang !!
        success = Act_attack(p, &act, attackId, defenceId, val);

    } else if (compareString(cmd, "level_up")) {
        
        // menyiapkan list bangunan
        list = buildingList(&pl);

        // mancetak daftar bangunan, pilih nomor bangunan yang ingin dinaikkan levelnya
        Building_printList(p, list, "Building List:");
        buildingId = Game_readCommandInt(p, "Choose building number to level up: ", 1, List_getLength(&list));
        buildingId = List_getAt(&list, buildingId);

        // kondisi bangunan telah mencapai level maksimal
        b = Building_getBuilding(p, buildingId);
        if (level(&b) >= MAX_LEVEL) {
            printf("That building is already at max level!\n");
            return false;
        }

        // tambah level bangunan b
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
