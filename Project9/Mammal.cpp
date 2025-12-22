#include "Mammal.h"
#include <iostream>

using namespace std;

Mammal::Mammal(const string& name, int age, double weight, bool hasFur): hasFur(hasFur){
    if (hasFur)
        cout << "Stvoren sisavac s dlakom" << endl;
    else
        cout << "Stvoren sisavac s malo dlake" << endl;
}

