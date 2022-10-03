#include <iostream>
#include <ostream>
void testStatic() {
  static int i = 0;
  i++;
  int j = 0;
  j++;
  std::cout << "i =" << i << std::endl; // 每次调用 i 增长 1
  std::cout << "j =" << j << std::endl; // 每次调用 j 都是 1
}