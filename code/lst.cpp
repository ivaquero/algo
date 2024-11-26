#include <cstdio>
#include <list>
void test() {
    std::list<int> L1{10, 20, 30};

    for (auto it = L1.begin(); it != L1.end(); it++) {
        printf("%d\n", *it);
    }

    for (auto it = L1.rbegin(); it != L1.rend(); it++) {
        printf("%d\n", *it);
    }
}

int main() { test(); }
