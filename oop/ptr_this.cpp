#include <cstdio>

struct ClockOfTheLongNow {
  bool set_year(int year) {
    if (year < 2019)
      return false;
    this->year = year;
    return true;
  }
  int get_year() { return year; }

private:
  int year;
};

int main() {
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
