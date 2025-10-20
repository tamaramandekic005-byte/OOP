/*#include<iostream>
using namespace std;

int* fibonacci(int n) {
	if (n <= 0) return nullptr;

	int* niz = new int[n];
	niz[0] = 1;
	if (n > 1) {
		niz[1] = 1;
	}

	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main() {
	int n;
	cout << "Unesi velicinu niza:";
	cin >> n;

	int *f = fibonacci(n);

	cout << "Novi niz je: ";
	for (int i = 0; i < n; i++) {
		cout << f[i] << " ";
	}
	cout << endl;
	delete []f;
	f = nullptr;

	return 0;
}
*/