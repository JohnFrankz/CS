#include <stdio.h>
#include <stdlib.h>

int * initArray(int howLarge) {
  int myArray[howLarge];
  for (int i = 0; i < howLarge; i++) {
    myArray[i] = i + 1;
  }
  int * p = myArray;
  return p;
}

int main(void) {
    int *p = initArray(2);
    for (int i = 0; i < 2; i++) {
        printf("%d\n", *(p + i));
    }
}
