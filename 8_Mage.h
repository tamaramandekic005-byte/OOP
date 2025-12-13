#ifndef MAGE_H
#define MAGE_H

#include "8_Player.h"
#include "8_Enemy.h"

class Mage : public Player {
private:
    int mana;
public:
    Mage(string n);
    void attackEnemy(Enemy* target) override;
    void specialAbility() override;
    void displayStatus() override;
};

#endif

