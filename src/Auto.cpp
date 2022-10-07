#include "common.h"
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

class Device {};
class DeviceManager {
private:
  std::unordered_map<std::string, std::vector<Device *>> m_Devices;

public:
  const std::unordered_map<std::string, std::vector<Device *>> &
  GetDevices() const {
    return m_Devices;
  }
};

void testAuto() {
  auto i = 1;
  // 1 适合使用 auto 的例子
  std::vector<std::string> strings;
  strings.push_back("Apple");
  strings.push_back("V");
  // 迭代器的类型 std::vector<std::string>::iterator 很长，换成 auto 简洁很多
  for (auto it = strings.begin(); it != strings.end(); it++) {
    std::cout << *it << std::endl;
  }
  // 2 在看一个巨大类型的例子
  // 使用 using 优化
  using DeviceMap = std::unordered_map<std::string, std::vector<Device *>>;
  // 使用 typedef 定义别名
  // typedef std::unordered_map<std::string, std::vector<Device *>> DeviceMap;

  DeviceManager dm;
  const DeviceMap &d1 = dm.GetDevices();
  // 使用 auto
  const auto &d2 = dm.GetDevices(); // auto 不处理引用，需要自己加 &
}