#ifndef TYPES32_C
#define TYPES32_C

#include "assert.c"

typedef char                   i8;
typedef unsigned char          u8;
typedef short                  i16;
typedef unsigned short         u16;
typedef int                    i32;
typedef unsigned int           u32;
typedef float                  f32;

void assert_types32(void) {
  assert(sizeof(i8)  == 1, "sizeof(i8) != 1\n");
  assert(sizeof(u8)  == 1, "sizeof(u8) != 1\n");
  assert(sizeof(i16) == 2, "sizeof(i16) != 2\n");
  assert(sizeof(u16) == 2, "sizeof(u16) != 2\n");
  assert(sizeof(i32) == 4, "sizeof(i32) != 4\n");
  assert(sizeof(u32) == 4, "sizeof(u32) != 4\n");
  assert(sizeof(f32) == 4, "sizeof(f32) != 4\n");
}

#endif
