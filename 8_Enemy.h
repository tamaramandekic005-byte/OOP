#ifndef ENEMY_H
#define ENEMY_H

#include "8_GameCharacter.h"
class Player; 

class Enemy : public GameCharacter {
protected:
    int difficulty;
public:
    Enemy(string n, int h, int d);
    virtual ~Enemy();

    virtual void attackPlayer(Player* target) = 0;
    int getDifficulty();
};

#endif

