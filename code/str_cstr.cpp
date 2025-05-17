#include <cstdio>
#include <string>

auto main() -> int {
  // typedef basic_string<char, char_traits<char>, allocator<char>> string
  const char *str = "hello";
  printf("pointer of str.c_str() is %p\n", str);
  printf("value of str.c_str() is %c\n", *str);

  // const char * -> string，可隐式转换
  std::string s(str);

  // string -> const char *，不可隐式转换
  const char *str2 = s.c_str();
  printf("pointer of str.c_str() is %p\n", str2);
  printf("value of str.c_str() is %c\n", *str2);
}
