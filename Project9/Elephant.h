#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Mammal.h"

class Elephant : public Mammal {
public:
    Elephant(const string& name, int age, double weight);

    string getSpecies() const override;
    double getDailyFood() const override;
    string getName() const override;
};
#endif
