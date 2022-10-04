
#include <iostream>
using namespace std;

// 在类中使用 const 通常用在 get 方法，承诺不会修改类实例成员
class Entity1004 {
private:
  int m_X, m_Y;
  // m_X2 是指针，m_Y2 依然是int 不是指针。m_Y2前面加* 才是指针
  int *m_X2, m_Y2;
  // 标记为mutable的变量可以在 const 方法中修改。用于调试等
  mutable int var;

public:
  // const 这个方法不会修改任何实际的类，因此您可以看到我们不能修改类成员变量
  int GetX() const {
    // error: Member function 'Entity1004::GetX' is declared const here
    // m_X = 1;
    var = 123;
    return m_X;
  };
  // 三个 const 作用：
  // 1 返回指针指向的内容不能被修改
  // 2 返回一个不能被修改的指针
  // 3 这个方法不能修改实例的成员
  const int *const GetX2() const { return m_X2; };
  void SetX(int x) { m_X = x; }
};

void PrintEntity1004(const Entity1004 &e) {
  // 引用是常量指针常量，指向的内容和本身都不能修改
  cout << e.GetX() << endl;
}

void testConst() {
  // 常量指针 不能改变 指针指向的内存的内容
  const int *a1 = new int;
  int const *a11 = new int; // 常量指针等效写法

  // 指针常量 不能把指针本身重新赋值，指向别的地方
  int *const a2 = new int;
  // 常量指针（常量的指针） 和 指针常量关键在于，const 在 * 前面还是后面。
  // 指针和内容都不能修改
  const int *const a3 = new int;
  cout << *a1 << endl; // 0
  cout << *a3 << endl; // 0
  // 在类中使用 const
}