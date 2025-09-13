#ifndef ARENA_H
#define ARENA_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "game.h"

class Arena {
public:
    Arena(const char *arenaPath, int x, int y);
    ~Arena(){ SDL_DestroyTexture(arenaTexture); }

    void Render();
    void Update();
private:
    SDL_Texture* arenaTexture;
    SDL_Rect srcRect, destRect;

    int xpos, ypos;
};



#endif //ARENA_H
