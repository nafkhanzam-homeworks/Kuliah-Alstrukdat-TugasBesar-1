#if !defined(__game_h__)
#define __game_h__

typedef struct _Game Game;
#include "headers.h"

typedef struct _Game {
    StackOfAct actStack;
    Matrix map;
    ArrayOfBuilding buildingList;
    Graph buildingGraph;
    ArrayOfPlayer players;
    MesinKata config, command;
    int turn;
    boolean isExiting;
} Game;

Game new_Game();
void Game_init(Game* p);
void Game_initConfig(Game* p);
char* Game_readCommand(Game* p);
void Game_playTurn(Game* p);
void Game_printMap(Game* p);
void Game_printTurnInfo(Game* p);

#endif // __game_h__
