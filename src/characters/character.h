#ifndef CHARACTER_H
#define CHARACTER_H


#include <iostream>
#include <string>
#include <fstream>
#include "utils/utils.h"
#include "game.h"

class Character {
public:
    Character(std::string name = "Unknown") {
        health = 100;
        maxHealth = 100;
        xp = 0;
        level = 1;
        mp = 100;
    };
    virtual ~Character() {};

    int getHealth() {return health;}
    int getMaxHealth() {return maxHealth;}
    int getXP() {return xp;}
    int getLevel() {return level;}
    int getMP() {return mp;}
    std::string getName() {return name;}

    void setHealth(int health) {this->health = health;}
    void setMaxHealth(int maxHealth) {this->maxHealth = maxHealth;}
    void setXP(int xp) {this->xp = xp;}
    void setLevel(int level) {this->level = level;}
    void setMP(int mp) {this->mp = mp;}

    void Heal();
    void Rest();
    void CheckLevelUP();
    void LevelUp();

    virtual bool Attack1(Character&);
    virtual bool Attack2(Character&);
    virtual bool Attack3(Character&);
    virtual bool Attack4(Character&);
    virtual void Idle() = 0;
    virtual void TakeDamage() = 0;
    virtual void Death() = 0;

    bool IsAttacking() const {return isAttacking;}
    void SetAttacking(bool isAttacking) {this->isAttacking = isAttacking;}
    void SetXpos(int xpos){this->xpos = xpos;}
    void SetYpos(int ypos){this->ypos = ypos;}

    void Update();
    void Render();
    void SaveGame();

    void SetPath(std::string filePath) {filepath = filePath;}
    void SetFrames(int frames) {this->frames = frames;}
    void SetCount(int count) {this->count = count;}

protected:
    int health;
    int maxHealth;
    int xp;
    int level;
    int mp;
    std::string name;
    std::string type;

    SDL_Texture* characterTexture;
    SDL_Rect srcRect, destRect;
    int xpos, ypos, frames, count = 1, delay = 70;
    std::string filepath;
    Uint32 lastFrameTime = 0;
    bool isAttacking = false;
};



#endif //CHARACTER_H
