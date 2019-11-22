#include "game.h"

Game new_Game(char* configFileName) {
    Game res;
    config(&res) = (MesinKata*) malloc(sizeof(MesinKata));
    *config(&res) = new_FileMesinKata(configFileName);
    Game_initConfig(&res);
    int n = N(&res), r = ROW(&res), c = COL(&res);
    actStack(&res) = (StackOfAct*) malloc(sizeof(StackOfAct));
    *actStack(&res) = new_StackOfAct();
    buildingGraph(&res) = (Graph*) malloc(sizeof(Graph));
    *buildingGraph(&res) = new_Graph(n);
    buildingList(&res) = NULL;
    command(&res) = (MesinKata*) malloc(sizeof(MesinKata));
    *command(&res) = new_MesinKata();
    isExiting(&res) = false;
    map(&res) = (Matrix*) malloc(sizeof(Matrix));
    *map(&res) = new_Matrix(r, c);
    players(&res) = (ArrayOfPlayer*) malloc(sizeof(ArrayOfPlayer));
    *players(&res) = new_ArrayOfPlayer(2);
    playersi(&res, 1) = new_Player();
    playersi(&res, 2) = new_Player();
    turn(&res) = 1;
    Game_initConfig2(&res);
    return res;
}

void Game_init(Game* p) {
    Game_initConfig(p);
}

void Game_initConfig(Game* p) {
    MesinKata* reader = config(p);
    ROW(p) = MesinKata_readInt(reader); COL(p) = MesinKata_readInt(reader); N(p) = MesinKata_readInt(reader);
}

void Game_initConfig2(Game* p) {
    MesinKata* reader = config(p);
    int n = N(p);
    for (int i = 1; i <= n; ++i) {
        char buildingType = MesinKata_readString(reader)[0];
        int x = MesinKata_readInt(reader), y = MesinKata_readInt(reader);
        tabij(map(p), x, y) = i;
        ListOfBuilding_addLast(&buildingList(p), new_Building(buildingType, x, y, i <= 2 ? i : 0));
        if (i <= 2) {
            List_addFirst(&buildingList(&playersi(p, i)), i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int isConnected = MesinKata_readInt(reader);
            if (isConnected) {
                Graph_add1(buildingGraph(p), i, j);
            }
        }
    }
}

char* Game_readCommand(Game* p) {
    MesinKata_readString(command(p));
}

void Game_playTurn(Game* p) {
    Game_printMap(p);
    Game_printTurnInfo(p);
    char* command;
    do {
        printf("ENTER COMMAND: ");
        command = Game_readCommand(p);
    } while (!Act_do(p, command));
    Game_checkFinishGame(p);
    Game_endTurn(p);
}

void Game_printMap(Game* p) {
    int row = row(map(p)), col = col(map(p));
    for (int i = 1; i <= col+2; ++i) {
        printf("#");
        if (i < col+2) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    for (int i = 1; i <= row; ++i) {
        printf("#");
        for (int j = 1; j <= col; ++j) {
            printf(" ");
            int index = tabij(map(p), i, j);
            if (index == 0) {
                printf(" ");
                continue;
            }
            Building b = ListOfBuilding_getAt(&buildingList(p), index);
            switch (owner(&b)) {
                case 0:
                    printf("%c", type(&b));
                    break;
                case 1:
                    print_blue(type(&b));
                    break;
                case 2:
                    print_red(type(&b));
                    break;
            }
        }
        printf(" #\n");
    }
    for (int i = 1; i <= col+2; ++i) {
        printf("#");
        if (i < col+2) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

void Game_printTurnInfo(Game* p) {
    printf("Player %d\n", turn(p));
    Player pl = Player_getCurrentPlayer(p);
    List bIndexList = buildingList(&pl);
    int i = 0;
    while (bIndexList != NULL) {
        Building b = ListOfBuilding_getAt(&buildingList(p), info(bIndexList));
        printf("%d. %s (%d,%d) %d lv. %d\n", ++i, Building_getName(type(&b)), x(position(&b)), y(position(&b)), armyCount(&b), level(&b));
        bIndexList = next(bIndexList);
    }
    printf("Skill Available: %s\n", Queue_isEmpty(skillQueue(&pl)) ? "-" : Skill_getAcronym(Queue_peek(skillQueue(&pl))));
}

void Game_checkFinishGame(Game* p) {
    Player pl1 = playersi(p, 1), pl2 = playersi(p, 2);
    int winner = 0;
    if (List_isEmpty(&buildingList(&pl1))) {
        winner = 2;
    } else if (List_isEmpty(&buildingList(&pl2))) {
        winner = 1;
    }
    if (winner) {
        printf("The game is finished!\nThe winner is player %d!\n", winner);
        isExiting(p) = true;
    }
}

void Game_endTurn(Game* p) {
    Player pl = Player_getCurrentPlayer(p);
    if (extraTurn(&pl)) {
        extraTurn(&pl) = false;
    } else {
        turn(p) = turn(p) == 1 ? 2 : 1;
    }
}
