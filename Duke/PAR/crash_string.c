#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char * str = "12345";
    printf("%p\n", str);
    printf("%p\n", &str);
    printf("%p\n", str[1]);
    printf("%p\n", &str[1]);
    int x = str;
    printf("%x\n", x);
    x = *str;
    printf("%d\n", x);
    return EXIT_SUCCESS;
}