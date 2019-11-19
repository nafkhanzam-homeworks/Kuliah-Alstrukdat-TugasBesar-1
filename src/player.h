#if !defined(__player_h__)
#define __player_h__

#include "adt/stack.h"

typedef struct {
    StackOfAct actStack;
    boolean extraTurn, attackUp, criticalHit;
    int shieldTurn;
} Player;

Player new_Player();
Player Player_getEnemyPlayer(Player* p, Game* gp);

#endif // __player_h__
