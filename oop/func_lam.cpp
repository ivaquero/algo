#include <stdio.h>
#include <string>

int main() {
  int a = 1, b = 2, c = 3;
  auto retVal = [=, &a, &b]() mutable -> int {
    printf("inner c[%d]\n", c);
    a = 10;
    b = 20;
    c = 30;
    printf("inner c2[%d]\n", c);
    return a + b;
  };

  printf("sum[%d]\n", retVal());
  printf("a[%d] b[%d] c[%d]\n", a, b, c);
  return 0;
}
