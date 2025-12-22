#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void task1(const vector<int>& numbers) {
    cout << "1.\n";
    auto it = find_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 != 0; });
    if (it != numbers.end())
        cout << "Prvi neparni: " << *it << "\n";
    else
        cout << "Nema neparnih brojeva\n";

    int countOdd = count_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 != 0; });
    cout << "Broj neparnih: " << countOdd << "\n";

    int sumOdd = accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int x) { return sum + (x % 2 != 0 ? x : 0); });
    double avgOdd = countOdd ? static_cast<double>(sumOdd) / countOdd : 0.0;
    cout << "Prosjek neparnih: " << avgOdd << "\n";

    vector<int> numbersCopy = numbers;
    for_each(numbersCopy.begin(), numbersCopy.end(), [](int& x) { if (isPowerOfTwo(x)) x = 2; });

    vector<int> even, odd;
    for (int x : numbersCopy) (x % 2 == 0 ? even : odd).push_back(x);
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    cout << "Parni: ";
    for (int x : even) cout << x << " ";
    cout << "\nNeparni: ";
    for (int x : odd) cout << x << " ";
    cout << "\n\n";
}

namespace math_utils {
    struct Point { double x; double y; };
    double distance(const Point& a, const Point& b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    Point centroid(const vector<Point>& points) {
        if (points.empty()) return { 0.0, 0.0 };
        double sumX = accumulate(points.begin(), points.end(), 0.0, [](double s, const Point& p) { return s + p.x; });
        double sumY = accumulate(points.begin(), points.end(), 0.0, [](double s, const Point& p) { return s + p.y; });
        return { sumX / static_cast<double>(points.size()), sumY / static_cast<double>(points.size()) };
    }
}

istream& operator>>(istream& is, math_utils::Point& p) {
    return is >> p.x >> p.y;
}

void task2() {
    cout << "2.\n";
    ifstream fin("points.txt");
    if (!fin) { cout << "Ne mogu otvoriti points.txt\n"; return; }

    vector<math_utils::Point> points;
    math_utils::Point p;
    while (fin >> p) points.push_back(p);

    sort(points.begin(), points.end(), [](const math_utils::Point& a, const math_utils::Point& b) {
        return math_utils::distance({ 0,0 }, a) < math_utils::distance({ 0,0 }, b);
        });

    int firstQuad = count_if(points.begin(), points.end(), [](const math_utils::Point& p) { return p.x > 0 && p.y > 0; });
    cout << "Broj tocaka u prvom kvadrantu: " << firstQuad << "\n";

    math_utils::Point c = math_utils::centroid(points);
    cout << "Centroid: (" << c.x << ", " << c.y << ")\n";

    transform(points.begin(), points.end(), points.begin(), [](math_utils::Point p) { p.x += 5; p.y += 3; return p; });
    points.erase(remove_if(points.begin(), points.end(), [](const math_utils::Point& p) { return p.x < 0 && p.y < 0; }), points.end());

    cout << "Tocke nakon transformacije i filtriranja:\n";
    for (const auto& p : points) cout << "(" << p.x << ", " << p.y << ")\n";
    cout << "\n";
}

namespace student_records {
    struct Student { string ime; string prezime; int bodovi; };
    int bodovi_u_ocjenu(int bodovi) {
        if (bodovi < 40) return 1;
        else if (bodovi < 55) return 2;
        else if (bodovi < 70) return 3;
        else if (bodovi < 85) return 4;
        else return 5;
    }
}

void task3() {
    cout << "3.\n";
    ifstream fin("studenti.txt");
    if (!fin) { cout << "Ne mogu otvoriti studenti.txt\n"; return; }

    vector<student_records::Student> students;
    student_records::Student s;
    while (fin >> s.ime >> s.prezime >> s.bodovi) students.push_back(s);

    students.erase(remove_if(students.begin(), students.end(), [](const student_records::Student& s) { return s.bodovi < 40; }), students.end());

    transform(students.begin(), students.end(), students.begin(), [](student_records::Student s) {
        s.bodovi = student_records::bodovi_u_ocjenu(s.bodovi);
        return s;
        });

    double avgGrade = students.empty() ? 0.0 :
        static_cast<double>(accumulate(students.begin(), students.end(), 0, [](int sum, const student_records::Student& s) { return sum + s.bodovi; })) / students.size();

    sort(students.begin(), students.end(), [](const student_records::Student& a, const student_records::Student& b) { return a.prezime < b.prezime; });

    cout << "Studenti i ocjene:\n";
    for (const auto& st : students) cout << st.ime << " " << st.prezime << " - " << st.bodovi << "\n";
    cout << "Prosjek ocjena: " << avgGrade << "\n";
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 8, 16, 7 };
    task1(numbers);
    task2();
    task3();
    return 0;
}
