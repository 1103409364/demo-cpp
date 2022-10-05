#include <iostream>
#include <ostream>
namespace sp {
class Entity {
public:
  Entity() { std::cout << "create entity" << std::endl; }
  ~Entity() { std::cout << "destroy entity" << std::endl; }
  void Print() { std::cout << "Print Entity" << std::endl; }
  void Print() const { std::cout << "const Print Entity" << std::endl; }
};
} // namespace sp

class ScopePointer {
private:
  sp::Entity *ptr;

public:
  ScopePointer(sp::Entity *ptr) : ptr(ptr) {}
  ~ScopePointer() { delete ptr; }
  sp::Entity *GetObj() { return ptr; }
  // 重载箭头操作符
  sp::Entity *operator->() { return ptr; }
  sp::Entity const *operator->() const { return ptr; }
};
// 利用作用域超出后自动销毁机制实现自动 delete 堆对象
// 重载 -> 操作符使代码更加简洁
void testScopePointer() {
  {
    // 隐式转换等效于 p(new Entity()); 约等于 new ScopePointer(new Entity())
    ScopePointer p = new sp::Entity();
    p.GetObj()->Print();
    ScopePointer e1 = new sp::Entity();
    e1->Print();
    const ScopePointer e2 = new sp::Entity();
    e2->Print(); // const指针只能调用const方法
  }
}
