#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ) {
        printf("%d\n",(i++)[a]);
    }
    return EXIT_SUCCESS;
}