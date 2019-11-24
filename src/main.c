#if !defined(__MAIN__)
#define __MAIN__

#include "headers.h"

int main() {

	/* KAMUS */
	int ans;
    Game game;

   	/* ALGORITMA */

	/* Menyiapkan konsol input mesin kata */
    console = (MesinKata*) malloc(sizeof(MesinKata));
    *console = new_MesinKata();

    /* Menampilkan menu */
    printf("Game Avatar World War (by Group 7)!\n");
    printf("MENU:\n");
    printf("[1] New Game.\n");
    printf("[2] Load Game.\n");
    printf("Choose Menu: ");
    ans = MesinKata_readInt(console);

    /* Validasi pemilihan menu */
    while (ans != 1 && ans != 2) {
        printf("The chosen menu is not valid!\n");
        printf("Choose Menu: ");
        ans = MesinKata_readInt(console);
    }


    if (ans == 1) { // Memulai Game dari awal
        game = new_Game("config.txt");
    } else { // Memuat konfigurasi tersimpan
        printf("File Name to Load: ");
        game = Game_loadGame(MesinKata_readString(console));
    }

    /* Cek kondisi pengakhiaran Game */
    while (!isExiting(&game)) {
        Game_playTurn(&game);
    }
    return 0;
}

#endif // __MAIN__
