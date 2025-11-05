#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

void reverse_strings(vector<string>& words) {
	for (string& word : words) {
		reverse(word.begin(), word.end());
	}
}

int main() {
	vector<string> words = { "hello", "world", "c++" };

	cout << "Prije okretanja: ";
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << " ";
		if (i != words.size() - 1) {
			cout << ", ";
		}
	}

	reverse_strings(words);
	cout<<endl;

	cout << "Nakon okretanja: ";
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << " ";
		if (i != words.size() - 1) {
			cout << ", " ;
		}
	}

	return 0;
}