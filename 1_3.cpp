/*#include<iostream>
#include<string>
#include<cctype>

int main() {
	std::string s;
	std::cout << "Unesite jedan redak: ";
	std::getline(std::cin, s);

	for (char &c : s) {
		if (std::isalpha(c)) {
			c = toupper(c);
		}
		else if (std::isdigit(c)) {
			c = '*';
		}
		else if (c == ' ' || c == '\t') {
			c = '_';
		}
	}
	std::cout << "Novi string je:" << s << std::endl;
	return 0;
}
*/
