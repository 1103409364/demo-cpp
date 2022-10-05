#include <iostream>
#include <ostream>
#include <vector>
struct Vertex {
  float x, y, z;
};
// 重载 << 运算符，便于打印，类似其他语言重写 toString() 打印对象
std::ostream &operator<<(std::ostream &stream, const Vertex &vertex) {
  return stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
}
// 传递动态数组时，需要确保传递的是引用
void printVector(std::vector<Vertex> &vertices) {
  // Range-based for loop is a C++11 extension
  for (const Vertex &v : vertices) {
    std::cout << v << std::endl;
  }
};

void testVector() {
  // 范型参数 <> 可以使用基本类型 <int> java 中需要使用 Integer，不能用基本类型
  // 存指针还是存值？视情况而定，主要考虑存储vertex对象比存储指针在技术上更优
  // 存储对象在内存分配将是一条线上的，连续的，这是最优的。内存连续，数组操作更快
  // 动态数组 vector 在内存上是连续的。
  // vector 的访问和普通数组类似，可以通过下标访问
  std::vector<Vertex> vertices;
  // 直接 push 报错：Expected expression。中间变量 v 接一下，报错消失
  vertices.push_back({1.0f, 2.0f, 3.0f});
  Vertex v = {4.0f, 5.0f, 6.0f};
  vertices.push_back(v);
  // 使用引用避免复制数据
  printVector(vertices);
  std::cout << "=======" << std::endl;
  // 移除某个元素
  vertices.erase(vertices.begin() + 1); // 参数是一个迭代器 iterator
  printVector(vertices);
  // 清除数组，同时将数组大小设为 0
  vertices.clear();
}