#include <iostream>
using namespace std;

class Box {
public:
  Box() { cout << "调用构造函数！" << '\n'; }
  ~Box() { cout << "调用析构函数！" << '\n'; }
};

auto main() -> int {
  Box *myBoxArray = new Box[4];

  delete[] myBoxArray; // 删除数组
  return 0;
}
