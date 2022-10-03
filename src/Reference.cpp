#include "../include/common.h"
#include <iostream>

// 入参 使用指针
void Increment(int *value) {
  // *value = *value + 1;
  (*value)++; //不加括号会把内存地址++
}
// 入参 使用引用
void Increment2(int &value) {
  // 更简单，不用加括号。无需解引用之类的
  value++;
}

void testReference() {
  // 指针和引用基本上是一回事，当然，我们如何写它们，怎么用它们还是有一些不同的。
  // 但是最终来看，引用就是指针，他俩就是一回事
  // “引用变量”必须引用一个已存在的变量，它本身并不是一个新的变量。
  // 它只是其他变量的引用而不是一个真正的变量。
  int a = 0;
  int *b = &a;
  // 不需要取引用操作，只要一个已存在的变量，现在可以把ref当成a用，ref是a的别名
  int &ref = a; // 引用声明和取引用使用了同一个符号
  // 当你声明一个引用时，你必须立刻给它赋值，因为它必须是某物的引用
  std::cout << ref << std::endl;
  Increment(&a); // 通过指针修改
  std::cout << ref << std::endl;
  // 使用引用修改 a，引用是一种语法糖，让代码更具可读性
  Increment2(a);
  std::cout << ref << std::endl;
}
