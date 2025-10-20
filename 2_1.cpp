#include <iostream>
using namespace std;

int* fibonacci(int n) {
    if (n <= 0) return nullptr; 

    int* niz = new int[n]; 
    niz[0] = 1;
    if (n > 1)
        niz[1] = 1;

    for (int i = 2; i < n; i++) {
        niz[i] = niz[i - 1] + niz[i - 2];
    }

    return niz;
}

int main() {
    int n;

    cout << "Unesite velicinu niza: ";
    cin >> n;

    int* fib = fibonacci(n);

    if (fib != nullptr) {
        cout << "Fibonacci niz: ";
        for (int i = 0; i < n; i++) {
            cout << fib[i] << " ";
        }
        cout << endl;

        delete[] fib;
        fib = nullptr;
    }
    else {
        cout << "Pogresna velicina niza!" << endl;
    }

    return 0;
}
