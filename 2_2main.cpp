#include <iostream>
#include "vector.hpp"
using namespace std;

int main() {
    vector v = vector_new(2); 

    vector_push_back(v, 10);
    vector_push_back(v, 20);
    vector_push_back(v, 30); 
    vector_push_back(v, 40);

    cout << "Vektor: ";
    for (int i = 0; i < v.log; i++) {
        cout << v.niz[i] << " " ;
    }
    cout << endl;

    cout << "Prvi element: " << vector_front(v) << endl;
    cout << "Zadnji element: " << vector_back(v) << endl;
    cout << "Logicka velicina: " << vector_size(v) << endl;

    vector_pop_back(v);

    cout << "Vektor nakon uklanjanja: ";
    for (int i = 0; i < v.log; i++) {
        cout << v.niz[i] << " ";
    }


    vector_delete(v); 
    return 0;
}
