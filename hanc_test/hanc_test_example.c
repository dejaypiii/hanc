#include <stdio.h>

#include "add.h"
#include "hanc_test.h"

#ifndef HANC_TEST
int main(void) {
  printf("Hello hanc\n");
  int result = add(7, 4);
  printf("Add 7+4: %d\n", result);
  return 0;
}
#else

inline hanc_test_test_t *get_hanc_tests_start(void);
inline hanc_test_test_t *get_hanc_tests_end(void);

int main(void) {
  /* TODO
   * - Get test methods
   * - Include files
   * - Iterate and execute methods
   * - Print some logs
   */
    extern hanc_test_test_t __start_hanc_tests;
    __start_hanc_tests.test_func();

  // for (hanc_test_test_t *test = get_hanc_tests_start();
  //      test != get_hanc_tests_end(); ++test) {
  //     test->test_func();
  // }
}

inline hanc_test_test_t *get_hanc_tests_start(void) {
  extern hanc_test_test_t __start_hanc_tests;
  return &__start_hanc_tests;
}

inline hanc_test_test_t *get_hanc_tests_end(void) {
  extern hanc_test_test_t __stop_hanc_tests;
  return &__stop_hanc_tests;
}
#endif
