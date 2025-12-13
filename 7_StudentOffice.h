#ifndef STUDENT_OFFICE_H
#define STUDENT_OFFICE_H

#include "7_Student.h"
#include "7_UniversityConstants.h"
#include "7_Course.h"
#include <iostream>
using namespace std;

class StudentOffice {
public:
    static void moveStudent(Student& s, string new_program);
    static void enroll_student(Student& s, const Course& c);
    static void process_exam_results(Student& s);
    static void update_student_years(Student* students, size_t count);
};

#endif



