#include <chrono>
#include <iostream>
#include <ostream>
#include <thread>
// chrono库 可以高精度计时，它几乎适用于所有平台
// 使用这个方法来满足你所有的时间（计时）需求
// 除非你正在做一些特定的底层的事情。99％的情况下
// 使用std::chrono就行了

// 利用对象生存周期自动计时
struct Timer {
  std::chrono::time_point<std::chrono::steady_clock> start, end;
  std::chrono::duration<float> duration;

  Timer() { start = std::chrono::high_resolution_clock::now(); }
  ~Timer() {
    end = std::chrono::high_resolution_clock::now();
    duration = (end - start) * 1000.0f;
    std::cout << "Timer took " << duration.count() << "ms " << std::endl;
  }
};

void testTimer() {
  Timer timer;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}