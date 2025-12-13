#include <iostream>
#include <vector>
#include "8_GameCharacter.h"
#include "8_Player.h"
#include "8_Enemy.h"
#include "8_Warrior.h"
#include "8_Mage.h"
#include "8_Gnome.h"
#include "8_Boss.h"

using namespace std;


GameCharacter::GameCharacter(string n, int h) : name(n), health(h) {}
GameCharacter::~GameCharacter() {}
void GameCharacter::takeDamage(int dmg) { health -= dmg; if (health < 0) health = 0; }
bool GameCharacter::isAlive() { return health > 0; }
string GameCharacter::getName() { return name; }
int GameCharacter::getHealth() { return health; }


Player::Player(string n, int h) : GameCharacter(n, h), score(0) {}
Player::~Player() {}
void Player::addScore(int points) { score += points; }
int Player::getScore() { return score; }


Enemy::Enemy(string n, int h, int d) : GameCharacter(n, h), difficulty(d) {}
Enemy::~Enemy() {}
int Enemy::getDifficulty() { return difficulty; }


Warrior::Warrior(string n) : Player(n, 120), shieldActive(false) {}
void Warrior::attackEnemy(Enemy* target) {
    if (!target->isAlive()) return;
    cout << name << " attacks " << target->getName() << " with sword!" << endl;
    target->takeDamage(20);
    if (!target->isAlive()) {
        addScore(10);
        cout << name << " defeated " << target->getName() << " and gains 10 points!" << endl;
    }
}
void Warrior::specialAbility() {
    shieldActive = true;
    cout << name << " activates shield! Next attack damage reduced by 50%." << endl;
}
void Warrior::displayStatus() {
    cout << "Warrior: " << name << ", Health: " << health << ", Score: " << score << endl;
}
void Warrior::takeDamageWithShield(int dmg) {
    if (shieldActive) {
        dmg /= 2;
        shieldActive = false;
    }
    takeDamage(dmg);
}


Mage::Mage(string n) : Player(n, 80), mana(100) {}
void Mage::attackEnemy(Enemy* target) {
    if (!target->isAlive()) return;
    if (mana >= 20) {
        cout << name << " casts fireball on " << target->getName() << "!" << endl;
        target->takeDamage(40);
        mana -= 20;
    }
    else {
        cout << name << " attacks " << target->getName() << " with staff!" << endl;
        target->takeDamage(20);
    }
    if (!target->isAlive()) {
        addScore(10);
        cout << name << " defeated " << target->getName() << " and gains 10 points!" << endl;
    }
}
void Mage::specialAbility() {
    if (health > 50) {
        cout << name << " teleports to a safe location!" << endl;
    }
}
void Mage::displayStatus() {
    cout << "Mage: " << name << ", Health: " << health << ", Mana: " << mana << ", Score: " << score << endl;
}


Gnome::Gnome(string n) : Enemy(n, 90, 3) {}
void Gnome::attackPlayer(Player* target) {
    if (!target->isAlive()) return;
    cout << name << " shoots arrows at " << target->getName() << "!" << endl;
    target->takeDamage(5 * difficulty);
}
void Gnome::specialAbility() {
    if (health > 20) {
        cout << name << " plays trumpet, calling other gnomes for help!" << endl;
    }
}
void Gnome::displayStatus() {
    cout << "Gnome: " << name << ", Health: " << health << ", Difficulty: " << difficulty << endl;
}


Boss::Boss(string n) : Enemy(n, 300, 8) {}
void Boss::attackPlayer(Player* target) {
    if (!target->isAlive()) return;
    cout << name << " crushes the ground under " << target->getName() << "!" << endl;
    target->takeDamage(10 * difficulty);
}
void Boss::specialAbility() {
    health += 50;
    if (health > 300) health = 300;
    cout << name << " regenerates 50 health! Current health: " << health << endl;
}
void Boss::displayStatus() {
    cout << "Boss: " << name << ", Health: " << health << ", Difficulty: " << difficulty << endl;
}
