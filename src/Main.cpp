// #include <iostream>
// using namespace std;

// int main() {
//   int a = 'A';
//   char a2 = 65;
//   short a3 = 65;
//   float a4 = 1.1;  // 实际定义的是 (double)(1.100000000000000089)
//   double a5 = 1.2;
//   float a6 = 1.1f;  // (float)(1.100000024F)
//   bool a7 = true;
//   // 有了基本数据类型可以将它们转换为指针 (pointer)或引用 (reference)
//   //
//   //
//   每一个变量都有一个内存位置，可使用（&）运算符访问的地址，它表示了在内存中的一个地址。
//   bool* a8 = &a7;

//   cout << a << "\n";                // 65
//   cout << a2 << "\n";               // A
//   cout << a3 << "\n";               // 65
//   cout << a4 << "\n";               // 1.1
//   cout << a5 << "\n";               // 1.2
//   cout << a6 << "\n";               // 1.1
//   cout << a7 << "\n";               // true
//   cout << sizeof(a5) << "bytes\n";  // 8bytes sizeof 检查一个类型咋用多大空间
//   cout << sizeof(long double) << "bytes\n";  // 8bytes
//   cout << a8 << "\n";                        // 0x16fdff1b3
//   cin.get();
// }
#include "../include/common.h"
#include <iostream>
using namespace std;

int main() {
  // testPointer();
  // testReference();
  // testStatic();
  // testStatic();
  // testClass();
  // testEnum();
  // testConstructor();
  // testInheritance();
  // testVirtualFun();
  // testString();
  // testConst();
  // testOperatorOverloading();
  // testThis();
  // testScopePointer();
  testSmartPointer();
  // cin.get(); // 执行完不退出
}
