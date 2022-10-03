#include <iostream>
#include <ostream>
enum Example1 { A, B = 11, C };
// 指定你想要给枚举赋值的 [整数] 类型 short long char等，默认 int
enum Example2 : unsigned char { D, E, F = 'b' };
void testEnum() {
  Example1 e = B;
  if (e == 11) {
    std::cout << B << " SIZE:" << sizeof(B) << std::endl;
  }

  int a = 1;
  if (a == B) {
    std::cout << "a is 1" << std::endl;
  }
  std::cout << F << std::endl;
}