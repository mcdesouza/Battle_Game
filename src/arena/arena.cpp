#include "arena.h"
#include "utils/utils.h"


Arena::Arena(const char *arenaPath, int x, int y) {
    arenaTexture = Utils::LoadTexture(arenaPath);
    xpos = x;
    ypos = y;
}

void Arena::Render() {
    Utils::Draw(arenaTexture, srcRect, destRect);
}

void Arena::Update() {
    srcRect.h = 644;
    srcRect.w = 1280;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
    destRect.x = xpos;
    destRect.y = ypos;
}
