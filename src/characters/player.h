#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <fstream>

class Player : public Character{
public:
    Player(std::string name,std::string type) : Character(name), type(type) {};
    virtual ~Player();
    void Update();
    void Render();
    void SetTexture(const char* filePath) {characterTexture = Utils::LoadTexture(filePath);}

    std::string getType() {return type;}
    void setType(std::string type) {this->type = type;}

    virtual bool Attack1(Character&);
    virtual bool Attack2(Character&);
    virtual bool Attack3(Character&);
    virtual bool Attack4(Character&);
    void SaveGame();
    // we won't load game here, we will load a game in the game function better that way for pointers
protected:
    std::string type;

    SDL_Texture* characterTexture;
    SDL_Rect srcRect, destRect;
    int xpos, ypos, frames, count, delay = 70;
    std::string filepath;
    Uint32 lastFrameTime = 0;
    bool isEnemy = false, isAttacking = false;
};



#endif //PLAYER_H
