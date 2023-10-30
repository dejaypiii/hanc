#include "add.h"
#include "hanc_test.h"

int add(int a, int b) { return a + b; }

// HC_TEST(add_test, { assert(11 == add(7, 4)); })
// HC_TEST(add_test_2, {
//   assert(2 == add(1, 1));
//   assert(3 == add(1, 2));
//   assert(1337 == add(7, 4));
// })
void test_name(void);
static hanc_test_test_t hanc_test_test_name
    __attribute__((used, section("hanc_tests"))) = {
        .test_func = test_name,
};
void test_name(void) {
  assert(2 == add(1, 1));
  assert(3 == add(1, 2));
  assert(1347 == add(7, 4));
}
