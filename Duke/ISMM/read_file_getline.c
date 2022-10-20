#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t sz = 0;
    size_t len = 0;
    char * line = NULL;
    char ** lines = NULL;
    size_t i = 0;
     
    FILE * f = fopen("fuck.txt", "r");
    while((len = getline(&line, &sz, f) >= 0)) {
        lines = realloc(lines, (i + 1) * sizeof(*lines));
        lines[i] = line;
        line = NULL;
        i++;
    }
    free(line);
    for (size_t j = 0; j < i; j++) {
        printf("%s", lines[j]);
        free(lines[j]);
    }
    free(lines);
    return EXIT_SUCCESS;
}