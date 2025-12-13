#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course {
public:
    string name;
    string code;
    int ects;

    Course();
    Course(const string& name,
        const string& code, int ects);

    friend ostream& operator<<(ostream& os, const Course& c);
    friend istream& operator>>(istream& is, Course& c);
};

#endif

