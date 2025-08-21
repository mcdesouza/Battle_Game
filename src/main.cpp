#include <iostream>
#include "game.h"

Game *game = nullptr;

int main(int argc, char *argv[]) {
    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->Init("Battle Game", 1280, 644, false);
    while (game->Running()) {
        frameStart = SDL_GetTicks();

        game->HandleEvents();
        game->Update();
        game->Render();

    }
    game->Clean();
    return 0;
}