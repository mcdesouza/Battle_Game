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

    static SDL_Renderer *renderer;
    static SDL_Event event;
private:
    bool isRunning = false;
    int cnt = 0;
    SDL_Window *window;
};



#endif //GAME_H
