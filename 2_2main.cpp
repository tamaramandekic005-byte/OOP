#include<iostream>
using namespace std;
#include "vector.hpp";

int main() {
	vector v = vector_new(2);

	vector push_back(v, 10);
	vector push_back(v, 2);
	vector push_back(v, 14);
	vector push_back(v, 15);

	cout << "Vektor:";
	for (int i = 0; i < v.log; i++) {
		cout << v.niz[i] << " " << endl;
	}
	
	cout << "Prvi element: " << vector_front(v) << endl;
	cout << "Zadnji element: " << vector_front(v) << endl;
	cout << "Logicka velicina: " << vector_size(v) << endl;

	vector pop_back(v);
	cout << "Vektor nakon uklanjanja:";
	for (int i = 0; i < v.log; i++) {
		cout << v.niz[i] << " " << endl;
	}
	vector_delete(v);
	return 0;



}