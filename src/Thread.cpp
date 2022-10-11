#include <chrono>
#include <iostream>
#include <ostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {
  using namespace std::literals::chrono_literals;
  while (!s_Finished) {
    std::cout << "Working...\n";
    // std::chrono::milliseconds(1000) 挂起线程，防止 cpu 占用过高
    std::this_thread::sleep_for(1s);
  }
};

void testThread() {
  // 启动线程 传递引用
  std::thread worker(DoWork);
  std::cin.get();
  s_Finished = true;

  // 在当前线程上等待一个线程完成它的工作，后面的代码不会执行，直到 DoWork 结束
  worker.join();
  std::cout << "Finished\n";
  std::cin.get();
}