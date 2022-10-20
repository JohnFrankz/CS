#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * computeOutPutFileName(const char * inputName) {
  char * outputName = malloc((strlen(inputName) + 7) * sizeof(*outputName));
  strcpy(outputName, inputName);
  strcat(outputName, ".counts");
  return outputName;
}

