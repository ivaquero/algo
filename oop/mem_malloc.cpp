#include <cstdio>
#include <cstdlib>
#include <cstring>

auto main() -> int {
  char *str;

  /* 最初的内存分配 */
  str = (char *)malloc(15);
  strcpy(str, "runoob");
  printf("String = %s,  Address = %u\n", str, *str);
  // String = runoob,  Address = 114

  /* 重新分配内存 */
  str = (char *)realloc(str, 25);
  strcat(str, ".com");
  printf("String = %s,  Address = %u\n", str, *str);
  // String = runoob.com, Address = 114
  free(str);

  return (0);
}
