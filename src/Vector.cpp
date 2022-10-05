#include <iostream>
#include <ostream>
#include <vector>
struct Vertex {
  float x, y, z;
  Vertex(float x, float y, float z) : x(x), y(y), z(z) {}
  // 自定义 constructor 拷贝函数，覆盖默认的。观察拷贝
  Vertex(const Vertex &vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {
    // 第一次copy：当我们创建vertex时，实际上是在当前函数的当前栈帧中构造它，然后从当前函数中把它放到实际的vector分配的内存中
    // 优化：直接在vector的实际内存中创建元素 push_back 改用 emplace_back。
    // 区别：push_back 需要传健好之后放入，emplace_back 传参不用预先创建
    // vector默认分配容量1，每次重新分配只加1，造成了更多次的copy。
    // 优化：初始化需要的容量 vertices(int size) 或者 vertices.reserve(int size)
    std::cout << "Copied!" << std::endl; // 3次 Copied ! 优化后 0 copy
  }
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
  vertices.reserve(3);            // 预设容量，减少 copy
  vertices.emplace_back(1, 2, 3); // push_back(Vertex(1.0f, 2.0f, 3.0f));
  vertices.emplace_back(4, 5, 4);
  vertices.emplace_back(7.0f, 8.0f, 9.0f);
  // 使用引用避免复制数据
  printVector(vertices);
  std::cout << "=======" << std::endl;
  // 移除某个元素
  vertices.erase(vertices.begin() + 1); // 参数是一个迭代器 iterator
  printVector(vertices);
  // 清除数组，同时将数组大小设为 0
  vertices.clear();
}