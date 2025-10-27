#include<iostream>
#include<cstddef>
using namespace std;

void funk(int* niz, size_t s) {
	auto isEven = [](int n) { return n % 2 == 0; };
	auto udvostruci = [](int n) {return n * 2; };
	auto prepolovi = [](int n) {return n / 2; };

	for (size_t i = 0; i < s; i++) {
		if (isEven(niz[i])) {
			niz[i] = prepolovi(niz[i]);
		}
		else {
			niz[i] = udvostruci(niz[i]);
		}
	}
}

void funk1(int* niz, size_t s, int& suma, int& produkt) {
	suma = 0;
	produkt = 1;

	auto ssuma = [&](int n) { suma += n; };
	auto pprod = [&](int n) {produkt *= n; };

	for (size_t i = 0; i < s; i++) {
		ssuma(niz[i]);
		pprod(niz[i]);
	}
}

int funk2(int * niz, size_t s, int prag, int& suma) {
	suma = 0;
	auto dodaj_veci = [prag, &suma](int n) {
		if (n > prag) suma += n;
	};

	for (size_t i = 0; i < s; i++)
		dodaj_veci(niz[i]);
	return suma;
}

int main() {
	int niz[] = { 5,9,23,76,1,3,0 };
	size_t s = sizeof(niz) / sizeof(niz[0]);

	funk(niz, s);
	cout << "Novi niz je: ";
	for (int i = 0; i < s; i++)
		cout << niz[i] << " ";
	cout << endl;

	int suma, produkt;
	funk1(niz, s, suma, produkt);
	cout << "Suma je: " << suma << endl;
	cout << "Produkt je: " << produkt << endl;

	int prag = 4;
	int sum = funk2(niz, s, prag, suma);
	cout << "Suma elemenata koji su veci od praga je:" << suma << endl;
	return 0;
}



