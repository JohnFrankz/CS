#include <stdio.h>
#include <stdlib.h>
#include <valgrind/memcheck.h>

int main(void) {
  int y;
  int z = 3 + y;
  VALGRIND_CHECK_MEM_IS_DEFINED(&z,sizeof(z));
  printf("%d\n", z);
}