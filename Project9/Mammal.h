#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animal.h"
#include<string>

class Mammal :virtual public Animal {
protected:
	bool hasFur;
public:
	Mammal(const string& name, int age, double weight, bool hasFur);
};
#endif

