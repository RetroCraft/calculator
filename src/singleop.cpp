#include <iostream>

namespace calc {

  int collatz_sub(int in) {
    int out = in << 1;
    out = out + 1;
    out = out + in;
    while (out % 2 == 0) {
      out = out >> 1;
    }
    std::cout << "Collatz: ";
    std::cout << in << "->" << out << std::endl;
    return out;
  }

  int collatz(int in) {
    int i = 0;

    while (in != 1 && in != 0) {
      in = collatz_sub(in);
      i++;
    }

    std::cout << "Final: " << in << std::endl;
    std::cout << "Count: " << i << std::endl;

    return 1;
  }

}
