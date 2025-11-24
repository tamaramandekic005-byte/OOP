#include "container.h"
using namespace std;

container::container(size_t initial_capacity) : niz(nullptr), n(0), cap(initial_capacity) {
	if (cap > 0) {
		niz = new int[cap];
	}
	cout << "Kreiran je container." << endl;
}

container::container(const container& other) : n(other.n), cap(other.cap) {
	if (cap > 0) {
		niz = new int[cap];
	}
	else {
		niz = nullptr;
	}

	for (int i = 0; i < n; i++) {
		niz[i] = other.niz[i];
	}
	cout << "Copy constructor je pozvan." << endl;
}

container::container(container&& other) : niz(other.niz),n(other.n), cap(other.cap) {
	other.niz = nullptr;
	other.n = 0;
	other.cap = 0;

	cout << "Move constructor je pozvan.";
}

container:: ~container() {
	delete[] niz;
	cout << "Container je izbrisan." << endl;
}
