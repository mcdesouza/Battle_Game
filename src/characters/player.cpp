#include "player.h"

bool Player::Attack1(Character& enemy) {
    if (getMP() >= 15) {
        enemy.setHealth(enemy.getHealth() - (20 + (2 * level)));
        mp -= 15;
        return true;
    }
    return false;
}
bool Player::Attack2(Character& enemy) {
    if (getMP() >= 25) {
        enemy.setHealth(enemy.getHealth() - (30 + (2 * level)));
        mp -= 25;
        return true;
    }
    return false;
}
bool Player::Attack3(Character& enemy) {
    if (getMP() >= 40) {
        enemy.setHealth(enemy.getHealth() - (40 + (2 * level)));
        mp -= 40;
        return true;
    }
    return false;
}
bool Player::Attack4(Character& enemy) {
    if (getMP() >= 60) {
        enemy.setHealth(enemy.getHealth() - (60 + (2 * level)));
        mp -= 60;
        return true;
    }
    return false;
}
void Player::SaveGame() {
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