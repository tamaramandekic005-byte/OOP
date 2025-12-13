#ifndef WARRIOR_H
#define WARRIOR_H

#include "8_Player.h"
#include "8_Enemy.h"

class Warrior : public Player {
private:
    bool shieldActive;
public:
    Warrior(string n);
    void attackEnemy(Enemy* target) override;
    void specialAbility() override;
    void displayStatus() override;
    void takeDamageWithShield(int dmg);
};

#endif

