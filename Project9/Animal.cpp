#include "Animal.h"
#include <stdexcept>

using namespace std;

Animal::Animal(const string& name, int age, double weight): name(name), age(age), weight(weight){
    if (name.empty())
        throw invalid_argument("Ime ne smije biti prazno");
    if (age < 0)
        throw invalid_argument("Godine ne smiju biti negativne");
    if (weight <= 0)
        throw invalid_argument("Tezina mora biti veca od 0");
}
