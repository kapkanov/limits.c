#ifndef TYPES64_C
#define TYPES64_C

#include "assert.c"

typedef long long int          I64;
typedef unsigned long long int U64;
typedef double                 F64;

void assert_types64(void) {
  assert(sizeof(I64) == 8, "sizeof(I64) != 8\n");
  assert(sizeof(U64) == 8, "sizeof(U64) != 8\n");
  assert(sizeof(F64) == 8, "sizeof(F64) != 8\n");
}

#endif
