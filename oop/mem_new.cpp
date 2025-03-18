#include <iostream>
using namespace std;

auto main() -> int {
  double *pvalue = nullptr; // 初始化为 null 的指针
  pvalue = new double;      // 为变量请求内存
  *pvalue = 29494.99;       // 在分配的地址存储值
  cout << "Value of pvalue : " << *pvalue << '\n';
  delete pvalue; // 释放内存

  return 0;
}
