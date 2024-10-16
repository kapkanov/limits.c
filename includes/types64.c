#ifndef TYPES64_C
#define TYPES64_C

#include "assert.c"

typedef long long int          i64;
typedef unsigned long long int u64;
typedef double                 f64;

void assert_types64(void) {
  assert(sizeof(i64) == 8, "sizeof(i64) != 8\n");
  assert(sizeof(u64) == 8, "sizeof(u64) != 8\n");
  assert(sizeof(f64) == 8, "sizeof(f64) != 8\n");
}

#endif
