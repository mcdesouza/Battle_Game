#include "mauler.h"

Mauler::Mauler(std::string name, bool enemy) : Character(name, enemy) {
    SetPath(std::string("../assets/Crystal_Mauler/idle"));
    SetFrames(8);
    SetCount(1);
    if (!isEnemy) {SetXpos(60);}
    else { SetXpos(360);}
    SetYpos(200);
    type = "Mauler";
}
bool Mauler::Attack1(Character& enemy) {
    bool success = Character::Attack1(enemy);
    if (success) {
        // SetXpos(200);
        SetPath(std::string("../assets/Crystal_Mauler/1_atk"));
        SetFrames(7);
        SetCount(1);
        SetAttacking(true);
        enemy.TakeDamage();
    }
    return success;
}
bool Mauler::Attack2(Character& enemy) {
    bool success = Character::Attack2(enemy);
    if (success) {
        // SetXpos(200);
        SetPath(std::string("../assets/Crystal_Mauler/2_atk"));
        SetFrames(7);
        SetCount(1);
        SetAttacking(true);
        enemy.TakeDamage();
    }
    return success;
}
bool Mauler::Attack3(Character& enemy) {
    bool success = Character::Attack3(enemy);
    if (success) {
        SetPath(std::string("../assets/Crystal_Mauler/3_atk"));
        SetFrames(17);
        SetCount(1);
        SetAttacking(true);
        enemy.TakeDamage();
    }
    return success;
}
bool Mauler::Attack4(Character& enemy) {
    bool success = Character::Attack4(enemy);
    if (success) {
        SetPath(std::string("../assets/Crystal_Mauler/sp_atk"));
        SetFrames(15);
        SetCount(1);
        SetAttacking(true);
        enemy.TakeDamage();
    }
    return success;
}
void Mauler::TakeDamage() {
    SetPath(std::string("../assets/Crystal_Mauler/take_hit"));
    SetFrames(6);
    SetCount(1);
}
void Mauler::Death() {
    SetPath(std::string("../assets/Crystal_Mauler/death"));
    SetFrames(15);
    SetCount(1);
}
void Mauler::Idle() {
    SetPath(std::string("../assets/Crystal_Mauler/idle"));
    SetFrames(8);
    SetCount(1);
}
