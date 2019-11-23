#include "player.h"

Player new_Player() {
    Player res;
    buildingList(&res) = NULL;
    skillQueue(&res) = (Queue*) malloc(sizeof(Queue));
    *skillQueue(&res) = new_Queue();
    Player_addSkill(&res, 1);
    criticalHit(&res) = false;
    extraTurn(&res) = false;
    shieldTurn(&res) = 0;
    attackUp(&res) = false;
    return res;
}

Player Player_getCurrentPlayer(Game* p) {
    return playersi(p, turn(p));
}

Player Player_getEnemyPlayer(Game* p) {
    int turn = turn(p) == 1 ? 2 : 1;
    return playersi(p, turn);
}

void Player_addSkill(Player* p, int type) {
    if (Queue_getLength(skillQueue(p)) < MAX_QUEUE) {
        Queue_add(skillQueue(p), type);
    }
}
