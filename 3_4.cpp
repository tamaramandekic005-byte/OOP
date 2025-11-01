#include<iostream>
#include<cstddef>
#include<string>
using namespace std;

struct Student {
	string ime;
	long jmbag;
	int godina;
	int ects;
	double prosjek;
};

void filter_students(Student niz[], size_t n, void (*akcija)(Student&), bool (*filter)(Student&)) {
	for (size_t i = 0; i < n; ++i) {
		if (filter(niz[i])) {
			akcija(niz[i]);
		}
	}
}

void print(Student& s) {
	cout << s.ime << " JMBAG: " << s.jmbag
		<< " Godina: " << s.godina
		<< " ECTS: " << s.ects
		<< " Prosjek: " << s.prosjek << endl;
}

void godina(Student& s) {
	s.godina++;
}


int main() {
    Student studenti[] = {
        {"Ivan", 8203749940, 1, 7, 3.8},
        {"Ana", 2345675221, 2, 50, 4.2},
        {"Marko", 3456789435, 1, 0, 3.0},
        {"Lucija", 4567892224, 3, 60, 4.5}
    };
    size_t n = sizeof(studenti) / sizeof(studenti[0]);


    auto prva_godina = [](Student& s) { return s.godina == 1 && s.ects >= 6; };
    cout << "Studenti koji su polozili barem jedan ispit:" << endl;
    filter_students(studenti, n, print, prva_godina);

 
    auto prosjek = [](Student& s) { return s.prosjek > 3.5; };
    cout << "\nProsjek veci od 3.5:" << endl;
    filter_students(studenti, n, print, prosjek);

    auto veca_godina = [](Student& s) { return s.ects >= 45; };
    filter_students(studenti, n, godina, veca_godina);

    cout << "\nStudenti koji su upisali vecu godinu:" << endl;
    filter_students(studenti, n, print, veca_godina);

    return 0;
}


