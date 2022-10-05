#include <iostream>
#include <memory>
#include <ostream>

namespace smp {
class Entity {
public:
  Entity() { std::cout << "Create Entity" << std::endl; }
  ~Entity() { std::cout << "destroy entity" << std::endl; }
  void Print() { std::cout << "Entity" << std::endl; };
};
} // namespace smp

void testSmartPointer() {
  {
    // 不能使用 e = new smp::Entity();
    // 因为它的构造是 explicit unique_ptr(pointer __p)
    // explicit 需要显示调用构造，没有隐式转换
    std::unique_ptr<smp::Entity> e1(new smp::Entity());
    // No member named 'make_unique' clangd 插件问题？
    // 最好的方式是调用make_unique，因为如果构造函数碰巧抛出异常，不会得到一个没有引用的悬空指针从而造成内存泄露，更安全
    std::unique_ptr<smp::Entity> e2 = std::make_unique<smp::Entity>();
    // std::unique_ptr<smp::Entity> e2 = std::unique_ptr<smp::Entity>(new
    // smp::Entity());
    e1->Print();
    e2->Print();
    // 共享指针 使用引用计数
    std::shared_ptr<smp::Entity> e4 = std::make_shared<smp::Entity>();
    std::shared_ptr<smp::Entity> e5 = e4;
    e4->Print();
    e5->Print();
    // 弱引用指针，将一个shared_ptr赋值给 weak_ptr 不会增加引用计数
    std::weak_ptr<smp::Entity> e6 = e4;
  }
  // 超出作用域自动销毁
  // error: Use of undeclared identifier 'e'
  // e->Print();
}