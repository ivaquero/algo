#include <array>

struct student {
  std::array<char, 20> Name;
  float Math;
  float English;
  float Physical;
} stu[2] = {{"zhang", 78, 89, 95}, {"wang", 87, 79, 92}};
