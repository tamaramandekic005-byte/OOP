#include<iostream>
#include<cstddef>
using namespace std;


void sortt(int niz[], size_t n, bool(*cmp)(int, int)) {
	for (size_t i = 0; i < n - 1; i++) {
		for (size_t j = i + 1; j < n; j++) {
			if (!cmp(niz[i], niz[j])) {
				int temp = niz[i];
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

int main() {
	int niz[] = { 3,7,9,2,1,65,213 };
	size_t n = sizeof(niz) / sizeof(niz[0]);
	
	cout << "Originalni niz: ";
		for (size_t i = 0; i < n; i++) {
			cout << niz[i] << " ";
		}
	cout << endl;
	
	sortt(niz, n, ascending);
	cout << "Uzlazno: ";
	for (size_t i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	
	
	sortt(niz, n, descending);
	cout << "Silazno: ";
	for (size_t i = 0; i < n; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
	
	return 0;
}

