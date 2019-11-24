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

Game Game_loadGame(char* fileName) {
    Game res = new_Game(fileName);
    turn(&res) = MesinKata_readInt(config(&res));
    for (int i = 1; i <= N(&res); ++i) {
        Building* b = Building_getBuilding(&res, i);
        owner(b) = MesinKata_readInt(config(&res));
        level(b) = MesinKata_readInt(config(&res));
        armyCount(b) = MesinKata_readInt(config(&res));
    }
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

char* Game_readCommand(Game* p, char* msg) {
    printf(msg);
    return MesinKata_readString(console);
}

int Game_readCommandInt(Game* p, char* msg, int l, int r) {
    printf(msg);
    int res = MesinKata_readInt(console);
    if (l <= r) {
        while (res < l || res > r) {
            printf("Input is not valid!\n");
            printf(msg);
            res = MesinKata_readInt(console);
        }
    }
    return res;
}

void Game_playTurn(Game* p) {
    Game_printMap(p);
    char* command;
    char lower[128];
    do {
        Game_printTurnInfo(p);
        do {
            command = Game_readCommand(p, "ENTER COMMAND: ");
        } while (!Act_do(p, command));
        Game_checkFinishGame(p);
        if (isExiting(p)) {
            return;
        }
        toLowerCase(command, lower);
    } while (!compareString(lower, "end_turn"));
    Game_addArmies(p);
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
            Building* b = ListOfBuilding_getAt(&buildingList(p), index);
            switch (owner(b)) {
                case 0:
                    printf("%c", type(b));
                    break;
                case 1:
                    print_blue(type(b));
                    break;
                case 2:
                    print_red(type(b));
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
    Player* pl = Player_getCurrentPlayer(p);
    List bIndexList = buildingList(pl);
    Building_printList(p, bIndexList, "Building* List:");
    printf("Skill Available: %s\n", Queue_isEmpty(skillQueue(pl)) ? "-" : Skill_getAcronym(Queue_peek(skillQueue(pl))));
}

void Game_checkFinishGame(Game* p) {
    Player* pl1 = &playersi(p, 1), * pl2 = &playersi(p, 2);
    int winner = 0;
    if (List_isEmpty(&buildingList(pl1))) {
        winner = 2;
    } else if (List_isEmpty(&buildingList(pl2))) {
        winner = 1;
    }
    if (winner) {
        printf("The game is finished!\nThe winner is player %d!\n", winner);
        isExiting(p) = true;
    }
}

void Game_endTurn(Game* p) {
    Player* pl = Player_getCurrentPlayer(p), * en = Player_getEnemyPlayer(p);
    shieldTurn(en) = max(0, shieldTurn(en) - 1);
    attackUp(pl) = false;
    criticalHit(pl) = false;
    extraTurn(pl) = false;
    boolean allLevel4 = true;
    for (int i = 1; i < N(p); ++i) {
        Building* b = Building_getBuilding(p, i);
        hasAttacked(b) = false;
        if (level(b) != 4 && owner(b) == turn(p)) {
            allLevel4 = false;
        }
    }
    if (allLevel4) {
        Player_addSkill(pl, 6);
    }
    if (extraTurn(pl)) {
        printf("Extra turn has been used! You have one more turn!\n");
    } else {
        turn(p) = turn(p) == 1 ? 2 : 1;
    }
}

List Game_getAdjencyBuildings(Game* p, int buildingId, boolean enemy) {
    List res = NULL;
    List bIndexList = *ListOfList_getAt(&list(buildingGraph(p)), buildingId);
    while (bIndexList != NULL) {
        if (info(bIndexList) != buildingId) {
            Building* b = Building_getBuilding(p, info(bIndexList));
            if (owner(b) == turn(p) && !enemy || owner(b) != turn(p) && enemy) {
                List_addLast(&res, info(bIndexList));
            }
        }
        bIndexList = next(bIndexList);
    }
    return res;
}

void Game_addArmies(Game* p) {
    for (int i = 1; i < N(p); ++i) {
        Building* b = Building_getBuilding(p, i);
        if (armyCount(b) < Building_getMaxArmy(type(b), level(b)) && owner(b) == turn(p)) {
            armyCount(b) += Building_getArmyAddition(type(b), level(b));
        }
    }
}

List Game_getAttackableBuildings(Game* p) {
    List res = NULL;
    for (int i = 1; i <= N(p); ++i) {
        Building* b = Building_getBuilding(p, i);
        if (owner(b) == turn(p) && !hasAttacked(b)) {
            List_addLast(&res, i);
        }
    }
    return res;
}
