#include "7_Student.h"
#include "7_Course.h"
#include "7_StudentOffice.h"
#include "7_UniversityConstants.h"
#include <iostream>
using namespace std;

Course::Course() : name(""), code(""), ects(5) {}
Course::Course(const string& name, const string& code, int ects)
    : name(name), code(code), ects(ects) {}

ostream& operator<<(ostream& os, const Course& c) {
    os << c.code << " " << c.name << " (" << c.ects << " ECTS)";
    return os;
}

istream& operator>>(istream& is, Course& c) {
    is >> c.code >> c.name >> c.ects;
    return is;
}


int Student::total_students = 0;

Student::Student() : id(0), name(""), study_program(""), year(1),
enrolled_courses(nullptr), enrolled_count(0),
completed_courses(nullptr), completed_count(0) {
    total_students++;
}

Student::Student(int id, const string& name,
    const string& program, int year)
    : id(id), name(name), study_program(program),
    year(year), enrolled_courses(nullptr),
    enrolled_count(0), completed_courses(nullptr),
    completed_count(0) {
    total_students++;
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), study_program(other.study_program),
    year(other.year), enrolled_count(other.enrolled_count),
    completed_count(other.completed_count) {

    enrolled_courses = new Course[enrolled_count];
    for (size_t i = 0; i < enrolled_count; i++)
        enrolled_courses[i] = other.enrolled_courses[i];

    completed_courses = new Course[completed_count];
    for (size_t i = 0; i < completed_count; i++)
        completed_courses[i] = other.completed_courses[i];

    total_students++;
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        delete[] enrolled_courses;
        delete[] completed_courses;

        id = other.id;
        name = other.name;
        study_program = other.study_program;
        year = other.year;

        enrolled_count = other.enrolled_count;
        completed_count = other.completed_count;

        enrolled_courses = new Course[enrolled_count];
        completed_courses = new Course[completed_count];

        for (size_t i = 0; i < enrolled_count; i++)
            enrolled_courses[i] = other.enrolled_courses[i];
        for (size_t i = 0; i < completed_count; i++)
            completed_courses[i] = other.completed_courses[i];
    }
    return *this;
}

Student::Student(Student&& other) noexcept
    : id(other.id), name(other.name), study_program(other.study_program),
    year(other.year), enrolled_courses(other.enrolled_courses),
    enrolled_count(other.enrolled_count), completed_courses(other.completed_courses),
    completed_count(other.completed_count) {

    other.enrolled_courses = nullptr;
    other.completed_courses = nullptr;
    other.enrolled_count = 0;
    other.completed_count = 0;
    total_students++;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        delete[] enrolled_courses;
        delete[] completed_courses;

        id = other.id;
        name = other.name;
        study_program = other.study_program;
        year = other.year;

        enrolled_courses = other.enrolled_courses;
        completed_courses = other.completed_courses;
        enrolled_count = other.enrolled_count;
        completed_count = other.completed_count;

        other.enrolled_courses = nullptr;
        other.completed_courses = nullptr;
        other.enrolled_count = 0;
        other.completed_count = 0;
    }
    return *this;
}

Student::~Student() {
    delete[] enrolled_courses;
    delete[] completed_courses;
    total_students--;
}

int Student::get_total_students() { return total_students; }

void Student::enroll_course(const Course& c) {
    Course* temp = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; i++)
        temp[i] = enrolled_courses[i];
    temp[enrolled_count] = c;

    delete[] enrolled_courses;
    enrolled_courses = temp;
    enrolled_count++;
}

void Student::complete_course(size_t index) {
    if (index >= enrolled_count) return;

    Course* new_completed = new Course[completed_count + 1];
    for (size_t i = 0; i < completed_count; i++)
        new_completed[i] = completed_courses[i];

    new_completed[completed_count] = enrolled_courses[index];
    delete[] completed_courses;
    completed_courses = new_completed;
    completed_count++;

    Course* new_enrolled = new Course[enrolled_count - 1];
    size_t j = 0;
    for (size_t i = 0; i < enrolled_count; i++)
        if (i != index) new_enrolled[j++] = enrolled_courses[i];

    delete[] enrolled_courses;
    enrolled_courses = new_enrolled;
    enrolled_count--;
}

int Student::enrolled_ects() const {
    int sum = 0;
    for (size_t i = 0; i < enrolled_count; i++)
        sum += enrolled_courses[i].ects;
    return sum;
}

int Student::current_year_ects() const {
    int sum = 0;
    for (size_t i = 0; i < completed_count; i++)
        sum += completed_courses[i].ects;
    return sum;
}

Student& Student::operator+=(const Course& c) {
    enroll_course(c);
    return *this;
}

Student& Student::operator++() {
    if (current_year_ects() >= UniversityConstants::REQUIRED_ECTS_PER_YEAR)
        year++;
    return *this;
}

Student Student::operator++(int) {
    Student temp(*this);
    ++(*this);
    return temp;
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.id << " " << s.name << " "
        << s.study_program << " Year: " << s.year;
    return os;
}

istream& operator>>(istream& is, Student& s) {
    is >> s.id >> s.name >> s.study_program >> s.year;
    return is;
}



void StudentOffice::moveStudent(Student& s, string new_program) {
    s.study_program = move(new_program);
    cout << s.name << " moved to " << s.study_program << endl;
}

void StudentOffice::enroll_student(Student& s, const Course& c) {
    if (s.enrolled_ects() + c.ects <= UniversityConstants::MAX_ETCS_PER_YEAR) {
        s += c;
        cout << s.name << " successfully enrolled in " << c.name << endl;
    }
    else {
        cout << "Cannot enroll " << s.name << " in " << c.name
            << ". Max ECTS exceeded." << endl;
    }
}

void StudentOffice::process_exam_results(Student& s) {
    while (s.enrolled_count > 0)
        s.complete_course(0);
}

void StudentOffice::update_student_years(Student* students, size_t count) {
    for (size_t i = 0; i < count; i++)
        ++students[i];
}
