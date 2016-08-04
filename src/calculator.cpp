#include <stdio.h>
#include <iostream>
#include <sstream>

#include "helpers.h"
#include "singleop.h"
#include "dualop.h"

using std::string;

int main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stdout, "Usage: %s operation number1 [number2]\n", argv[0]);
    return 1;
  }

  std::istringstream snumber1(argv[2]);
  int number1;
  int number2;
  string op = argv[1];

  const char *singleOpInit[] = {"collatz"};
  std::vector<string> singleOp(singleOpInit, singleOpInit + 1);

  const char *dualOpInit[] = {"+"};
  std::vector<string> dualOp(dualOpInit, dualOpInit + 1);

  // Convert argv[2] into an int
  if (!(snumber1 >> number1)) {
    std::cerr << "Invalid number1: " << argv[2] << std::endl;
    return 0;
  }

  if (!in_array(op, (argc >= 4) ? dualOp : singleOp)) {
    std::cerr << "Invalid operation: " << argv[1] << std::endl;
  }

  // 2 number operations
  if (argc >= 4) {
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
