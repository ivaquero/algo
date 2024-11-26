#include <cstdio>

int main() {
  char lower[] = "abc?e";
  char upper[] = "ABC?E";
  char *upper_ptr = &upper[0];

  *(lower + 3) = 'd';
  *(upper_ptr + 3) = 'D';
  printf("lower: %s\nupper: %s\n", lower, upper);
  // lower: abcde
  // upper: ABCDE%
}
