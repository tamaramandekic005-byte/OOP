#include <iostream>
#include <string>
using namespace std;

void fix_spaces(string& text) {
    string result;

    for (char c : text) {
        if (c == ' ') {
            if (!result.empty() && result.back() != ' ') 
                result += ' ';
        }
        else if (c == ',' || c == '.') {
            if (!result.empty() && result.back() == ' ') 
                result.pop_back();            
            result += c;
            if (c == ',')
                result += ' ';
        }
        else {
            result += c;
        }
    }
    text = result;
}

int main() {
    string s = "Puno   razmaka ,i tocka .";
    fix_spaces(s);

    cout << "String: " << s << endl;

    return 0;
}
