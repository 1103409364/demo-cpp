// 管理游戏中所有实体对象的类
#include <iostream>
#include <ostream>
class Entity {
public:
  float x, y;
  Entity() { x = y = 0.0f; };
  void move(float dx, float dy) {
    x += dx;
    y += dy;
  }
};
// 继承 Entity 类
class Player : public Entity {
public:
  const char *name;
  Player(const char *name) { this->name = name; };
  void printName() { std::cout << *name << std::endl; }
};

void testInheritance() {
  // Conversion from string literal to 'char *' is deprecated
  // C 和 C++ 在字符串字面量的类型上有所不同。在 C 中，类型是 char 数组，而在
  // C++ 中，类型是 char 常量数组。不推荐将字符串字面量转换为 'char *'
  // 前面加类型转换(char * "p1") 或者在构造形参加 const 关键字
  Player p1("p1");
  // 多态，是一个单一类型，但有多个类型的意思 p1 即是 Player 也是 Entity
  // 可以在任何使用 Entity 的地方使用 Player。Player 的东西比 Entity 多
  // 子类可以改变通过重写父类方法改变行为
  p1.move(1.1f, 2.1f);
  std::cout << sizeof(Player) << std::endl; // 16 32位系统是 12？
}