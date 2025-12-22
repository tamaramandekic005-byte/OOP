#include <iostream>
#include <memory>
#include "ZooSection.h"
#include "ZooKeeper.h"
#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"

using namespace std;

int main() {
    try {
        ZooSection<Animal> zoo;
        ZooKeeper keeper;

        zoo.addAnimal(make_unique<Lion>("Simba", 5, 190));
        zoo.addAnimal(make_unique<Elephant>("Dumbo", 10, 5000));
        zoo.addAnimal(make_unique<Dolphin>("Flipper", 8, 300));
        zoo.addAnimal(make_unique<SeaTurtle>("Leonardo", 50, 150));

        for (size_t i = 0; i < zoo.size(); i++) {
            keeper.processAnimal(zoo.getAnimal(i));
        }

        cout << "\nUkupna dnevna hrana: " << zoo.totalFood() << "kg" << endl;
        cout << "Ukupno nahranjenih zivotinja: "
            << ZooKeeper::getTotalAnimalsServed() << endl;
    }
    catch (const exception& e) {
        cerr << "Greska: " << e.what() << endl;
    }

    return 0;
}
