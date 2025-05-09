#include <iostream>
using namespace std;

class Box {
public:
  double getVolume() { return length * breadth * height; }

  void setLength(double l) { length = l; }
  void setBreadth(double b) { breadth = b; }
  void setHeight(double h) { height = h; }

  // 重载 + 运算符，用于把两个 Box 对象相加
  Box operator+(const Box &b) {
    Box box;
    box.length = this->length + b.length;
    box.breadth = this->breadth + b.breadth;
    box.height = this->height + b.height;
    return box;
  }

private:
  double length;  // 长度
  double breadth; // 宽度
  double height;  // 高度
};

// 程序的主函数
auto main() -> int {
  Box Box1;            // 声明 Box1，类型为 Box
  Box Box2;            // 声明 Box2，类型为 Box
  Box Box3;            // 声明 Box3，类型为 Box
  double volume = 0.0; // 把体积存储在该变量中

  // Box1 详述
  Box1.setLength(1.0);
  Box1.setBreadth(2.0);
  Box1.setHeight(3.0);

  // Box2 详述
  Box2.setLength(2.0);
  Box2.setBreadth(4.0);
  Box2.setHeight(6.0);

  // Box1 的体积
  volume = Box1.getVolume();
  cout << "Volume of Box1 : " << volume << '\n';
  // Box2 的体积
  volume = Box2.getVolume();
  cout << "Volume of Box2 : " << volume << '\n';
  // 把两个对象相加，得到 Box3
  Box3 = Box1 + Box2;

  // Box3 的体积
  volume = Box3.getVolume();
  cout << "Volume of Box3 : " << volume << '\n';

  return 0;
}
