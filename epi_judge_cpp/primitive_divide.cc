#include "test_framework/generic_test.h"
int Divide(int x, int y) {
  // TODO - you fill in here.
  if (x < y) return 0;

  unsigned int result = 0;
  while(x >= y) {
    int k = 1;

    // find the largest k
    while( (y<<k) <= x && (y<<k) >= (y<<(k-1))){
      // Checks (y << power) >= (y << (power - 1)) to prevent potential overflow of unsigned.
      k++;
    }

    // update x to keep dividing
    // subtract 1 because the while loop add 1 more to k for breaking
    result += 1 << (k-1);
    x = x - (y<<(k-1));
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
