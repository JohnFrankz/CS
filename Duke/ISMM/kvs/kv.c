#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "kv.h"

kvpair_t * sparateKeyValueToPair(FILE * f) {
    char * line = NULL;
    size_t sz = 0;

    if (getline(&line, &sz, f) == EOF) {
      free(line);
      return NULL;
    }

    char * ptr1 = strchr(line, '=');
    if (ptr == NULL) {
       return NULL;
    }

    char * ptr2 = strchr(line. '\n');
    *ptr1 = '\0';
    *ptr2 = '\0';
    kvpair_t * ans = malloc(sizeof(*ans));
    ans->key = line;
    ptr1++;
    ans->value = ptr1;
    return ans;
}


kvarray_t * readKVs(const char * fname) {
    FILE * f = fopen(fname, "r");
    if (f == NULL) {
      return NULL;
    }

    kvarray_t * kva = malloc(sizeof(*kva));
    kvpair_t * pair = NULL;
    if (kva == NULL) {
      free(kva);
      return NULL;
    }
    kva->kvs = NULL;
    kva->num_kvs = 0;

    while ((pair = sparateKeyValueToPair(f)) != NULL) {
        kva->kvs = realloc(kva->kvs, (kva->num_kvs + 1) * sizeof(*kva->kvs));
        kva->kvs[kva->num_kvs] = pair;
        kva->num_kvs++;
    }
    free(line);
    assert(fclose(f) == 0);
    return kva;
}

void freeKVs(kvarray_t * pairs) {
    for (int i = 0; i < pairs->num_kvs; i++) {
      free(pairs->kvs[i]->key);
      free(pairs->kvs[i]->value);
      free(pairs->kvs[i])
    }
    free(pairs->kvs);
    free(pairs);
}

void printKVs(kvarray_t * pairs) {
    for(int i = 0; i < pairs->num_kvs; i++) {
      printf("key = '%s' value = '%s'\n", pairs->kvs[i]->key, pairs->kvs[i]->value);
    }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
    for(int i = 0; i < pairs->num_kvs; i++) {
        if (strcmp(pairs->kvs[i].key, key) == 0) {
          return pairs->kvs[i]->value;
        }
    }
    return NULL;
}