#include <cstdio>

struct ClockOfTheLongNow {
  void add_year() { year++; }
  auto set_year(int new_year) -> bool {
    if (new_year < 2019)
      return false;
    year = new_year;
    return true;
  }
  auto get_year() -> int { return year; }

private:
  int year;
};

auto main() -> int {
  ClockOfTheLongNow clock;
  if (!clock.set_year(2018)) {
    // will fail; 2018 < 2019
    clock.set_year(2019);
  }
  clock.add_year();
  printf("year: %d", clock.get_year());
}
