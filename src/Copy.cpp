#include <iostream>
#include <ostream>
namespace copy {
struct Vector2 {
  float x, y;
};
} // namespace copy

void testCopy() {
  // 复制值
  copy::Vector2 v1 = {1, 2};
  copy::Vector2 v2 = v1;
  v2.x = 22;
  std::cout << v1.x << std::endl; // 1 v1 v2 是独立的对象，互相不影响
  // 复制指针
  copy::Vector2 *v3 = new copy::Vector2();
  copy::Vector2 *v4 = v3; // 指向一个内存区
  v4->x = 55;
  std::cout << v3->x << std::endl; // 55
}