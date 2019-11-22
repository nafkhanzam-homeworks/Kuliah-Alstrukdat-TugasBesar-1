#if !defined(__player_h__)
#define __player_h__

typedef struct _Player Player;
#include "headers.h"

typedef struct _Player {
    List buildingList;
    Queue skillQueue;
    int shieldTurn;
    boolean extraTurn, attackUp, criticalHit;
} Player;

Player new_Player();
Player Player_getCurrentPlayer(Game* p);
Player Player_getEnemyPlayer(Game* p);

#endif // __player_h__
