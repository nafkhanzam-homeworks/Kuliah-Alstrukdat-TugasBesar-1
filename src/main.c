#include "game.h"

int main() {
    Game game = new_Game();
    while (!game.isExiting) {
        Game_play(&game);
    }
    return 0;
}