#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "7_Course.h"

using namespace std;

class Student {
private:
    int id;
    string name;
    string study_program;
    int year;

    static int total_students;

    Course* enrolled_courses;
    size_t enrolled_count;

    Course* completed_courses;
    size_t completed_count;

public:
    Student();
    Student(int id, const string& name,
        const string& program, int year);

    Student(const Student& other);
    Student& operator=(const Student& other);

    Student(Student&& other) noexcept;
    Student& operator=(Student&& other) noexcept;

    ~Student();

    static int get_total_students();

    void enroll_course(const Course& c);
    int current_year_ects() const;

    Student& operator+=(const Course& c);
    Student& operator++();       
    Student operator++(int);     

    friend ostream& operator<<(ostream& os, const Student& s);
    friend istream& operator>>(istream& is, Student& s);

    void complete_course(size_t index);
    int enrolled_ects() const;

    friend class StudentOffice;

};

#endif

