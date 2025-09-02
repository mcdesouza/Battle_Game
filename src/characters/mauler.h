#ifndef MAULER_H
#define MAULER_H

#include "character.h"

class Mauler : public Character {
public:
    Mauler(std::string name, bool enemy);
    ~Mauler() override {};

    bool Attack1(Character&) override;
    bool Attack2(Character&) override;
    bool Attack3(Character&) override;
    bool Attack4(Character&) override;
    void Idle() override;
    void TakeDamage() override;
    void Death() override;
};



#endif //MAULER_H
