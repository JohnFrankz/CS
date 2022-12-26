#include<string>
#include <iostream>

using namespace std;

int main() {
    string stanfordTree = "Fear the tree";

    char c1 = stanfordTree[3];
    char c2 = stanfordTree.at(2);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    for (int i = 0; i < stanfordTree.length(); i++) {
        cout << i << " : '" << stanfordTree[i] << "'" << endl;
    }
    cout << endl;

    for (char c : stanfordTree) {
        cout << "'" << c << "'" << endl;
    }
}