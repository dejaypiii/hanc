#include <stdio.h>

#include "add.h"
#include "add.c"

#ifndef HANC_TEST
int main(void) {
  printf("Hello hanc\n");
  int result = add(7, 4);
  printf("Add 7+4: %d\n", result);
  return 0;
}
#else
int main(void) {
    /* TODO 
     * - Get test methods 
     * - Include files  
     * - Iterate and execute methods
     * - Print some logs
    */

    add_test();
    add_test_2();
}
#endif

