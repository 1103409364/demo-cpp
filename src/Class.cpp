#include <iostream>
#include <ostream>
// 实现单例
class Singleton1 {
private:
  static Singleton1 *s_Instance;

public:
  static Singleton1 &GetIns() { return *s_Instance; } // 静态方法访问静态变量
  void Hello() { std::cout << "Hello World." << std::endl; }
};
// Non-const static data member must be initialized out of line
// 非const静态成员必须在外部初始化 声明实例，默认值为空指针
Singleton1 *Singleton1::s_Instance = nullptr;

// 使用局部静态变量实现单例
class Singleton2 {
public:
  static Singleton2 &GetIns() {
    static Singleton2 s_Instance;
    return s_Instance;
  };
  void Hello() { std::cout << "Hello World. 2" << std::endl; }
};

void testClass() {
  Singleton1::GetIns().Hello();
  Singleton2::GetIns().Hello();
  std::cin.get();
}