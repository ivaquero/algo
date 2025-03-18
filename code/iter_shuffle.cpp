#include <algorithm>
#include <cstdio>
#include <random>
#include <vector>

class myPrint { // 打印仿函数 全局调用
public:
  void operator()(int val) { printf("%d\n", val); }
};

void shuffle_() {
  std::vector<int> v;
  v.reserve(10);
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }

  printf("Original order:\n");
  for_each(v.begin(), v.end(), myPrint());

  printf("After shuffle:\n");
  std::random_device rnd;
  std::mt19937_64 seed(rnd());
  shuffle(v.begin(), v.end(), seed);
  for_each(v.begin(), v.end(), myPrint());
}

auto main() -> int { shuffle_(); }
