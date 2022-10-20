#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  FILE *f = fopen(filename, "r");
  if (f==NULL){
    fprintf(stderr, "File specified not found");
    assert(f!=NULL);
    return NULL;
  }
  counts_t * count= createCounts();
  char * line=NULL;
  size_t sz=0;
  char * value = NULL;
  char * ptr1 = NULL;
  while (getline(&line, &sz, f)!=EOF){
    ptr1 = strchr(line, '\n');
    *ptr1='\0';
    value = lookupValue(kvPairs, line);
    addCount(count, value);
  }
  free(line);

  //  printKVs(kvPairs);
  //printf("%d", kvPairs->list_len);
  if(fclose(f)!=0){
    fprintf(stderr, "Unable to close countFile");
    return NULL;
  }
  return NULL;
}

int main(int argc, char ** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: Enter at least 2 files as arguments\n");
        return EXIT_FAILURE;
    }

    kvarray_t * kv = readKVs(argv[1]);
    counts_t * c = NULL;
    char * suffix = ".counts";

    for (int i = 2; i < argc; i++) {
        c = countFile(argv[i], kv);
        char * outputFile = malloc((strlen(argv[i]) + strlen(suffix) + 1) *
                                        sizof(*outputFile));
        FILE * f = fopen(outputFile, "w");
        printCounts(c, f);
        if (fclose(f) != 0) {
            fprintf(stderr, "Unable to close file after writing");
            return EXIT_FAILURE;
        }
        free(outputFile);
        freeCounts(c);
    }
    freeKVs(kv);
    return EXIT_SUCCESS;
}