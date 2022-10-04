#include <iostream>
#include <ostream>
#include <string>
struct Vector2 {
  float x, y;
  Vector2(float x, float y) : x(x), y(y){};
  Vector2 Add(const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);
  };
  // 使用运算符重载 +
  Vector2 operator+(const Vector2 &other) const {
    // 也可以反过来，具体加逻辑在重载 operator+ 中实现，
    // 在 Add 方法中调用重载后的➕ *this + other 或 operator+(other)
    return Add(other);
  };
  Vector2 Multiply(const Vector2 &other) const {
    return Vector2(x * other.x, y * other.y);
  };
  // 重载 * 写法类似
  Vector2 operator*(const Vector2 &other) const { return Multiply(other); };
  // 重载 == java 中需要重写为 equal
  bool operator==(const Vector2 &other) const {
    // 由于浮点数的表示是不精确的，一般不能直接比较两个数是否完全相等
    return x == other.x && y == other.y;
  }
  bool operator!=(const Vector2 &other) const { return *this == other; }
};

// 重载左移运算符 << 打印 Vector2 对象，如同在 java 中重写 toString
// << 接收两个参数运算符左边和右边的操作数，返回 ostream 引用
std::ostream &operator<<(std::ostream &stream, const Vector2 &other) {
  return stream << other.x << ", " << other.y;
}

void testOperatorOverloading() {
  Vector2 position(4.0f, 4.0f);
  Vector2 speed(0.5f, 0.5f);
  Vector2 powerup(1.1f, 1.1f); // 提速
  // 在其他语言如 java 中实现这个需求，只能这样写
  Vector2 result1 = position.Add(speed.Multiply(powerup));
  // C++有运算有符重载，这意味着我们可以利用这些运算符，并定义我们自己的运算符：
  Vector2 result2 = position + speed * powerup; // 和 result1 等效
  bool isEqual = result1 == result2;
  std::cout << isEqual << std::endl;
  // 支持打印 Vector2 对象
  std::cout << result2 << std::endl;
}