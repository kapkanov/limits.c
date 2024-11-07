#ifndef LIMITS64_C
#define LIMITS64_C

#include "includes/assert.c"
#include "includes/types64.c"

const I64 I64_MIN = 0x8000000000000000; /* -9223372036854775808 */
const I64 I64_MAX = 0x7fffffffffffffff; /*  9223372036854775807 */
const U64 U64_MAX = 0xffffffffffffffff; /* 18446744073709551615 */

void assert_limits64(void) {
  /*
   * 2^64 - 1 = 2 * 2^63 - 1 = 2^63 - 1 + 2^63 = 2^60 * 8 - 1 + 2^60 * 8
   */
  const U64 two_pow_thirty_unsigned = 1024 * 1024 * 1024;
  const U64 two_pow_sixty_unsigned  = two_pow_thirty_unsigned * two_pow_thirty_unsigned;
  U64       max64_unsigned;
  max64_unsigned  = two_pow_sixty_unsigned;
  max64_unsigned  = 8 * two_pow_sixty_unsigned;
  max64_unsigned -= 1;
  max64_unsigned += 8 * two_pow_sixty_unsigned;
  assert(U64_MAX == max64_unsigned, "U64_MAX: expected %llu but got %llu\n", max64_unsigned, U64_MAX);
  
  /*
   * 2^63 - 1 = 8 * 2^60 - 1 = 4 * 2^60 - 1 + 4 * 2^60
   */
  const I64 two_pow_thirty_signed = 1024 * 1024 * 1024;
  const I64 two_pow_sixty_signed  = two_pow_thirty_signed * two_pow_thirty_signed;
  I64       max64_signed;
  max64_signed  = 4 * two_pow_sixty_signed;
  max64_signed -= 1;
  max64_signed += 4 * two_pow_sixty_signed;
  assert(I64_MAX == max64_signed, "I64_MAX: expected %lld but got %lld\n", max64_signed, I64_MAX);
}

#endif
