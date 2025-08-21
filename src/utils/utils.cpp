#include "utils.h"


SDL_Texture* Utils::LoadTexture(const char* fileName) {
    SDL_Surface* tempSurface = IMG_Load(fileName);
    if (!tempSurface) {
        printf("Failed to load the image. Error: %s", IMG_GetError());
        __debugbreak();
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    if (!tex) {
        printf("Failed to create texture. Error %s", SDL_GetError());
        __debugbreak();
    }
    return tex;
}

void Utils::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

