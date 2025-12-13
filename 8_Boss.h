#ifndef BOSS_H
#define BOSS_H

#include "8_Enemy.h"
#include "8_Player.h"

class Boss : public Enemy {
public:
    Boss(string n);
    void attackPlayer(Player* target) override;
    void specialAbility() override;
    void displayStatus() override;
};

#endif

