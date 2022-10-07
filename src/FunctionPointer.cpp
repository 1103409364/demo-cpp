#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// 实现一个 forEach。支持更多类型可以使用 template
void forEach(std::vector<int> vec, void (*func)(int i)) {
  for (const int i : vec) {
    func(i); // 这里也有隐式转换 (*func)(i);
  }
};

void log(int x) { std::cout << x << std::endl; }

void testFunctionPointer() {
  std::vector<int> vector = {1, 2, 3, 4};
  forEach(vector, log); // 传参，隐式传换，函数转函数指针
  forEach(vector, [](int x) {
    std::cout << "lambda" << x << std::endl;
  }); // lambda 表达式
};