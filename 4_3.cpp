#include<iostream>
#include<string.h>
#include<cctype>
using namespace std;

string word_to_pig_latin(const string& word) {
	string sam = "aeiouAEIOU";
	char prvo = word[0];

	if (sam.find(prvo) != string::npos) { 
		return word + "hay";
	}
	else {
		return word.substr(1) + prvo + "ay"; 
	}
}

int main() {
	cout << word_to_pig_latin("apple") << endl;  
	cout << word_to_pig_latin("hello") << endl;  
	cout << word_to_pig_latin("World") << endl;  
	return 0;
}