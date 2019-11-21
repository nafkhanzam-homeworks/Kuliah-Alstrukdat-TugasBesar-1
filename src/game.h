#if !defined(__game_h__)
#define __game_h__

#include "selector.h"

#include "adt/matrix.h"
#include "adt/array.h"
#include "adt/graph.h"
#include "adt/boolean.h"
#include "adt/reader.h"
#include "player.h"

typedef struct {
    StackOfAct actStack;
    Matrix map;
    ArrayOfBuilding buildingList;
    Graph buildingGraph;
    Player players[3];
    Reader config, command;
    int turn;
    boolean isExiting;
} Game;

Game new_Game();
void Game_init(Game* p);
void Game_initConfig(Game* p, Reader r);
char* Game_readCommand(Game* p);
void Game_playTurn(Game* p);
void Game_printMap(Game* p);

#endif // __game_h__
