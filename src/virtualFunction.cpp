
#include <iostream>
#include <ostream>
#include <string>
using namespace std;
// 打印类名接口
class Printable {
public:
  virtual void showClassName() = 0;
};
// 不加 public 报错：Implicitly declared private here 在这里隐式声明为私有
class Entity2 : public Printable {
public:
  // virtual void showName() { cout << "Entity2" << endl; };
  virtual void showName() = 0; // 纯虚函数：无方法体加 = 0，必须在子类中实现
  void showClassName() override { cout << "Entity2" << endl; };
};

class Player2 : public Entity2 {
private:
  string m_name;

public:
  // : 后面是初始化成员
  Player2(const string &name) : m_name(name) {}
  // 'override' keyword is a C++11 extension
  void showName() override { cout << m_name << endl; };
  void showClassName() override { cout << "Player" << endl; };
};
// 形参为指针，虚调用才会有这种多态效果。
void printName(Entity2 *e) {
  // 报错：EXC_BAD_ACCESS (code=1, address=0x0)
  // 原因：虚函数调用失败，其他文件的同名类干扰
  e->showName(); // Entity
}

// 打印类名
void Print(Printable *obj) { obj->showClassName(); }

void testVirtualFun() {
  // 改为纯虚函数后报错：Allocating an object of abstract class type 'Entity2'
  // Entity2 *e = new Entity2();
  // printName(e); // Entity2
  Player2 *p = new Player2("p");
  Print(p);

  p->showName(); // p
  printName(p);  // Entity2 使用虚函数后 打印 p
  // 使用多态时导致问题。这就是虚函数的使用场景，虚函数引入了一种叫做Dynamic
  // Dispatch(动态调度) 的东西，它通常通过v表（虚函数表）来实现编译，
  // v表就是一个表，它包含基类中所有虚函数的映射，这样我们可以在它运行时，
  // 如果你想覆写一个函数将它们映射到正确的重写(override)函数,
  // 必须将基类中的基函数标记为虚函数

  // 改为纯虚函数后报错：Variable type 'Entity2' is an abstract class
  // Entity2 p2 = *p;
  // p2.showName(); // Entity2
  Entity2 *p3 = new Player2("p");
  p3->showName(); // p
}

class A {
public:
  virtual void show() { cout << "in A" << endl; }
};

class B : public A {
public:
  void show() { cout << "in B" << endl; }
};
// 实调用
void func(A a) { a.show(); } // in a
// 虚调用
void func(A *a) { a->show(); } // in b

void testVirtualFun2() {
  B b;
  func(b);
  func(&b);
}

// 程序运行输出结果是：in A。在函数func()中，虽然在class
// A中函数show()被定义为虚函数，但是由于a是类A的一个示例，
// 而不是指向类A对象的指针或者引用，所以函数调用a.show()
// 是【实调用】，函数的入口地址是在编译阶段静态决定的