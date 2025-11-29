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

	cout << "Copy konstruktor je pozvan." << endl;

}


container::container(container&& other) : niz(other.niz), n(other.n), cap(other.cap) {
	other.niz = nullptr;
	other.n = 0;
	other.cap = 0;

	cout << "Move konstruktor je pozvan." << endl;
}


container:: ~container() {
	delete[] niz;
	cout << "Container je izbrisan." << endl;
}


void container::push_back(int broj) {
	if (n == cap) {
		size_t new_cap;
		if (cap == 0) {
			new_cap = 1;
		}
		else {
			new_cap = cap * 2;
		}

		int* novi = new int[new_cap];

		for (int i = 0; i < n; i++) {
			novi[i] = niz[i];
		}
		delete[] niz;
		niz = novi;
		cap = new_cap;

		cout << "Realokacija memorije." << cap << endl;
	}
	niz[n++] = broj;
}



size_t container::velicina() const {
	return n;
}

size_t container:: capacity() const {
	return cap;
}

int container::at(size_t index) const {
	return niz[index];
}


void container::clear() {
	n = 0;
}

container napraviContainer() {
	container c;
	c.push_back(28);
	c.push_back(88);
	return c;
}

void primiPoVrijednosti(container c) {
	cout << "Funkcija je dobila container po vrijednosti." << endl;
}




int main() {
	container a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(8);


	container b = a;
	container c = move(a);
	primiPoVrijednosti(b);

	container d = napraviContainer();

	for (int i = 1; i <=5 ; i++) {
		d.push_back(i);
	}
	
	std::cout << "Elementi containera d:\n";
	for (size_t i = 0; i < d.velicina(); i++)
		std::cout << "Index " << i << " = " << d.at(i) << endl;

	return 0;
}