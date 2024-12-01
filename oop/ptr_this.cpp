#include <cstdio>

struct ClockOfTheLongNow {
  auto set_year(int year) -> bool {
    if (year < 2019)
      return false;
    this->year = year;
    return true;
  }
  auto get_year() -> int { return year; }

private:
  int year;
};

auto main() -> int {
  ClockOfTheLongNow clock;
  ClockOfTheLongNow *clock_ptr = &clock;
  printf("Address of clock: %p\n", clock_ptr);

  clock_ptr->set_year(2020);
  // 等同于
  // clock.set_year(2019);

  printf("Value of clock's year: %d", clock_ptr->get_year());
  // 等同于
  // printf("Value of clock's year: %d", (*clock_ptr).get_year());
}
