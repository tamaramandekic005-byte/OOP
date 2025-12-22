#include "Aquatic.h"
#include <iostream>

using namespace std;

Aquatic::Aquatic(const string& name, int age, double weight, double maxDiveDepth)
    : maxDiveDepth(maxDiveDepth){
    cout << "Stvorena vodena zivotinja koja roni do " << maxDiveDepth << "m" << endl;
}
