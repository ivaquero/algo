#include <algorithm>
#include <cstdio>
#include <vector>
// adjacent_find 查找相邻重复元素 面试
void AdjFind() {
    std::vector<int> v = {1, 2, 5, 3, 4, 4, 3};
    // 查找相邻元素
    auto it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        printf("not found\n");
    } else {
        printf("duplicated: %d\n", *it);
    }
}

void biSearch() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    // 查找的容器中元素必须的有序序列
    // 二分查找，返回布尔值
    bool ret = binary_search(v.begin(), v.end(), 2);
    if (ret) {
        printf("found\n");
    } else {
        printf("not found\n");
    }
}

int main() {
    // AdjFind();
    biSearch();
}
