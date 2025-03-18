#include <iostream>
using namespace std;

int8_t a = 200;
uint8_t b = 100;

auto main() -> int {
  cout << "a=" << a;
  cout << ", b=" << b;
  // a=-56, b=100
  return 0;
}
