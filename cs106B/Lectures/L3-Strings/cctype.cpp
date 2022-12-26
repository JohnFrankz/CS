#include <cctype>
#include <iostream>

using namespace std;

int main() {
    string mixed = "ab80c3d27";
    string hiThere = mixed + "hi" + "there";
    string hiQuestion = "hi" + '?'; // C-string + char
    string hi41 = "hi" + 41;  // C-string + int

    cout << hiQuestion << " " << hi41 << endl;

    cout << "The digits in " << mixed << ": " << endl;

    for (int i = 0; i < mixed.length(); i++) {
        if (isdigit(mixed[i])) {
            cout << mixed[i] << endl;
        }
    }

    string s = "my string";
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    cout << "Now " << s << " is all UPPERCASE." << endl;
}