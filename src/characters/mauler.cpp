#include "mauler.h"

bool Mauler::Attack1(Character& enemy) {
    bool success = Player::Attack1(enemy);
    if (success) {
        //render
        //enemy.TakeDamage(); render this animation
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