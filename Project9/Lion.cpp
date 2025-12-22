#include "Lion.h"
#include <stdexcept>

using namespace std;

Lion::Lion(const string& name, int age, double weight)
    : Animal(name, age, weight),
    Mammal(name, age, weight, true) {};

string Lion::getSpecies() const {
    return "Lion";
}

double Lion::getDailyFood() const {
    double food = weight * 0.06;
    if (food == 0)
        throw logic_error("Hrana ne moze biti 0");
    return food;
}

string Lion::getName() const {
    return name;
}
