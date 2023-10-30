#ifndef HANC_TEST_HANC_TEST_H
#define HANC_TEST_HANC_TEST_H
#include <assert.h>

typedef void (*hanc_test_test_func)(void);

typedef struct hanc_test_test {
  hanc_test_test_func test_func;
} hanc_test_test_t;

#ifdef HANC_TEST
#define HC_TEST(test_name, content)                                            \
  void test_name(void);                                                        \
  static hanc_test_test_t hanc_test_##test_name                                \
      __attribute__((used, section("hanc_tests"))) = {                         \
          .test_func = test_name,                                              \
  };                                                                           \
  void test_name(void) content
#else
#define HC_TEST(test_name, content)
#endif

#endif
