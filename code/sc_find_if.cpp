#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

class Person {
  public:
    Person(std::string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    // 重载 ==
    bool operator==(const Person &p) {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        }
        return false;
    };

  public:
    std::string m_Name;
    int m_Age;
};

void findPerson() {
    std::vector<Person> v;
    // 创建数据
    Person p1("Jhon", 18);
    Person p2("Joe", 38);
    Person p3("Eminem", 50);
    Person p4("Dr. Dre", 55);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    // 查找
    auto it = find(v.begin(), v.end(), p3);
    if (it == v.end()) {
        printf("not found\n");
    } else {
        printf("found! name: %s, age: %d.\n", it->m_Name.c_str(), it->m_Age);
    }
}

// find_if(iterator beg, iterator end, _Pred); 按条件查找元素
// 内置数据类型
class GreaterFive { // 定义仿函数  找到大于 5
  public:
    bool operator()(int val) { return val > 5; }
};

void findIf() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }
    auto it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end()) {
        printf("not found");
    } else {
        printf("num: %d.\n", *it);
    }
}

int main() {
    //   findPerson();
    findIf();
}
