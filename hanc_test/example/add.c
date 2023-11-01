#include "add.h"
#include "../hanc_test.h"

int add(int a, int b) { return a + b; }

HC_TEST(add_test, { HC_ASSERT(11 == add(7, 4)); })
HC_TEST(add_test_2, {
  HC_ASSERT(2 == add(1, 1));
  HC_ASSERT(3 == add(1, 2));
  HC_ASSERT(11 == add(7, 4));
})
