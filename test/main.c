#include "../limits32.c"
#include "../limits64.c"

I32 main(void) {
  assert_types32();
  assert_limits32();

  assert_types64();
  assert_limits64();

  return 0;
}
