#include <string>
#include <iostream>

using namespace std;

int main() {
    string plainText = "ATTACK AT DAWN";
    string cipherText = "";
    int key = 5;

    for (int i = 0; i < (int) plainText.length(); i++) {
        char plainChar = plainText[i];
        char cipherChar;

        if (plainChar >= 'A' && plainChar <= 'Z') {
            cipherChar = (plainText[i] + key - 'A') % 26 + 'A';
        } else {
            cipherChar = plainChar;
        }
        cipherText += cipherChar;
    }
    
    cout << "test windwos" << endl;
    cout << "test wsl" << endl;
    cout << "Plain text:  " << plainText << endl;
    cout << "Cipher text: " << cipherText << endl;
}
