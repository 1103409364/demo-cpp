#include <iostream>
#include <ostream>

struct Vector3 {
  float x, y, z;
};
// 箭头操作符出了能够解引用，还可以用来获取内存偏移量
// 当你把数据序列化为一串字节流时，当你想要计算某些东西的偏移量时，
void testArrowOperator() {
  // 0 转为 Vector3，通过箭头访问 x 将会得到这些内存的布局。
  // & 取这个 x 的内存地址就能得到 x 的偏移量，因为是从 0 开始的。
  // 0 也可以换成 nullptr，指向起始位置？
  // Cast from pointer to smaller type 'int' loses information
  // 64位系统指针占用 8 bit。(int)(size_t) 或者 long 都能解决
  int offsetX = (int)(size_t) & ((Vector3 *)0)->x; // 同 &(((Vector3 *)0)->x)
  long offsetY = (long)&((Vector3 *)0)->y;
  long offsetZ = (long)&((Vector3 *)0)->z;

  std::cout << offsetX << std::endl; // 0
  std::cout << offsetY << std::endl; // 4
  std::cout << offsetZ << std::endl; // 8
}