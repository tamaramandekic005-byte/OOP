#include<iostream>
#include<cstddef>
using namespace std;
template<typename T>


void sortt(T* niz, size_t n, bool(*cmp)(T, T)) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = i + 1; j < n; j++) {
			if (!cmp(niz[i], niz[j])) {
				T temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}
}

bool ascending(int a, int b) {
	return a < b;
}

bool descending(int a, int b) {
	return a > b;
}

bool ascending(double a, double b) {
	return a < b;
}

bool descending(double a, double b) {
	return a > b;
}



int main() {
	int niz[] = { 5, 2, 9, 1, 7 };
	double niz1[] = { 4.6,2.9,11.6, 0.3 };
	size_t n = sizeof(niz) / sizeof(niz[0]);
	size_t n1 = sizeof(niz1) / sizeof(niz1[0]);
	
	sortt(niz, n, ascending);
	cout << "Int niz uzlazno: ";
	for (size_t i = 0; i < n; i++) 
		cout << niz[i] << " ";
	cout << endl;

	sortt(niz, n, descending);
	cout << "Int niz silazno: ";
	for (size_t i = 0; i < n; i++)
		cout << niz[i] << " ";
	cout << endl;
	
	sortt(niz1, n1, ascending);
	cout << "Double niz uzlazno: ";
	for (size_t i = 0; i < n1; i++) 
		cout << niz1[i] << " ";
	cout << endl;
	
	sortt(niz1, n1, descending);
	cout << "Double niz silazno: ";
	for (size_t i = 0; i < n1; i++) cout << niz1[i] << " ";
	cout << endl;
	
	return 0;
}


