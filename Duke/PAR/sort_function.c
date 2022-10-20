#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void*));
int compareInts(const void *, const void *);
void sortIntArray(int *, size_t);
int compareStrings(const void *, const void *);
void sortStringArray(const char **, size_t);

int main(void) {
    printf("%ld\n", sizeof(const char *));
    char * fuck = "asdnbabs";
    const void * s1vp = fuck;
    const char * const * s = s1vp;
    printf("%d\n", strcmp(*s, "hello"));
}

int compareInts(const void * n1vp, const void * n2vp) {
    // convert back to int* so we can dereference
    const int * n1ptr = n1vp;
    const int * n2ptr = n2vp;

    // subtracting the two numbers compares them
    return *n1ptr - *n2ptr;
}

void sortIntArray(int * array, size_t nelements) {
    qsort(array, nelements, sizeof(int), compareInts);
}

int compareStrings(const void * s1vp, const void * s2vp) {
    // first const: s1vp is actually points at (const cahr *), so we can dereference
    // second const: we cannot change *s1vp
    const char * const * s1ptr = s1vp;
    const char * const * s2ptr = s2vp;

    return strcmp(*s1ptr, *s2ptr);
}

void sortStringArray(const char ** array, size_t nelements) {
    qsort(array, nelements, sizeof(const char *), compareStrings);
}