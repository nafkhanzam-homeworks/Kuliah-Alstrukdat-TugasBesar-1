#if !defined(__player_h__)
#define __player_h__

#include "headers.h"

typedef struct _Player {
    List buildingList;
    Queue* skillQueue;
    int shieldTurn;
    boolean extraTurn, attackUp, criticalHit;
} Player;

Player new_Player();
Player* Player_getCurrentPlayer(Game* p);
Player* Player_getEnemyPlayer(Game* p);
void Player_addSkill(Player* p, int type);

#endif // __player_h__
