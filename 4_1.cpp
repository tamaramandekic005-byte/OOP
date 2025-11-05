#include<iostream>
#include<vector>
#include <algorithm> 
#include <cmath> 
using namespace std;


void input_vector(vector<int>& v) { 
	int broj;
	cout << "Unosi brojeve (0 za kraj): " << endl;
	while (true) {
		cin >> broj;
		if (broj == 0) break;
		v.push_back(broj);
	}
}

void print_vector(const vector<int>& v) {
	cout << "Vektor: ";
	for (int broj : v) {
		cout << broj << " ";
	}
	cout << endl;
}


int main() {
	vector<int> brojevi;
	input_vector(brojevi);
	print_vector(brojevi);

	vector<int>jedinstveni;
	for (int x : brojevi) {
		if (find(jedinstveni.begin(), jedinstveni.end(), x) == jedinstveni.end()) { 
			jedinstveni.push_back(x);
		}
	}
	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);

	sort(jedinstveni.begin(), jedinstveni.end(), [](int a, int b) { return abs(a) < abs(b); });
	cout << "Sortirani elementi po abs: ";
	for (int i = 0; i < jedinstveni.size(); i++) {
		cout << jedinstveni[i]<<" ";
	}
	cout << endl;


	return 0;
}
