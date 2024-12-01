#include <cstdio>

auto main() -> int {
  char names1[] = {'j', 'a', 'c', 'k', '\0'};
  char names2[] = "jack";
  char *names3 = "jack";

  printf("Size of the string: %lu\n", sizeof(names1)); // 5
  printf("Size of the string: %lu\n", sizeof(names2)); // 5
  printf("Size of the string: %lu\n", sizeof(names3)); // 8

  return 0;
}
