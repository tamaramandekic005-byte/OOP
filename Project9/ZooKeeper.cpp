#include "ZooKeeper.h"

using namespace std;

int ZooKeeper::totalAnimalsServed = 0;

void ZooKeeper::processAnimal(Animal* animal) {
    cout << "Species: " << animal->getSpecies()
        << ", Name: " << animal->getName()
        << ", Food: " << animal->getDailyFood() << "kg" << endl;

    totalAnimalsServed++;
}

int ZooKeeper::getTotalAnimalsServed() {
    return totalAnimalsServed;
}
