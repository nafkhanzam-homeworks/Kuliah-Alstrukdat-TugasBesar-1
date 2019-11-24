#include "game.h"

Game new_Game(char* configFileName) {
    /* KAMUS LOKAL */    
    Game res;

    /* ALGORITMA */

    // Menyiapkan Konfigurasi Game
    config(&res) = (MesinKata*) malloc(sizeof(MesinKata));
    *config(&res) = new_FileMesinKata(configFileName);

    // Set Konfigurasi Game dari config.txt (Baris Peta, Kolom Peta, Banyak Bangunan)
    Game_initConfig(&res);
    int n = N(&res), r = ROW(&res), c = COL(&res);

    // Menyiapkan Stack untuk menyimpan Aksi
    actStack(&res) = (StackOfAct*) malloc(sizeof(StackOfAct));
    *actStack(&res) = new_StackOfAct();
    
    // Menyiapkan graf keterhubungan antar bangunan
    buildingGraph(&res) = (Graph*) malloc(sizeof(Graph));
    *buildingGraph(&res) = new_Graph(n);
    
    // Menyiapkan list daftar bangunan yang ada
    buildingList(&res) = NULL;
    
    // Kondisi Exit
    isExiting(&res) = false;
    
    // Menyiapkan Matriks Map untuk menyimpan posisi bangunan 
    map(&res) = (Matrix*) malloc(sizeof(Matrix));
    *map(&res) = new_Matrix(r, c);
    
    // Menyiapkan Player Game
    players(&res) = (ArrayOfPlayer*) malloc(sizeof(ArrayOfPlayer));
    *players(&res) = new_ArrayOfPlayer(2);
    playersi(&res, 1) = new_Player();
    playersi(&res, 2) = new_Player();
    
    // Set Turn awal bagi player pertama
    turn(&res) = 1;
    
    // Menyiapkan Konfigurasi Lanjut, Daftar Bangunan dan Keterhubungan Antar Bangunan
    Game_initConfig2(&res);
    
    return res;
}

Game Game_loadGame(char* fileName) {
    /* KAMUS LOKAL */
    Game res;

    /* ALGORITMA */
    res = new_Game(fileName); // Inisiasi mulai permainan
    turn(&res) = MesinKata_readInt(config(&res)); // Set status pemain yang mendapat putaran sesuai config
    for (int i = 1; i <= N(&res); ++i) { // Assign status permainan pada tipe data game
        Building* b = Building_getBuilding(&res, i);
        owner(b) = MesinKata_readInt(config(&res));
        level(b) = MesinKata_readInt(config(&res));
        armyCount(b) = MesinKata_readInt(config(&res));
    }
    return res;
}

void Game_init(Game* p) {
    /* ALGORITMA */
    Game_initConfig(p);
}

void Game_initConfig(Game* p) {
    /* KAMUS LOKAL */
    MesinKata* reader;

    /* ALGORITMA */
    reader = config(p);
    ROW(p) = MesinKata_readInt(reader); COL(p) = MesinKata_readInt(reader); N(p) = MesinKata_readInt(reader);
}

void Game_initConfig2(Game* p) {
    /* KAMUS LOKAL */
    MesinKata* reader;
    char buildingType;
    int x,y,isConnected;

    /* ALGORITMA */
    reader = config(p); // Inisiasi konfigurasi
    int n = N(p);

    // Membaca Daftar Bangunan (Jenis, Posisi[x,y])
    for (int i = 1; i <= n; ++i) {
        buildingType = MesinKata_readString(reader)[0];
        x = MesinKata_readInt(reader);
        y = MesinKata_readInt(reader);
        tabij(map(p), x, y) = i;
        // Set daftar bangunan, bangunan selain milik kedua pemain di set kepemilikan 0
        ListOfBuilding_addLast(&buildingList(p), new_Building(buildingType, x, y, i <= 2 ? i : 0));
        // Set Bangunan  Awal yang dimiliki tiap Player
        if (i <= 2) {
            List_addFirst(&buildingList(&playersi(p, i)), i);
        }
    }

    // Membaca Keterhubungan antar bangunan, membangun graf keterhubungan
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            isConnected = MesinKata_readInt(reader);
            if (isConnected) { // Jika keterhubungan True (1)
                Graph_add1(buildingGraph(p), i, j);
            }
        }
    }
}

char* Game_readCommand(Game* p, char* msg) {
    /* ALGORITMA */
    printf("%s",msg);
    return MesinKata_readString(console);
}

int Game_readCommandInt(Game* p, char* msg, int l, int r) {
    /* KAMUS LOKAL */
    int res;

    /* ALGORITMA */
    printf("%s",msg); // print pesan
    res = MesinKata_readInt(console);
    if (l <= r) {
        while (res < l || res > r) { // validasi input
            printf("Input is not valid!\n");
            printf("%s",msg);
            res = MesinKata_readInt(console);
        }
    }
    return res;
}

void Game_playTurn(Game* p) {
    /* KAMUS LOKAL */
    char* command;
    char lower[128];

    /* ALGORITMA */
    Game_printMap(p);
    do {
        Game_printTurnInfo(p);
        do { // Membaca COMMAND
            command = Game_readCommand(p, "ENTER COMMAND: ");
        } while (!Act_do(p, command));
        Game_checkFinishGame(p); // Cek status berhenti
        if (isExiting(p)) {
            return;
        }
        toLowerCase(command, lower);
    } while (!compareString(lower, "end_turn")); // Cek ganti turn
    Game_addArmies(p);
}

void Game_printMap(Game* p) {
    /* KAMUS LOKAL */
    int row,col,index;

    /* ALGORITMA */
    row = row(map(p));
    col = col(map(p));
    for (int i = 1; i <= col+2; ++i) {
        printf("#"); // Batas atas
        if (i < col+2) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    for (int i = 1; i <= row; ++i) {
        printf("#"); // Batas samping
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
                    printf("%c", type(b)); // print bangunan tanpa kepemilikan
                    break;
                case 1:
                    print_blue(type(b)); // print bangunan milik player 1
                    break;
                case 2:
                    print_red(type(b)); // print bangunan milik player 2
                    break;
            }
        }
        printf(" #\n");
    }
    for (int i = 1; i <= col+2; ++i) {
        printf("#"); // Batas bawah
        if (i < col+2) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

void Game_printTurnInfo(Game* p) {
    /* KAMUS LOKAL */
    Player* pl;
    List bIndexList;

    /* ALGORITMA */
    printf("Player %d\n", turn(p));
    pl = Player_getCurrentPlayer(p);
    bIndexList = buildingList(pl);
    Building_printList(p, bIndexList, "Building List:"); // Print bangunan yang dimiliki player
    printf("Skill Available: %s\n", Queue_isEmpty(skillQueue(pl)) ? "-" : Skill_getAcronym(Queue_peek(skillQueue(pl))));
}

void Game_checkFinishGame(Game* p) {
    /* KAMUS LOKAL */
    Player* pl1, * pl2;
    int winner;

    /* ALGORITMA */
    pl1 = &playersi(p, 1);
    pl2 = &playersi(p, 2);
    winner = 0;
    if (List_isEmpty(&buildingList(pl1))) { // Saat bangunan player 1 habis, player 2 menang
        winner = 2;
    } else if (List_isEmpty(&buildingList(pl2))) { // Saat bangunan player 2 habis, player 1 menang
        winner = 1;
    }
    if (winner) {
        printf("The game is finished!\nThe winner is player %d!\n", winner);
        isExiting(p) = true;
    }
}

void Game_endTurn(Game* p) {
    /* KAMUS LOKAL */
    Player* pl, * en;
    boolean allLevel4;

    /* ALGORITMA */
    // set player
    pl = Player_getCurrentPlayer(p);
    en = Player_getEnemyPlayer(p);
    // reset status skill
    shieldTurn(en) = max(0, shieldTurn(en) - 1);
    attackUp(pl) = false;
    criticalHit(pl) = false;
    extraTurn(pl) = false;
    
    // Cek level pada tiap bangunan
    allLevel4 = true;
    for (int i = 1; i < N(p); ++i) {
        Building* b = Building_getBuilding(p, i);
        hasAttacked(b) = false;
        if (level(b) != 4 && owner(b) == turn(p)) {
            allLevel4 = false;
        }
    }
    if (allLevel4) { // Jika semua bangunan telah level 4, tambah skill
        Player_addSkill(pl, 6);
    }
    if (extraTurn(pl)) {
        printf("Extra turn has been used! You have one more turn!\n");
    } else {
        turn(p) = turn(p) == 1 ? 2 : 1;
    }
}

List Game_getAdjencyBuildings(Game* p, int buildingId, boolean enemy) {
    /* KAMUS LOKAL */
    List res;
    List bIndexList;
    Building* b;

    /* ALGORITMA */
    res = NULL;
    // mencari list bangunan yang terkait dengan bangunan berID buildingID
    bIndexList = *ListOfList_getAt(&list(buildingGraph(p)), buildingId);
    while (bIndexList != NULL) {
        if (info(bIndexList) != buildingId) {
            b = Building_getBuilding(p, info(bIndexList));
            if (owner(b) == turn(p) && !enemy || owner(b) != turn(p) && enemy) {
                List_addLast(&res, info(bIndexList));
            }
        }
        bIndexList = next(bIndexList);
    }
    return res;
}

void Game_addArmies(Game* p) {
    /* KAMUS LOKAL */
    Building* b;

    /* ALGORITMA */
    for (int i = 1; i < N(p); ++i) {
        b = Building_getBuilding(p, i);
        // Menambahkan jumlah pasukan sesuai dengan level yang dimiliki bangunan
        if (armyCount(b) < Building_getMaxArmy(type(b), level(b)) && owner(b) == turn(p)) {
            armyCount(b) += Building_getArmyAddition(type(b), level(b));
        }
    }
}

List Game_getAttackableBuildings(Game* p) {
    /* KAMUS LOKAL */
    List res;
    Building* b;

    /* ALGORITMA */
    res = NULL;
    // Iterasi pencarian bangunan dengan status dapat menyerang (bekum menyerang dan dimiliki pemain yang sedang mendapat putaran)
    for (int i = 1; i <= N(p); ++i) {
        b = Building_getBuilding(p, i);
        if (owner(b) == turn(p) && !hasAttacked(b)) {
            List_addLast(&res, i);
        }
    }
    return res;
}
