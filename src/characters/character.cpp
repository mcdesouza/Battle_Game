#include "character.h"


void Character::Update() {
    srcRect.w = 288;
    srcRect.h = 128;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.h = srcRect.h * 3;
    destRect.w = srcRect.w * 3;

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime > lastFrameTime + delay) {
        if (count < frames) {
            std::string filename = filepath + "/" + std::to_string(count) + ".png";
            const char* file = filename.c_str();
            characterTexture = Utils::LoadTexture(file);
            count++;
        }
        else {
            count = 1;
            if (health > 0) {
                this->Idle();
                this->Update();
            }
            else {
                this->Death();
            }
            if (isAttacking) {
                isAttacking = false;
            }
        }
        lastFrameTime = currentTime;
    }
}

void Character::Render() {
    if (!isEnemy) {
        Utils::Draw(characterTexture, srcRect,destRect);
    }
    else {
        Utils::InvertedTexture(characterTexture, srcRect, destRect, SDL_FLIP_HORIZONTAL);
    }
}

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

bool Character::Attack1(Character& enemy) {
    if (getMP() >= 15) {
        enemy.setHealth(enemy.getHealth() - (20 + (2 * level)));
        mp -= 15;
        return true;
    }
    return false;
}
bool Character::Attack2(Character& enemy) {
    if (getMP() >= 25) {
        enemy.setHealth(enemy.getHealth() - (30 + (2 * level)));
        mp -= 25;
        return true;
    }
    return false;
}
bool Character::Attack3(Character& enemy) {
    if (getMP() >= 40) {
        enemy.setHealth(enemy.getHealth() - (40 + (2 * level)));
        mp -= 40;
        return true;
    }
    return false;
}
bool Character::Attack4(Character& enemy) {
    if (getMP() >= 60) {
        enemy.setHealth(enemy.getHealth() - (60 + (2 * level)));
        mp -= 60;
        return true;
    }
    return false;
}

void Character::SaveGame() {
    std::string output = name + ".txt";
    std::ofstream fout(output);
    if (!fout.is_open()) {
        std::cerr << "Error saving to file: " << output << std::endl;
        return;
    }
    fout << type << std::endl;
    fout << health << std::endl;
    fout << maxHealth << std::endl;
    fout << level << std::endl;
    fout << xp << std::endl;
    fout << name << std::endl;
    fout.close();
    std::cout << "Game saved to: " << output << std::endl;
}