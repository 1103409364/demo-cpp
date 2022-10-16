#include <iostream>
#include <ostream>

struct Vector2 {
  float x, y;
};

struct Vector4 {
  // float x, y, z, w;
  union {
    // 包装在一个像这样的匿名结构体中，这个匿名结构体是一个 union 成员
    struct {
      float x, y, z, w;
    };
    // 一个 Vector4 等效于两个 Vector2
    // 让 PrintVector2 支持打印 Vector4
    struct {
      Vector2 a, b;
    };
  };
};
// 只能打印 Vector2，不能打 Vector4
void PrintVector2(const Vector2 &vector) {
  std::cout << vector.x << ", " << vector.y << std::endl;
}

void testUnion() {
  struct Union {
    // 如果这是一个结构体，就有两个成员
    union {
      float a;
      int b;
    };
  };

  Union u;
  u.a = 1.0f;
  std::cout << u.a << " - " << u.b << std::endl; // 1 - 1065353216
  // b 输出 1065353216是浮点数形式的1的字节表示，如果这有意义的话
  //这就好像我们取了浮点数的内存，然后把它解释成一个整型
  //这就是 union 可以做的，它通常被用来做类型双关：将内存中的数据转成其他类型

  Vector4 vector4 = {1.0f, 2.0f, 3.0f, 4.0f};
  PrintVector2(vector4.a);
  PrintVector2(vector4.b);
  vector4.z = 5000.0f;
  std::cout << " -------- " << std::endl;
  PrintVector2(vector4.a);
  PrintVector2(vector4.b);
}