#include <iostream>
#include <ostream>
#include <string>

// 打印字符串时就需要重载一个 Print
// 每增加一个类型就需要重载一次，重复代码很多
// template 标记一个模版，并不是真正的函数。
// 只有当我们实际【调用时函数才被创建】
// 当我们调用这个函数的时候，基于传递的参数
// 这个函数才被创建出来，并作为源代码被编译
// typename/class 声明模版参数 T，可以在模版中使用
template <typename T> void Print(T value) { std::cout << value << std::endl; };
// 基于模板的使用情况，发送到编译器，进行编译后，才会具体化为真正的代码
// 模版里的代码报错是基于编译器的，因为还未产生真正的代码，ide 可能不会报错
// 有点像是C++的meta programming （元编程）

// 模版参数类型可以是任意类型，不一定是 type
// 这很酷，我们在这里创建的Array 与标准数组类在C++
// 标准模板库中的工作方式非常相似
template <typename T, int N> class Array {
private:
  // 这里可以使用alloca（动态分配栈内存）或者其他可以动态地增加内存
  T m_Array[N];

public:
  int GetSize() const { return N; }
};

void testTemplate() {
  Print<int>(5);
  Print(1.5f); // 自动类型推断
  Print<std::string>("May");

  Array<std::string, 11> array;
  Print(array.GetSize());
}