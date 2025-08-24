#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>


class Game {
public:
    Game();
    ~Game();

    void Init(const char* title, int width, int height, bool fullscreen);

    void HandleEvents();
    void Update();
    bool Running() {return isRunning;}
    void Render();
    void Clean();

    void Intro();
    void GameEvents();
    void BattleEvents();
    void EnemySelect();
    void PlayerSelect();

    static SDL_Renderer *renderer;
    static SDL_Event event;
private:
    bool isRunning = false;
    int cnt = 0;
    int battle = 0;
    SDL_Window *window;
    bool inBattle = true;
    bool intro = true;
    bool characterSelect = false;
    bool options = false;
    bool playerTurn = true;
};



#endif //GAME_H
