#include <stdio.h>
#include <stdlib.h>

typedef int (*int_function_t) (int);

int inc(int);
int square(int);
void doToAll(int *, int, int_function_t);
void printArrayInt(int *, int);


int main(void) {
    int data[] = {1, 2, 3, 4, 5};
    doToAll(data, 5, square);
    printArrayInt(data, 5);
    doToAll(data, 5, inc);
    printArrayInt(data, 5);
}

int inc(int x) {
    return x + 1;
}

int square(int x) {
    return x * x;
}

void doToAll(int * data, int n, int_function_t f) {
    for (int i = 0; i < n; i++) {
        data[i] = f(data[i]);
    }
}

void printArrayInt(int * data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", data[i]);
    }
    printf("\n");
}