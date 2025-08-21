#include "character.h"

void Character::Heal() {
    health += 20;
    if (health > maxHealth) {
        health = maxHealth;
    }
}
void Character::Rest() {
    mp += 20;
    if (mp > 100) {
        mp = 100;
    }
}
void Character::CheckLevelUP() {
    while (xp >= 100) {
        LevelUp();
        xp -= 100;
    }
}
void Character::LevelUp() {
    level++;
    maxHealth += 10;
    health = maxHealth;
}