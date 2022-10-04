
#include <iostream>
#include <string>
using namespace std;

void printName(const char *name) { cout << "name:" << name << endl; };
void printName(const string &name) { cout << "name2:" << name << endl; };

void testString() {
  const char *name = "May";
  printName(name);

  const string name2 = "May2";
  printName(name2);
  // printName 形参相当于做了如下的操作
  const string &name3 = name2;
  // 其他宽字符类型 不是所有编译器都支持
  const wchar_t *name4 = L"May";
  // const char16_t *name5 = u"May";
  // const char32_t *name6 = U"May";
  // const char *name7 = R"(line1
  // line2
  // line3)";
}