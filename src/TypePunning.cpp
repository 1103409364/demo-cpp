#include <iostream>
#include <ostream>

struct Entity {
  int x, y;
  int *GetPosition() { return &x; }
};

void testTypePunning() {
  int a = 50;
  // 取了 4 bytes 的 int，转为 double（8 bytes）多读了 4 bytes
  double value = *(double *)&a;
  std::cout << value << std::endl;
  // 可以将Entity结构体看成是一个int数组 不用通过 e.x 就可以提取出这些整数
  // 不能是 class 会报错
  Entity e = {1, 3};
  // e 包含了这个int数组的开始地址，也就是包含了指向int的指针
  // C++【原始数组就是个指针】，储存第一个值的地址
  int *position = (int *)&e;
  std::cout << position[0] << "," << position[1] << std::endl; // 1, 3
  // 等效于下面这种写法。没有任何复制，只是选择了另一种方式来解释那段内存
  // 如果不想这么做类型转换，可以使用reinterpret_cast做同样的事情
  int *position2 = e.GetPosition();
  std::cout << position2[0] << "," << position2[1] << std::endl; // 1, 3
  // char 1 byte 右移 4 byte，解引用
  int y = *(int *)((char *)&e + 4);
  std::cout << y << std::endl;   // 3
  std::cout << e.y << std::endl; // 3
}