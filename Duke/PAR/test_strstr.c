#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char * str = "bannanaab";
    const char * a = strchr(str, 'a');
    a++;
    printf("%c\n", *a);
    printf("%c\n", a[2]);
    a = strstr(str, "nana");
    if (a != NULL) {
      printf("%s has %s %ld characters into it!\n", str, a, a - str);
    }
    char *b = NULL;
    printf("%ld\n", strlen(b));
}