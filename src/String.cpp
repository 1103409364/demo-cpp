
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>

// 自定义 String 类，实现 std::string
class String {
private:
  char *m_Buffer;
  unsigned int m_Size;

public:
  String(const char *string) {
    m_Size = strlen(string);
    m_Buffer = new char[m_Size + 1]; // 预留终止符位置
    memcpy(m_Buffer, string, m_Size + 1);
    //一般有空终止字符。如果不能保证这一点的话，手动补 0 作为终止符
    m_Buffer[m_Size] = 0; //
  }
  // 默认提供的拷贝构造函数，它所做的就是内存复制，将other内存的成员【浅拷贝】到当前实例
  // String(const String &other) = delete 禁用构造拷贝
  // 浅拷贝导致共用 buffer，导致报错。需要自己【实现深拷贝】如下
  String(const String &other) : m_Size(other.m_Size), m_Buffer(other.m_Buffer) {
    std::cout << "copy:" << m_Buffer << std::endl;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 4);
  };
  ~String() {
    std::cout << "Destroy String" << std::endl;
    // 复制后，第二次触发析构报错：SIGABRT pointer being
    // freed was not allocated 浅拷贝 使用相同的 buffer 缓冲区
    // 导致第二次 delete 企图释放已释放的内存，报错
    // 解决方式：拷贝构造函数
    delete[] m_Buffer;
  }
  // 使用友元访问私有成员
  friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

std::ostream &operator<<(std::ostream &stream, const String &string) {
  stream << string.m_Buffer;
  return stream;
}
// 打印方法只要使用引用&，无需拷贝，这个函数无需改变 string，加 const 防止修改
void PrintString(const String &string) { std::cout << string << std::endl; }

void testString() {
  const std::string name2 = "May2";
  // printName 形参相当于做了如下的操作
  const std::string &name3 = name2;
  // 其他宽字符类型 不是所有编译器都支持
  const wchar_t *name4 = L"May";
  // const char16_t *name5 = u"May";
  // const char32_t *name6 = U"May";
  // const char *name7 = R"(line1
  // line2
  // line3)";

  // 测试 string 类
  String s1 = "Hey";
  String s2 = s1; // 浅拷贝 使用了相同的 buffer
  PrintString(s1);
  // std::cout << s2 << std::endl;
}