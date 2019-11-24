#include "player.h"

Player new_Player() {
    /* KAMUS LOKAL */
    Player res;

    /* ALGORITMA */
    buildingList(&res) = NULL; // Menyiapkan list bangunan


    skillQueue(&res) = (Queue*) malloc(sizeof(Queue)); // Menyiapkan & alokasi queue untuk skill
    *skillQueue(&res) = new_Queue();
    
    Player_addSkill(&res, 1); // Menambahkan skill awal IU
    
    /* Set status skill yang sedang dipakai */
    criticalHit(&res) = false;
    extraTurn(&res) = false;
    shieldTurn(&res) = 0;
    attackUp(&res) = false;
    return res;
}

Player* Player_getCurrentPlayer(Game* p) {
    /* ALGORITMA */
    return &playersi(p, turn(p));
}

Player* Player_getEnemyPlayer(Game* p) {
    /* ALGORITMA */
    return &playersi(p, enemyIndex(turn(p)));
}

void Player_addSkill(Player* p, int type) {
    /* ALGORITMA */
    if (Queue_getLength(skillQueue(p)) < MAX_QUEUE) {
        Queue_add(skillQueue(p), type);
    }
}
