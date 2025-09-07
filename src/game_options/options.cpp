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
    optionsTexture = Utils::LoadTexture("../assets/options/character_select.png");
    Utils::Draw(optionsTexture, srcRect, destRect);
    srcRect.w = 1323;
    srcRect.h = 225;
    xpos = -30;
}

void Options::RenderGameEvents() {
    optionsTexture = Utils::LoadTexture("../assets/options/game_events.png");
    Utils::Draw(optionsTexture, srcRect, destRect);
    srcRect.w = 459;
    srcRect.h = 270;
    xpos = 400;
}

void Options::RenderBattleEvents() {
    optionsTexture = Utils::LoadTexture("../assets/options/battle_events.png");
    Utils::Draw(optionsTexture, srcRect, destRect);
    srcRect.w = 1026;
    srcRect.h = 225;
    xpos = 135;
}

void Options::Update() {
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.h = srcRect.h;
    destRect.w = srcRect.w;
    destRect.x = xpos;
    destRect.y = ypos;
}