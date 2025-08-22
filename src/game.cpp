#include "game.h"
#include "arena/arena.h"
#include "utils/utils.h"
#include "characters/character.h"
#include "characters/player.h"
#include "characters/mauler.h"

Player* player = nullptr;
Arena* arena;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game(){}

Game::~Game(){}

void Game::Init(const char* title, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }
        isRunning = true;
    }
    arena = new Arena("../assets/arena/arena.png",0,0);
    // player = std::unique_ptr<Player>(new Mauler("matt",false));
}

void Game::Update() {
    arena->Update();
    // player->Update();
}
void Game::HandleEvents()
{
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT :
            isRunning = false;
            break;
        default:
            break;
    }
}
void Game::Render() {
    SDL_RenderClear(renderer);
    arena->Render();
    // player->Render();
    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}