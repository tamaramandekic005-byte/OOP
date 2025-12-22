#ifndef AQUATIC_H
#define AQUATIC_H
#include "Animal.h"
#include <iostream>
using namespace std;

class Aquatic : virtual public Animal {
protected:
	double maxDiveDepth;
public:
	Aquatic(const string& name, int age, double weight, double maxDiveDepth);
};
#endif
