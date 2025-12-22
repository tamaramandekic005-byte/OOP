#include "SeaTurtle.h"
#include <stdexcept>

using namespace std;

SeaTurtle::SeaTurtle(const string& name, int age, double weight)
    : Animal(name, age, weight),
    Aquatic(name, age, weight, 200.0) {};

string SeaTurtle::getSpecies() const {
    return "Sea Turtle";
}

double SeaTurtle::getDailyFood() const {
    double food = weight * 0.03;
    if (food == 0)
        throw logic_error("Hrana ne moze biti 0");
    return food;
}

string SeaTurtle::getName() const {
    return name;
}
