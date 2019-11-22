#include "game.h"

Game new_Game(int n, char* configFileName, int r, int c) {
    Game res;
    actStack(&res) = new_StackOfAct();
    buildingGraph(&res) = new_Graph(n);
    buildingList(&res) = new_ArrayOfBuilding(n);
    command(&res) = new_MesinKata();
    config(&res) = new_MesinKata(configFileName);
    isExiting(&res) = false;
    map(&res) = new_Matrix(r, c);
    players(&res) = new_ArrayOfPlayer(2);
    turn(&res) = 1;
    Game_init(&res);
    return res;
}

void Game_init(Game* p) {
    Game_initConfig(p);
}

void Game_initConfig(Game* p) {
    MesinKata* reader = &config(p);
    int row = MesinKata_readInt(reader), col = MesinKata_readInt(reader), n = MesinKata_readInt(reader);
    for (int i = 1; i <= n; ++i) {
        char buildingType = MesinKata_readString(reader)[0];
        int x = MesinKata_readInt(reader), y = MesinKata_readInt(reader);
        tabi(&buildingList(p), i) = new_Building(buildingType, x, y);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int isConnected = MesinKata_readInt(reader);
            if (isConnected) {
                Graph_add1(&buildingGraph(p), i, j);
            }
        }
    }
}

char* Game_readCommand(Game* p) {
    MesinKata_readString(&command(p));
}

void Game_playTurn(Game* p) {
    Game_printMap(p);
    Game_printTurnInfo(p);
    char* command;
    do {
        printf("ENTER COMMAND: ");
        command = Game_readCommand(p);
    } while (!Act_do(p, command));
}

void Game_printMap(Game* p) {
    int row = row(&map(p)), col = col(&map(p));
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
            Building b = tabi(&buildingList(p), tabij(&map(p), i, j));
            switch (owner(&b)) {
                case 0:
                    printf(type(&b));
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
        Building b = tabi(&buildingList(p), info(bIndexList));
        printf("%d. %s (%d,%d) %d lv. %d\n", ++i, Building_getName(&b), x(&position(&b)), y(&position(&b)), armyCount(&b), level(&b));
        bIndexList = next(bIndexList);
    }
    printf("Skill Available: %s\n", Skill_getAcronym(Queue_peek(&skillQueue(&pl))));
}
