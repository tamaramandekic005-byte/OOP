#ifndef GNOME_H
#define GNOME_H

#include "8_Enemy.h"
#include "8_Player.h"

class Gnome : public Enemy {
public:
    Gnome(string n);
    void attackPlayer(Player* target) override;
    void specialAbility() override;
    void displayStatus() override;
};

#endif

