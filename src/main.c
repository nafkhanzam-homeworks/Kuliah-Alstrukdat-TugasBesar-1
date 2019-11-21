#if !defined(__MAIN__)
#define __MAIN__

#include "game.h"

int main() {
    Game game = new_Game();
    while (!isExiting(&game)) {
        Game_playTurn(&game);
    }
    return 0;
}

#endif // __MAIN__
