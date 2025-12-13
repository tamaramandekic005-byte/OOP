#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
using namespace std;

class GameCharacter {
protected:
    int health;
    string name;
public:
    GameCharacter(string n, int h);
    virtual ~GameCharacter();

    virtual void displayStatus() = 0;
    virtual void specialAbility() = 0;

    void takeDamage(int dmg);
    bool isAlive();
    string getName();
    int getHealth();
};

#endif

