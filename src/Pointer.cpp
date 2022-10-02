#include <cstring>
#include <iostream>

void testPointer() {
  // 创建一个纯粹的指针 void *ptr = 0 不是一个有效的内存地址，这个指针无效
  // c11 可以使用nullptr
  void *ptr = nullptr;
  int b = 1;
  // 给一个指针一个类型，只是声明地址的数据可能是我们给它的类型，
  // 这个类型除了让编程更加容易之外没有其他意义
  int *bPtr = &b; // 取变量b的内存地址
  int c = *bPtr;  // 解引用 & 的反向操作，取内存地址对应的值
  *bPtr = 2;      // 解引用修改指针指向内存地址的值
  std::cout << ptr << std::endl;  // 0x0
  std::cout << bPtr << std::endl; // 0x16fdff400

  char *buffer = new char[8]; //动态分配具有不确定值的 char 数组，长度 10
  char *buffer2 = new char(8); //创建一个值为 8 的 char
  memset(buffer, 0, 8);

  char **ptr2 = &buffer; // 二级指针：指针的指针，还是整数
  delete[] buffer;       // new和delete都是在堆heap上操作内存
}