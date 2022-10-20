#include <stdio.h>
#include <stdlib.h>

int isalpha(int);

int main(int argc, char **argv)
{
    if (argc != 2) {}
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {}
    int c;
    int letter = 0;
    while ((c = fgetc(f)) != EOF) {
        if (isalpha(c)) {
            letter++;
        }
    }
    printf("%s has %d letters in it.\n", argv[1], letter);
    return EXIT_SUCCESS;
}

int isalpha(int c) {
    if (c > 0 && c < 255) {
        return 1;
    } 
    return 0;
}