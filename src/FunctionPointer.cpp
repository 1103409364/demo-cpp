#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// 实现一个 forEach。支持更多类型可以使用 template
void forEach(std::vector<int> &vec, void (*func)(int i)) {
  for (const int i : vec) {
    func(i); // 这里也有隐式转换 (*func)(i);
  }
};

void forEach2(std::vector<int> &vec, std::function<void(int)> func) {
  for (const int i : vec) {
    func(i);
  }
};

void log(int x) { std::cout << x << std::endl; }

void testFunctionPointer() {
  std::vector<int> values = {1, 2, 3, 4};
  forEach(values, log); // 传参，隐式传换，函数转函数指针
  forEach(values, [](int x) {
    std::cout << "lambda: " << x << std::endl;
  }); // lambda 表达式

  int a = 1;
  auto f = [=](int x) mutable {
    a = 5; // mutable允许修改外部值
    std::cout << "lambda: " << x + a << std::endl;
  };
  forEach2(values, f);

  auto it = std::find_if(values.begin(), values.end(), [](int value) {
    // 找第一个大于 2 的
    return value > 2;
  });

  std::cout << "result: " << *it << std::endl; // 3
};