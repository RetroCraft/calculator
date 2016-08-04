#include <stdio.h>
#include <iostream>

namespace calc {
  int add(int x, int y) {
    fprintf(stdout, "%d + %d = %d\n", x, y, x + y); 
    return x + y;
  }

  int subtract(int x, int y) {
    fprintf(stdout, "%d - %d = %d\n", x, y, x - y); 
    return x - y;
  }

  int multiply(int x, int y) {
    fprintf(stdout, "%d + %d = %d\n", x, y, x * y); 
    return x * y;
  }

  int divide(int x, int y) {
    fprintf(stdout, "%d + %d = %d\n", x, y, x / y); 
    return x / y;
  }

  int modulo(int x, int y) {
    fprintf(stdout, "%d mod %d = %d\n", x, y, x % y); 
    return x % y;
  }
}
