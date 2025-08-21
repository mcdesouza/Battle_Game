#ifndef UTILS_H
#define UTILS_H

#include "game.h"

class Utils {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};



#endif //UTILS_H
