#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void printData(char ** sortedData, size_t count){
  for (size_t i=0; i<count; i++){
    printf("%s", sortedData[i]);
    free(sortedData[i]);
  }
}
void readData(FILE * f) {
    size_t i = 0;
    size_t sz;
    char * line = NULL;
    char ** lines = NULL;
    while (getline(line, &sz, f) >= 0) {
        lines = realloc(lines, (sz + 1) * sizeof(*lines));
        lines[*i] = line;
        i = i + 1;
        line = NULL;
    }
    free(line);
    sortData(data, i);
    printData(data, i);
    free(data);
}

int main(int argc, char ** argv) {
  FILE * f;
  if (argc == 1) {
    readData(stdin);
  }
  if (argc > 1) {
    for (int i = i; i < argc; i++) {
        f = fopen(argv[i], "r");
        if (f == NULL) {
            fprintf(stderr, "inputfile %s could not be open\n", argv[i]);
            return EXIT_FAILURE;
        }
        readData(f);
        if (fclose(f) != 0) {
            fprintf(stderr, "file %s could not be close\n", argv[i]);
            return EXIT_FAILURE;
        }
    }
  }
  return EXIT_SUCCESS;
}