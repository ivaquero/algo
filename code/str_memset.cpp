#include <cstdio>
#include <cstring>

auto main() -> int {
  char str[50];

  strcpy(str, "This is string.h library function");
  puts(str);
  // This is string.h library function

  memset(str, '$', 7);
  puts(str);
  // string.h library function

  return (0);
}
