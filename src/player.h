#if !defined(__player_h__)
#define __player_h__

#include "adt/stack.h"

typedef struct {
    boolean extraTurn, attackUp, criticalHit;
    int shieldTurn;
} Player;

Player new_Player();
Player Player_getCurrentPlayer(Game* p);
Player Player_getEnemyPlayer(Game* p);

#endif // __player_h__
