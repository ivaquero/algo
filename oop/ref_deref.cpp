#include <cstdio>

int main() {
  int original = 100;
  int &original_ref = original;
  printf("Original: %d\n", original);
  printf("Reference: %d\n", original_ref);
  // Original: 100
  // Reference: 100

  int new_value = 200;
  original_ref = new_value;
  printf("Original: %d\n", original);
  printf("Reference: %d\n", original_ref);
  // Original: 200
  // Reference: 200
}
