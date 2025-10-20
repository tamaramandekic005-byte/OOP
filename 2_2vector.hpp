#ifndef VECTOR_HPP
#define VECTOR_HPP

typedef struct {
	int* niz;
	int log;
	int fiz;
}vector;

vector vector_new(int initVelicina);

void vector_delete(vector& v);

void vector_push_back(vector& v, int n);

void vector_pop_back(vector& v);

int vector_front(vector& v);

int vector_back(vector& v);

int vector_size(vector& v);


#endif