#ifndef PLAYER_H
#define PLAYER_H

#include "8_GameCharacter.h"
class Enemy; 

class Player : public GameCharacter {
protected:
    int score;
public:
    Player(string n, int h);
    virtual ~Player();

    virtual void attackEnemy(Enemy* target) = 0;
    void addScore(int points);
    int getScore();
};

#endif

