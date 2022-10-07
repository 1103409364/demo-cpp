#include <algorithm>
#include <array>
#include <iostream>
#include <ostream>
#define _LIBCPP_DEBUG = 1

// 使用模版，避免在声明形参时需要写数组长度
template <typename T, int N> void Print(std::array<T, N> &array) {
  for (const int item : array) {
    std::cout << item << std::endl;
  }
  std::cout << "array size:" << array.size() << std::endl;
}

void testArray() {
  std::array<int, 10> arr;
  arr.fill(1);
  arr[5] = 22;
  arr[1111] = 111;

  Print<int, 10>(arr);
}