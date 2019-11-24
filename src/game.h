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
    int turn, N, ROW, COL;
    boolean isExiting;
} Game;

Game new_Game();
Game Game_loadGame(char* fileName);
void Game_init(Game* p);
void Game_initConfig(Game* p);
void Game_initConfig2(Game* p);
char* Game_readCommand(Game* p, char* msg);
int Game_readCommandInt(Game* p, char* msg, int l, int r);
void Game_playTurn(Game* p);
void Game_printMap(Game* p);
void Game_printTurnInfo(Game* p);
void Game_checkFinishGame(Game* p);
void Game_endTurn(Game* p);
List Game_getAdjencyBuildings(Game* p, int buildingId, boolean enemy);
void Game_addArmies(Game* p);
List Game_getAttackableBuildings(Game* p);
List Game_getMovableBuildings(Game* p);

// save format
// <config.txt>
// [each building]
// <currentTurn>
// <owner> <level> <armyCount>
// <skillCount: player 1> [skillNumbers...]
// <skillCount: player 2> [skillNumbers...]

#endif // __game_h__
