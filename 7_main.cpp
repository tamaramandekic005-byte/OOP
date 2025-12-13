#include "7_Student.h"
#include "7_Course.h"
#include "7_UniversityConstants.h"
#include "7_StudentOffice.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    UniversityConstants::print_university_rules();
    cout << endl;

    vector<Student> students;
    students.push_back(Student(1, "Ana", "IT", 1));
    students.push_back(Student(2, "Korana", "IT", 2));
    students.push_back(Student(3, "Ivan", "Math", 1));

    cout << "Lista studenata: " << endl;
    for (auto& s : students)
        cout << s << " | Enrolled ECTS: " << s.enrolled_ects()
        << " | Completed ECTS: " << s.current_year_ects() << endl;
    cout << "Total students: " << Student::get_total_students() << endl << endl;

    Course c1("OOP", "OOP101", 5);
    Course c2("Math", "M101", 5);
    Course c3("SPA", "SPA102", 5);
    Course c4("Algorithms", "ALG101", 5);

    StudentOffice::enroll_student(students[0], c1);
    StudentOffice::enroll_student(students[0], c2);

    StudentOffice::enroll_student(students[1], c1);
    StudentOffice::enroll_student(students[1], c3);

    StudentOffice::enroll_student(students[2], c4);

    cout << endl << "Nakon upisa kolegija: " << endl;
    for (auto& s : students)
        cout << s << " | Enrolled ECTS: " << s.enrolled_ects()
        << " | Completed ECTS: " << s.current_year_ects() << endl;
    cout << endl;

    for (auto& s : students)
        StudentOffice::process_exam_results(s);

    cout << " Nakon polaganja ispita: " << endl;
    for (auto& s : students)
        cout << s << " | Enrolled ECTS: " << s.enrolled_ects()
        << " | Completed ECTS: " << s.current_year_ects() << endl;
    cout << endl;

    StudentOffice::update_student_years(students.data(), students.size());

    cout << "Nakon update_student_years: " << endl;
    for (auto& s : students)
        cout << s << " | Year: " << s.current_year_ects() / 5 + 1 << endl;
    cout << endl;

    StudentOffice::moveStudent(students[2], "ComputerScience");

    cout << "Nakon moveStudent: " << endl;
    for (auto& s : students)
        cout << s << " | Enrolled ECTS: " << s.enrolled_ects()
        << " | Completed ECTS: " << s.current_year_ects() << endl;
    cout << endl;

    cout << "Total students in system: " << Student::get_total_students() << endl;

    return 0;
}
