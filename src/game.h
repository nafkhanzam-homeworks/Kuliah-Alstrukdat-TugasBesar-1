#if !defined(__game_h__)
#define __game_h__

#include "headers.h"

typedef struct _Game {
    StackOfAct* actStack;
    Matrix* map;
    ListOfBuilding buildingList;
    Graph* buildingGraph;
    ArrayOfPlayer* players;
    MesinKata* config;
    MesinKata* command;
    int turn, N, ROW, COL;
    boolean isExiting;
} Game;

Game new_Game();
void Game_init(Game* p);
void Game_initConfig(Game* p);
void Game_initConfig2(Game* p);
char* Game_readCommand(Game* p);
void Game_playTurn(Game* p);
void Game_printMap(Game* p);
void Game_printTurnInfo(Game* p);
void Game_checkFinishGame(Game* p);
void Game_endTurn(Game* p);

#endif // __game_h__
