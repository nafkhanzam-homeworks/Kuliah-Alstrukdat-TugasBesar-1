#if !defined(__game_h__)
#define __game_h__

#include "adt/matrix.h"
#include "adt/array.h"
#include "adt/graph.h"
#include "adt/boolean.h"
#include "player.h"

typedef struct {
    Matrix map;
    ArrayOfBuilding buildingList;
    Graph buildingGraph;
    Player players[3];
    int turn;
    boolean isExiting;
} Game;

Game new_Game();
void Game_play(Game* p);

#endif // __game_h__
