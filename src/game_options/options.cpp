#include "options.h"
#include "utils/utils.h"

void Options::RenderIntro() {
    optionsTexture = Utils::LoadTexture("../assets/options/intro.png");
    Utils::Draw(optionsTexture, srcRect, destRect);
    srcRect.w = 405;
    srcRect.h = 225;
    xpos = 400;
}

void Options::RenderCharacterEvents() {

}

void Options::RenderGameEvents() {

}

void Options::RenderBattleEvents() {

}

void Options::Update() {
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
    destRect.x = xpos;
    destRect.y = ypos;
}