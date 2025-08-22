#include "mauler.h"

Mauler::Mauler(std::string name) : Player(name, "Mauler") {
    // SetTexture("../assets/Crystal_Mauler/idle");
    SetPath(std::string("../assets/Crystal_Mauler/idle"));
    SetFrames(8);
    SetCount(1);
    SetXpos(20);
    SetYpos(200);
};
bool Mauler::Attack1(Character& enemy) {
    bool success = Player::Attack1(enemy);
    if (success) {
        // SetTexture("../assets/Crystal_Mauler/1_atk");
        SetPath(std::string("assets/Crystal_Mauler/1_atk"));
        SetFrames(7);
        SetCount(1);
        SetAttacking(true);
    }
    return success;
}
bool Mauler::Attack2(Character& enemy) {
    bool success = Player::Attack1(enemy);
    if (success) {
        //render
        //enemy.TakeDamage(); render this animation
    }
    return success;
}
bool Mauler::Attack3(Character& enemy) {
    bool success = Player::Attack1(enemy);
    if (success) {
        //render
        //enemy.TakeDamage(); render this animation
    }
    return success;
}
bool Mauler::Attack4(Character& enemy) {
    bool success = Player::Attack1(enemy);
    if (success) {
        //render
        //enemy.TakeDamage(); render this animation
        //player.update mp
        //enemy.update health bar
    }
    return success;
}
void Mauler::TakeDamage() {
    // render take damage animation
}
void Mauler::Death() {
    // render death animation
}
void Mauler::Idle() {
    // SetTexture("../assets/Crystal_Mauler/idle");
    SetPath(std::string("../assets/Crystal_Mauler/idle"));
    SetFrames(8);
    SetCount(1);
}
