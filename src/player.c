#include "player.h"

Player new_Player() {
    Player res;
    buildingList(&res) = NULL;
    skillQueue(&res) = (Queue*) malloc(sizeof(Queue));
    *skillQueue(&res) = new_Queue();
    Queue_add(skillQueue(&res), 1);
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
