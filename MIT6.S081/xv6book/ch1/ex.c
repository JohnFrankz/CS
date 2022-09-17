#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s = "hello";
    char *es;
    es = s + strlen(s);
    printf("%s", es);
}