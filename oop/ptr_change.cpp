#include <vector>
using namespace std;

vector<int> v1{1, 2, 3}, v2;
vector<int> *w1 = new vector<int>({1, 2, 3});
vector<int> *w2;

auto main() -> int {
  v1.push_back(4);
  v2.push_back(5);
  // v1: 1, 2, 3, 4,
  // v2: 1, 2, 3, 5,

  w2 = w1;
  w1->push_back(4);
  w2->push_back(5);
  // w1: 1, 2, 3, 4, 5
  // w2: 1, 2, 3, 4, 5
  return 0;
}
