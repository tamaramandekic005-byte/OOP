#include<iostream>
#include "vector.hpp"
using namespace std;

vector vector_new(int initvelicina) { 
	vector v;
	v.niz = new int[initvelicina];
	v.log = 0;
	v.fiz = initvelicina;  
	return v;
}

void vector_delete(vector& v) {  
	delete[] v.niz;
	v.niz = nullptr;
	v.log = 0;  
	v.fiz = 0;  
}

void vector_push_back(vector& v, int n) {
	if (v.log == v.fiz) {
		int novavelicina = v.fiz * 2;
		int* novi_niz = new int[novavelicina];

		for (int i = 0; i < v.log; i++) {
			novi_niz[i] = v.niz[i];  
		}

		delete[] v.niz;  
		v.niz = nullptr;
		v.niz = novi_niz;  
		v.fiz = novavelicina;  
	}

	v.niz[v.log] = n;  
	v.log++;
}

void vector_pop_back(vector& v) {
	if (v.log > 0) {  
		v.log--;  
	}
	else {
		cout << "vektor je prazan!" << endl;
	}
}

int vector_front(vector& v) {
	if (v.log > 0) {
		return v.niz[0];
	}
	else {
		cout << "vektor je prazan!" << endl;
	}
}

int vector_back(vector& v) {
	if (v.log > 0) {
		return v.niz[v.log - 1];
	}
	else {
		cout << "vektor je prazan." << endl;
	}
}

int vector_size(vector& v) {
	return v.log;
}