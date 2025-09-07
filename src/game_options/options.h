#ifndef OPTIONS_H
#define OPTIONS_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "game.h"

class Options {
public:
    Options(){xpos = 0 ; ypos = 100;}
    ~Options();

    void RenderIntro();
    void RenderCharacterEvents();
    void RenderGameEvents();
    void RenderBattleEvents();

    void Update();
private:
    SDL_Texture* optionsTexture;

    SDL_Rect srcRect, destRect;

    int xpos, ypos;
};



#endif //OPTIONS_H
