#ifndef HANC_TEST_HANC_TEST_H
#define HANC_TEST_HANC_TEST_H
#include <stdio.h>
#include <stdlib.h>

typedef void (*hanc_test_test_func)(int *);

typedef struct hanc_test_test {
  hanc_test_test_func test_func;
  const char *name;
} hanc_test_test_t;

#ifdef HANC_TEST

#ifdef _MSC_VER // MSVC specifics

#pragma section("hctsts$a", read) // Start of section
#define HCTSTS_START                                                           \
  _declspec(allocate("hctsts$a")) static hanc_test_test_t hctsts_start = {0};  \
  return &hctsts_start + 1;       // skip the first empty reference
#pragma section("hctsts$d", read) // Content/data of section
#pragma section("hctsts$z", read) // End of section
#define HCTSTS_END                                                             \
  _declspec(allocate("hctsts$z")) static hanc_test_test_t hctsts_end = {0};    \
  return &hctsts_end;
#define MSVC_SECTION_HCTSTS __declspec(allocate("hctsts$d"))
#define CLANG_SECTION_HCTSTS

#else // Clang & GCC specifics

#define MSVC_SECTION_HCTSTS
#define CLANG_SECTION_HCTSTS __attribute__((used, section("hctsts")))
#define HCTSTS_START                                                           \
  extern hanc_test_test_t __start_hctsts;                                      \
  return &__start_hctsts;
#define HCTSTS_END                                                             \
  extern hanc_test_test_t __stop_hctsts;                                       \
  return &__stop_hctsts;

#endif

#define HC_TEST(test_name, content)                                            \
  void test_name(int *);                                                       \
  MSVC_SECTION_HCTSTS static hanc_test_test_t hanc_test_##test_name            \
      CLANG_SECTION_HCTSTS = {                                                 \
          .test_func = test_name,                                              \
          .name = #test_name,                                                  \
  };                                                                           \
  void test_name(int *result) content

#define HC_ASSERT(expression)                                                  \
  if (!(expression)) {                                                         \
    printf("Failed at assertion (%s) in %s:%d\n", (#expression), __FILE__,     \
           __LINE__);                                                          \
    *result = 1;                                                               \
  }

#define HANC_TEST_MAIN(content)                                                \
  hanc_test_test_t *get_hanc_tests_start(void);                                \
  hanc_test_test_t *get_hanc_tests_end(void);                                  \
                                                                               \
  int main(void) {                                                             \
    int tst_count = 0;                                                         \
    int passed = 0;                                                            \
    hanc_test_test_t *start = get_hanc_tests_start();                          \
    hanc_test_test_t *end = get_hanc_tests_end();                              \
    for (hanc_test_test_t *test = start; test != end; ++test) {                \
      tst_count += 1;                                                          \
      int result = 0;                                                          \
      test->test_func(&result);                                                \
      if (result == 0) {                                                       \
        passed += 1;                                                           \
        printf("Test %s passed\n", test->name);                                \
      } else {                                                                 \
        printf("Test %s failed\n", test->name);                                \
      }                                                                        \
    }                                                                          \
    printf("%d/%d tests passed\n", passed, tst_count);                         \
    if (passed != tst_count)                                                   \
      return 1;                                                                \
    else                                                                       \
      return 0;                                                                \
  }                                                                            \
                                                                               \
  hanc_test_test_t *get_hanc_tests_start(void) { HCTSTS_START; }               \
  hanc_test_test_t *get_hanc_tests_end(void) { HCTSTS_END; }
#else
#define HC_TEST(test_name, content)

#define HANC_TEST_MAIN(content)                                                \
  int main(int argc, char **argv) {                                            \
    (void)argc;                                                                \
    (void)argv;                                                                \
    content                                                                    \
  }
#endif
#endif
