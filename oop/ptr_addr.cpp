#include <cstdio>

auto main() -> int {
  int var = 0;
  int *var_address = &var;
  printf("Value at var_address: %d\n", *var_address);
  printf("Var Address: %p\n", var_address);
  // Value at var_address: 0
  // Var Address: 0x16b8d2edc

  *var_address = 17325;
  printf("Value at var_address: %d\n", *var_address);
  printf("Var Address: %p\n", var_address);
  // Value at var_address: 17325
  // Var Address: 0x16b8d2edc
}
