#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

double** matrica(int m, int n) {  
	double** mat = new double* [m]; 
	for (int i = 0; i < m; i++) {
		mat[i] = new double[n];
	}
	return mat;
}

void unos(double** mat, int m, int n) {
	cout << "unesi elemente matrice(" << m << "x" << n << ");\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
}

void generiraj(double** mat, int m, int n, double a, double b) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double r = (double)rand() / RAND_MAX;
			mat[i][j] = a + r * (b - a);
		}
	}
}
void print(double** mat, int m, int n) {
    cout << fixed << setprecision(4);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << mat[i][j] << " ";
        }
        cout << endl;
    }
}


double** zbroj(double** A, double** B, int m, int n) {
    double** C = matrica(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}


double** razlika(double** A, double** B, int m, int n) {
    double** C = matrica(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

//
double** umnozak(double** A, double** B, int m, int n, int p) {
    double** C =matrica(m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}


double** transp(double** A, int m, int n) {
    double** T = matrica(n, m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    return T;
}


void oslobodi(double** mat, int m) {
    for (int i = 0; i < m; i++)
        delete[] mat[i];
    delete[] mat;
}


int main() {
    srand(time(0));

    int m = 2, n = 3, p = 2;

    double** A = matrica(m, n);
    double** B = matrica(m, n);

    generiraj(A, m, n, 0, 10);
    generiraj(B, m, n, 0, 10);

    cout << "Matrica A:\n";
    print(A, m, n);

    cout << "Matrica B:\n";
    print(B, m, n);


    double** Z = zbroj(A, B, m, n);
    cout << "Zbroj:\n";
    print(Z, m, n);


    double** R = razlika(A, B, m, n);
    cout << "Razlika:\n";
    print(R, m, n);


    double** Bt = transp(B, m, n);         
    double** U = umnozak(A, Bt, m, n, m);
    cout << "Umnozak :\n";
    print(U, m, m);
    oslobodi(Bt, n);                        


    double** T = transp(A, m, n);
    cout << "Transponirana matrica A:\n";
    print(T, n, m);

    oslobodi(A, m);
    oslobodi(B, m);
    oslobodi(Z, m);
    oslobodi(R, m);
    oslobodi(U, m);
    oslobodi(T, n);

    return 0;
}


