#if !defined(__MAIN__)
#define __MAIN__

#include "headers.h"
#include <unistd.h>
int main() {
    Game game = new_Game("config.txt");
    while (!isExiting(&game)) {
        Game_playTurn(&game);
    }
    return 0;
}

#endif // __MAIN__
