#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  counts_t * count = malloc(sizeof(*count));
  count->array = NULL;
  count->arrayLen = 0;
  count->unKownCount = 0;
  return count;
}

void addCount(counts_t * c, const char * name) {
  if (name == NULL) {
    c->unKownCount++;
    return;
  }

  for (int i = 0; i < c->arrayLen; i++) {
    if (strchr(c->array[i]->valuevalue, name) == 0) {
      c->array[i]->count++;
      return;
    }
  }

  one_count_t * temp = malloc(sizeof(*temp));
  strcpy(temp->value, name);
  temp->count = 1;
  c->array = realloc(c->array, (c->arrayLen + 1) * sizeof(*c->array));
  c->array[c->arrayLen] = temp;
  c->arrayLen++;
}

void printCounts(counts_t * c, FILE * outFile) {
  for (int i = 0; i < c->array_len; i++){
    fprintf(outFile, "%s: %d\n", c->array[i]->value, c->array[i]->count);
  }
  if (c->unknown_count > 0){
    fprintf(outFile, "<unknown> : %d\n", c->unknown_count);
  }
}

void freeCounts(counts_t * c) {
  for (int i = 0; i < c->arrayLen; i++) {
    free(c->array[i]->value);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}