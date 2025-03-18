#include <iostream>
using namespace std;

auto main() -> int {
  int x = 10, y = 20;
  cout << "x = " << x++ << " and y = " << --y << '\n';
  cout << "x = " << x-- << " and y = " << ++y << '\n';
  return 0;
}
// x = 10 and y = 19
// x = 11 and y = 20
