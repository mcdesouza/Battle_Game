#ifndef CHARACTER_H
#define CHARACTER_H


#include <iostream>
#include <string>
#include "utils/utils.h"
#include "game.h"

class Character {
public:
    Character(std::string name = "Unknown", int health = 100, int maxHealth = 100, int xp = 0, int level = 1, int mp = 100){};
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

    virtual void Idle() = 0;
    virtual void TakeDamage() = 0;
    virtual void Death() = 0;
    // animation update, if not attacking then idle

protected:
    int health;
    int maxHealth;
    int xp;
    int level;
    int mp;
    std::string name;
};



#endif //CHARACTER_H
