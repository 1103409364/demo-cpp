#include <iostream>
#include <GLFW/glfw3.h>
// extern "C" int glfwInit(); // extern "C" 链接到 c 库
void testUsingLibraries()
{
  int a = glfwInit();
  std::cout << "GLFW:" << a << std::endl;
};