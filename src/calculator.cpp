#include <stdio.h>
#include <iostream>
#include <sstream>

#include "config.h"
#include "helpers.h"
#include "singleop.h"
#include "dualop.h"

using std::string;

int main(int argc, char** argv) {
  fprintf(stdout, "%s version %d.%d build %d\n", argv[0], VERSION_MAJOR, VERSION_MINOR, VERSION_BUILD);
  if (argc < 3) {
    fprintf(stdout, "Usage: %s operator number\n", argv[0]);
    fprintf(stdout, "       %s number operator number\n", argv[0]);
    return 1;
  }

  int number1;
  int number2;
  bool dual = argc >= 4;
  string op = argv[dual ? 2 : 1];

  const char *singleOpInit[] = {"collatz"};
  std::vector<string> singleOp(singleOpInit, singleOpInit + 1);

  const char *dualOpInit[] = {"+"};
  std::vector<string> dualOp(dualOpInit, dualOpInit + 1);

  // Convert first number into an int
  std::istringstream snumber1(argv[dual ? 1 : 2]);
  if (!(snumber1 >> number1)) {
    std::cerr << "Invalid number1: " << argv[dual ? 1 : 2] << std::endl;
    return 0;
  }

  if (!in_array(op, dual ? dualOp : singleOp)) {
    std::cerr << "Invalid operation: " << argv[1] << std::endl;
  }

  // 2 number operations
  if (dual) {
    // Convert argv[3] into an int
    std::istringstream snumber2(argv[3]);
    if (!(snumber2 >> number2)) {
      std::cerr << "Invalid number2: " << argv[3] << std::endl;
    }

    // Operations
    if (op == "+" || op == "add" || op == "plus") {
      return calc::add(number1, number2);
    } else if (op == "-" || op == "subtract" || op == "minus") {
      return calc::subtract(number1, number2);
    } else if (op == "/" || op == "divide") {
      return calc::divide(number1, number2);
    } else if (op == "*" || op == "x" || op == "multiply" || op == "times") {
      return calc::multiply(number1, number2);
    } else if (op == "%" || op == "mod" || op == "modulo") {
      return calc::modulo(number1, number2);
    }
  } else if (argc >= 3) {
    // 1 number operations (i.e. functions)
    if (op == "collatz") {
      return calc::collatz(number1);
    }
  }

}
