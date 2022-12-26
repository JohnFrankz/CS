#include <iostream>
#include "all-examples.h"

using namespace std;

int main() {
    cout << square(15) << endl;
    if (even(42)) {
        cout << "evedsadn" << endl;
    } else {
        cout << "odd" << endl;
    }

}

int square(int x) {
    return x * x;
}

bool even(int v) {
    return v % 2 == 0;
}