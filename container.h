#ifndef CONTAINER_H
#define CONTAINER_H
#include<iostream>

class container {
private:
	int* niz;
	size_t n;
	size_t cap;

public:
	container(size_t kapacitet = 0);
	container(const container& other);
	container(container&& other);
	~container();

	void push_back(int broj);

	size_t velicina()const;
	size_t capacity()const;

	int at(size_t index)const;

	void clear();

};

#endif