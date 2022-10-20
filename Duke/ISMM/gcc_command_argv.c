#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv, char ** envp) {
    printf("Hello, my name is %s.\n", argv[0]);
    printf("envp = %s\t", envp[0]);
    printf("%s\t", envp[1]);
    printf("%s\t", envp[2]);
    printf("%s\t", envp[3]);
    printf("%s\t", envp[4]);
    printf("%s\t", envp[5]);
    printf("%s\t", envp[6]);
    printf("%s\t", envp[7]);
    printf("%s\t", envp[8]);
    printf("%s\t", envp[9]);
    printf("%s\t", envp[10]);
    printf("%s\t", envp[11]);
    return EXIT_SUCCESS;
}