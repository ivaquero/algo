long long reversed = 0;
long long temp;

auto main() -> int {

  while (temp != 0) {
    int digit = temp % 10;
    reversed = reversed * 10 + digit;
    temp /= 10;
  }
  return reversed;
}
