#include <stdio.h>

#include "add.h"
#include "hanc_test.h"

HANC_TEST_MAIN({
  printf("Hello hanc\n");
  int result = add(7, 5);
  printf("Add 7+5: %d\n", result);
  return 0;
})
