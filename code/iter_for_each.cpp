#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

using namespace std::placeholders;

class MyPrint {
  public:
    void operator()(int val) {
        printf("value: %d\n", val);
        m_count++;
    }
    int m_count = 0;
};

// for each，有返回值
void for_each_test() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    MyPrint myprint = for_each(v.begin(), v.end(), MyPrint());
    printf("%d\n", myprint.m_count);
}

class MyPrint2 : public binary_function<int, int, void> {
  public:
    void operator()(int val, int start) const { printf("value: %d\n", val); }
};

// for each，绑定参数
void for_each_test2() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for_each(v.begin(), v.end(), bind(MyPrint2(), _1, 100));
}

int main() {
    for_each_test();
    //   for_each_test2();
}
