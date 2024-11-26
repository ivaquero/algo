#include <cstdio>
#include <iostream>
using namespace std;

int addAge(int);
void addAgePoint(int &);

int main(int argc, char **argv) {
  int age = 45;
  int newAge = addAge(45);
  printf("age = %d\n", newAge);
  printf("age = %d\n", age);
  printf("&age = %d\n", *&age);

  addAgePoint(age);
  printf("age = %d\n", age);
  return 0;
}

int addAge(int age) {
  int result = age + 1;
  return result;
}

void addAgePoint(int &age) {
  ++(age);

  printf("age = %d\n", age);
  printf("&age = %d\n", *&age);
}
