#ifndef UNIVERSITY_CONSTANTS_H
#define UNIVERSITY_CONSTANTS_H

#include <iostream>

using namespace std;

struct UniversityConstants {
    static const int MAX_ETCS_PER_YEAR = 60;
    static const int REQUIRED_ECTS_PER_YEAR = 45;

    static void print_university_rules() {
        cout << "MAX ECTS per year: "
            << MAX_ETCS_PER_YEAR << endl;
        cout << "REQUIRED ECTS per year: "
            << REQUIRED_ECTS_PER_YEAR << endl;
    }
};

#endif

