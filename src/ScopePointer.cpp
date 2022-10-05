#include <iostream>
#include <ostream>
namespace sp {
class Entity {
public:
  Entity() { std::cout << "create entity" << std::endl; }
  ~Entity() { std::cout << "destroy entity" << std::endl; }
};
} // namespace sp

class ScopePointer {
private:
  sp::Entity *ptr;

public:
  ScopePointer(sp::Entity *ptr) : ptr(ptr) {}
  ~ScopePointer() { delete ptr; }
};
// 利用作用域超出后自动销毁机制实现自动 delete 堆对象
void testScopePointer() {
  {
    // 隐式转换等效于 p(new Entity()); 约等于 new ScopePointer(new Entity())
    ScopePointer p = new sp::Entity();
  }
}
