#include <iostream>
using namespace std;

int main() {
    enum spectrum {
        red, orange, yellow, green, blue, violet, indigo, ultaviolet
    };

    spectrum band = orange;
    int color = blue;
    color = 3 + red;
    cout << color << endl;

}