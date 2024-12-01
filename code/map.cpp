#include <map>
#include <utility>

void test() {
  std::map<int, int> m;
  // 插入方式 1
  m.insert(std::make_pair(1, 2));
  // 插入方式 2
  m[2] = 3;
}

auto main() -> int { test(); }
