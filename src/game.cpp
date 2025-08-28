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
    // player = new Mauler("matt",false);
    enemy = new Mauler("enemy",true);
}

void Game::Update() {
    if (player != nullptr) { player->Update(); }
    // add a delay switch case depending on attack
    if (enemy != nullptr) { enemy->Update(); }
    // add a delay switch case depending on attack
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
    Intro();
    PlayerSelect();
    BattleEvents();
    GameEvents();
}
void Game::Render() {
    SDL_RenderClear(renderer);
    arena->Render();
    if (player != nullptr) { player->Render(); }
    if (enemy != nullptr) { enemy->Render(); }
    // if (intro) {
    //     // to do display intro box
    // }
    // if (player == nullptr && !intro){
    //     // to do display character selection box
    // }
    // if (options) {
    //     // to do display attacks and in battle options
    // }
    SDL_RenderPresent(renderer);
}

void Game::Clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::Intro() {
// to do: render intro to the screen and make load game function
    if (intro) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_1: // New Game
                    choosePlayer = true;
                    break;
                case SDLK_2: // load game
                    loadPlayer = true;
                    break;
                default:
                    break;
            }
        }
        if (event.type == SDL_KEYUP && (choosePlayer || loadPlayer)) {
            intro = false;
        }
    }
}

void Game::PlayerSelect() {
    // to do: render player selection text box
    // to do: add in all player paths for animations
    if (choosePlayer && !intro) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    player = new Mauler("matt",false);
                    choosePlayer = false;
                    break;
                case SDLK_2:
                    choosePlayer = false;
                    break;
                case SDLK_3:
                    choosePlayer = false;
                    break;
                case SDLK_4:
                    choosePlayer = false;
                    break;
                case SDLK_5:
                    choosePlayer = false;
                    break;
                case SDLK_6:
                    choosePlayer = false;
                    break;
                default:
                    break;
            }
            if (event.type = SDL_KEYUP && player != nullptr) {
                options = true;
            }
        }
    }
}

void Game::GameEvents() {
    // to do: render the options to the screen
    if (options) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_1: // enter battle;
                    inBattle = true;
                    //EnemySelect();
                    break;
                case SDLK_2: // save game
                    player->SaveGame();
                    options = false;
                    intro = true;
                    break;
                case SDLK_3: // exit to main menu saving
                    options = false;
                    intro = true;
                    break;
                default:
                    break;
            }
        }
        if (event.type == SDL_KEYUP && (inBattle || intro)) {
            options = false;
        }
    }
}

void Game::BattleEvents() {
    bool flag = false;
    if (inBattle && !options) {
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
                        flag = true;
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
            if (player->getHealth() <= 0) {
                inBattle = false;
            }
            playerTurn = true;
        }
    }
    if (!inBattle && flag) {
        options = true;
    }
}

void Game::EnemySelect() {
    if (enemy == nullptr) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 8);
        // randomize enemy selection
        int x = dist(gen);
        switch (x) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                break;
        }
    }
}