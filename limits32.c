#ifndef LIMITS32_C
#define LIMITS32_C

#include "includes/assert.c"
#include "includes/types32.c"

const i8  I8_MIN  = -128;
const i8  I8_MAX  =  127;
const u8  U8_MAX  =  255;

const i16 I16_MIN = -32768;
const i16 I16_MAX =  32767;
const u16 U16_MAX =  65535;

const i32 I32_MIN = -2147483648;
const i32 I32_MAX =  2147483647;
const u32 U32_MAX =  4294967295;

void assert_limits32(void) {
  const u8 max8_unsigned = 0xff;
  assert(U8_MAX == max8_unsigned, "U8_MAX: expected %lu but got %lu\n", max8_unsigned, U8_MAX);
     
  const i8 min8_signed = 0x80;
  assert(I8_MIN == min8_signed, "I8_MIN: expected %d but got %d\n", min8_signed, I8_MIN);

  const i8 max8_signed = 0x7f;
  assert(I8_MAX == max8_signed, "I8_MAX: expected %d but got %d\n", max8_signed, I8_MAX);

  const u16 max16_unsigned = 0xffff;
  assert(U16_MAX == max16_unsigned, "U16_MAX: expected %d but got %d\n", max16_unsigned, U16_MAX);

  const i16 min16_signed = 0x8000;
  assert(I16_MIN == min16_signed, "I16_MIN: expected %d but got %d\n", min16_signed, I16_MIN);

  const i16 max16_signed = 0x7fff;
  assert(I16_MAX == max16_signed, "I16_MAX: expected %d but got %d\n", max16_signed, I16_MAX);

  /*
   * 2^32 - 1 = 2 * 2^31 - 1 = 2^31 - 1 + 2^31 = 2^30 * 2 - 1 + 2^30 * 2
   */
  const u32 two_pow_thirty_unsigned = 1024 * 1024 * 1024;
  u32       max32_unsigned;
  max32_unsigned  = 2 * two_pow_thirty_unsigned;
  max32_unsigned -= 1;
  max32_unsigned += 2 * two_pow_thirty_unsigned;
  assert(U32_MAX == max32_unsigned, "U32_MAX: expected %lu but got %lu\n", max32_unsigned, U32_MAX);
  assert(0xffffffff == U32_MAX, "U32_MAX in binary: expected %lu but got %lu\n", 0xffffffff, U32_MAX);
  
  /*
   * 2^31 - 1 = 2 * 2^30 - 1 = 2^30 - 1 + 2^30
   */
  const i32 two_pow_thirty_signed = 1024 * 1024 * 1024;
  i32       max32_signed;
  max32_signed  = two_pow_thirty_signed;
  max32_signed -= 1;
  max32_signed += two_pow_thirty_signed;
  assert(I32_MAX == max32_signed, "I32_MAX: expected %d but got %d\n", max32_signed, I32_MAX);
  assert(0x7fffffff == I32_MAX, "I32_MAX in binary: expected %d but got %d\n", 0x7fffffff, I32_MAX);
}

#endif
