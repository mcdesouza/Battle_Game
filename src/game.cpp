#include "game.h"
#include "arena/arena.h"
#include "utils/utils.h"
#include "characters/character.h"
#include "characters/mauler.h"

Character* player;
Character* enemy;
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
    player = new Mauler("matt");
    enemy = new Mauler("enemy");
}

void Game::Update() {
    player->Update();
    enemy->Update();
    arena->Update();
}
void Game::HandleEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT :
            isRunning = false;
            break;
        default:
            break;
    }
    BattleEvents();
    GameEvents();
}
void Game::Render() {
    SDL_RenderClear(renderer);
    arena->Render();
    if (player) {
        player->Render();
    }
    if (enemy) {
        enemy->Render();
    }
    if (intro) {
        // to do display intro box
    }
    if (characterSelect){
        // to do display character selection box
    }
    if (options) {
        // to do display attacks and in battle options
    }
    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::GameEvents() {
// to do provide in game options save etc.
}

void Game::Intro() {
// to do provide intro options
}

void Game::BattleEvents() {
    if (inBattle) {
        if (playerTurn){ // Player Battle Options
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_1:
                        player->Attack1(*enemy);
                        break;
                    case SDLK_2:
                        player->Attack2(*enemy);
                        break;
                    case SDLK_3:
                        player->Attack3(*enemy);
                        break;
                    case SDLK_4:
                        player->Attack4(*enemy);
                        break;
                    case SDLK_5:
                        player->Heal();
                        break;
                    case SDLK_6:
                        player->Rest();
                        break;
                    case SDLK_7:
                        inBattle = false;
                        break;
                    default:
                        break;
                }
                playerTurn = false;
            }
            if (enemy->getHealth() <= 0) {
                inBattle = false;
            }
        }
        else { // Generate Random Enemy Battle Options
            playerTurn = true;
        }
    }
}

void Game::EnemySelect() {
// to do generate a random enemy
// easy switch case
}
void Game::PlayerSelect() {
// to do options for player select
// easy switch case
}