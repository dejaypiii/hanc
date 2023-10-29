#include "add.h"
#include "hanc_test.h"

int add(int a, int b) { return a + b; }

HC_TEST(add_test) { assert(11 == add(7, 4)); }
HC_TEST(add_test_2) {
     assert(1337 == add(7, 4));
}
