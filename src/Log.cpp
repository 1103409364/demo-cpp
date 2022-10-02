#include <iostream>

void Log(const char *message) {
  std::cout << "call Log" << std::endl;
  std::cout << message << std::endl;
}

void Log(const int message) {
  std::cout << "call Log" << std::endl;
  std::cout << message << std::endl;
}