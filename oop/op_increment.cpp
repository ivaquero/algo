#include <iostream>
using namespace std;

int main() {
  int x = 10, y = 20;
  cout << "x = " << x++ << " and y = " << --y << endl;
  cout << "x = " << x-- << " and y = " << ++y << endl;
  return 0;
}
// x = 10 and y = 19
// x = 11 and y = 20
