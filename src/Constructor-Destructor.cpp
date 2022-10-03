#include <iostream>
#include <ostream>
class Entity {
private: // 默认私有
  float x;

public:
  float y;
  // Entity() = delete; // 告诉编译器，不想要默认的构造函数
  // Entity() { this->x = 1.0f; };
  Entity(float x) {
    this->x = x; // private 成员需要用 this 访问
    y = x;
  };
  ~Entity() {
    // 控制台打印了两次
    std::cout << "call Destructor" << std::endl;
  };
  float getX() {
    // return this->x
    // return (*this).x;
    return x;
  };
  float getY() { return y; };
};

void testConstructor() {
  // Entity e1;
  Entity e2(1.1f);
  Entity e3 = *new Entity(1.1f);
  float f = e2.getX();
  std::cout << e2.getX() << std::endl;
  std::cout << e3.getX() << std::endl;
  std::cout << e3.getY() << std::endl;
}