#include <iostream>
using namespace std;

auto max(int, int) -> int;
auto max(double, double) -> double;

auto main(int argc, char **argv) -> int {
  double x = 1.3;
  double y = 2.4;
  int a = 1;
  int b = 45;

  cout << max(x, y) << '\n';
  cout << max(a, b) << '\n';
  return 0;
}

auto max(int a, int b) -> int { return (a > b) ? a : b; }

auto max(double a, double b) -> double { return (a > b) ? a : b; }
