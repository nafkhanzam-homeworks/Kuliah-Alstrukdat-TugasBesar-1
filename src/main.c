#if !defined(__MAIN__)
#define __MAIN__

#include "headers.h"

int main() {
    console = (MesinKata*) malloc(sizeof(MesinKata));
    *console = new_MesinKata();
    Game game;
    // editin biar bagus
    printf("Game Avatar World War (by Group 7)!\n");
    printf("MENU:\n");
    printf("[1] New Game.\n");
    printf("[2] Load Game.\n");
    printf("Choose Menu: ");
    int ans = MesinKata_readInt(console);
    while (ans != 1 && ans != 2) {
        printf("The chosen menu is not valid!\n");
        printf("Choose Menu: ");
        ans = MesinKata_readInt(console);
    }
    if (ans == 1) {
        game = new_Game("config.txt");
    } else {
        printf("File Name to Load: ");
        game = Game_loadGame(MesinKata_readString(console));
    }
    while (!isExiting(&game)) {
        Game_playTurn(&game);
    }
    return 0;
}

#endif // __MAIN__
