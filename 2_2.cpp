#include<iostream>
using namespace std;
#include "vector.hpp";

vector vector_new(int initVelicina) {
	vector v;
	v.niz = new int[initVelicina];
	v.log = 0;
	v.fiz = initVelicina;

	return v;

}

void vector_delete(vector &v) {
	delete[] v.niz;
	v.niz = nullptr;
	v.log = 0;
	v.fiz = 0;

}

void vector_push_back(vector &v, int n) {
	if (v.log == v.fiz) {
		int novaVelicina = v.fiz * 2;
		int* noviNiz = new int[novaVelicina];
		for (int i =0 ; i < n; i++) {
			noviNiz[i] = v.niz[i];
		}
		delete[] v.niz;
		v.niz = nullptr;
		v.niz = noviNiz;
		v.fiz = novaVelicina;
	}
	v.niz[v.log] = n;
	v.log++;
}

void vector_pop_back(vector &v) {
	if (v.log > 0) {
		v.log --;
	}
	else {
		cout << "Vektor je prazan!";
	}
}

int vector_front(vector &v) {
	if (v.log > 0) {
		return v.niz[0];
	}
	else {
		cout << "Vektor je prazan!";
	}
}


int vector_back(vector &v) {
	if (v.log > 0) {
		return v.niz[v.log - 1];
	}
	else {
		cout << "Vektor je prazan!";
	}
}

int vector_size(vector &v) {
	return v.log;
}