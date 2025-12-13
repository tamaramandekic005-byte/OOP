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

int main() {
    vector<GameCharacter*> characters;

    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Gnome* gnomeo = new Gnome("Gnomeo");
    Gnome* sneaky = new Gnome("Sneaky");
    Boss* dragon = new Boss("Dragon");

    characters.push_back(conan);
    characters.push_back(merlin);
    characters.push_back(gnomeo);
    characters.push_back(sneaky);
    characters.push_back(dragon);

    conan->attackEnemy(gnomeo);
    conan->displayStatus(); gnomeo->displayStatus(); cout << endl;

    merlin->attackEnemy(sneaky);
    merlin->displayStatus(); sneaky->displayStatus(); cout << endl;

    gnomeo->attackPlayer(conan);
    conan->displayStatus(); gnomeo->displayStatus(); cout << endl;

    merlin->attackEnemy(gnomeo);
    merlin->displayStatus(); gnomeo->displayStatus(); cout << endl;

    dragon->attackPlayer(merlin);
    dragon->displayStatus(); merlin->displayStatus(); cout << endl;

    merlin->attackEnemy(gnomeo);
    merlin->displayStatus(); gnomeo->displayStatus(); cout << endl;

    conan->attackEnemy(dragon);
    conan->displayStatus(); dragon->displayStatus(); cout << endl;

    merlin->attackEnemy(dragon);
    merlin->displayStatus(); dragon->displayStatus(); cout << endl;

    cout << "\nSpecial Abilities: \n";
    for (auto c : characters) c->specialAbility();

    cout << "\nStatus prezivjelih: \n";
    GameCharacter* maxHealthChar = nullptr;
    for (auto c : characters) {
        if (c->isAlive()) {
            c->displayStatus();
            if (!maxHealthChar || c->getHealth() > maxHealthChar->getHealth())
                maxHealthChar = c;
        }
    }

    if (maxHealthChar) {
        cout << "Character with highest health: " << maxHealthChar->getName() << endl;
    }

    for (auto c : characters) delete c;

    return 0;
}
