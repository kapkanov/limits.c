#ifndef LIMITS32_C
#define LIMITS32_C


void assert(const int condition, const unsigned char format[], ...);
void assert_types32(void);
void assert_limits32(void);


#ifndef TYPES32_C
#define TYPES32_C

#ifndef ASSERT_C
#define ASSERT_C

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void assert(const int condition, const unsigned char format[], ...) {
  if (0 != condition)
    return;

  printf("Assertion failed. ");

  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);

  putchar('\n');
  exit(1);
}
#endif

typedef char           I8;
typedef unsigned char  U8;
typedef short          I16;
typedef unsigned short U16;
typedef int            I32;
typedef unsigned int   U32;
typedef float          F32;

void assert_types32(void) {
  assert(sizeof(I8)  == 1, "sizeof(I8) != 1");
  assert(sizeof(U8)  == 1, "sizeof(U8) != 1");
  assert(sizeof(I16) == 2, "sizeof(I16) != 2");
  assert(sizeof(U16) == 2, "sizeof(U16) != 2");
  assert(sizeof(I32) == 4, "sizeof(I32) != 4");
  assert(sizeof(U32) == 4, "sizeof(U32) != 4");
  assert(sizeof(F32) == 4, "sizeof(F32) != 4");
}

#endif


const I8  I8_MIN  = -128;
const I8  I8_MAX  =  127;
const U8  U8_MAX  =  255;

const I16 I16_MIN = -32768;
const I16 I16_MAX =  32767;
const U16 U16_MAX =  65535;

const I32 I32_MIN = -2147483648;
const I32 I32_MAX =  2147483647;
const U32 U32_MAX =  4294967295;


void assert_limits32(void) {
  const U8 max8_unsigned = 0xff;
  assert(U8_MAX == max8_unsigned, "U8_MAX: expected %lu but got %lu", max8_unsigned, U8_MAX);
     
  const I8 min8_signed = 0x80;
  assert(I8_MIN == min8_signed, "I8_MIN: expected %d but got %d", min8_signed, I8_MIN);

  const I8 max8_signed = 0x7f;
  assert(I8_MAX == max8_signed, "I8_MAX: expected %d but got %d", max8_signed, I8_MAX);

  const U16 max16_unsigned = 0xffff;
  assert(U16_MAX == max16_unsigned, "U16_MAX: expected %d but got %d", max16_unsigned, U16_MAX);

  const I16 min16_signed = 0x8000;
  assert(I16_MIN == min16_signed, "I16_MIN: expected %d but got %d", min16_signed, I16_MIN);

  const I16 max16_signed = 0x7fff;
  assert(I16_MAX == max16_signed, "I16_MAX: expected %d but got %d", max16_signed, I16_MAX);

  /*
   * 2^32 - 1 = 2 * 2^31 - 1 = 2^31 - 1 + 2^31 = 2^30 * 2 - 1 + 2^30 * 2
   */
  const U32 two_pow_thirty_unsigned = 1024 * 1024 * 1024;
  U32       max32_unsigned;
  max32_unsigned  = 2 * two_pow_thirty_unsigned;
  max32_unsigned -= 1;
  max32_unsigned += 2 * two_pow_thirty_unsigned;
  assert(U32_MAX == max32_unsigned, "U32_MAX: expected %lu but got %lu", max32_unsigned, U32_MAX);
  assert(0xffffffff == U32_MAX, "U32_MAX in binary: expected %lu but got %lu", 0xffffffff, U32_MAX);
  
  /*
   * 2^31 - 1 = 2 * 2^30 - 1 = 2^30 - 1 + 2^30
   */
  const I32 two_pow_thirty_signed = 1024 * 1024 * 1024;
  I32       max32_signed;
  max32_signed  = two_pow_thirty_signed;
  max32_signed -= 1;
  max32_signed += two_pow_thirty_signed;
  assert(I32_MAX == max32_signed, "I32_MAX: expected %d but got %d", max32_signed, I32_MAX);
  assert(0x7fffffff == I32_MAX, "I32_MAX in binary: expected %d but got %d", 0x7fffffff, I32_MAX);
}

#endif
