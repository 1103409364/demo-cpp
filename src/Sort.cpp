#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <vector>

void LogVector(std::vector<int> &values) {
  for (int value : values) {
    std::cout << value << std::endl;
  }
}

void testSort() {
  std::vector<int> values = {3, 4, 565, 2, 5, 44};
  // 从大到小
  std::sort(values.begin(), values.end(), std::greater<int>());
  LogVector(values);

  // 使用 lambda 提供一个比较器 从小到大排序
  std::sort(values.begin(), values.end(),
            [](int a, int b) { return a - b < 0; });
  LogVector(values);
}