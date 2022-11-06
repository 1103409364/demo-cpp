#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

struct AllocationMetrics {
  // 分配的内存
  uint32_t TotalAllocated = 0;
  // 释放的内存
  uint32_t TotalFreed = 0;

  uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AAllocationMetrics;

// 重载操作符 new delete
void *operator new(size_t size) {
  s_AAllocationMetrics.TotalAllocated += size;
  // std::cout << "Allocating new " << size << " bytes\n";
  return malloc(size);
};

void operator delete(void *memory) throw() {
  std::cout << "Freeing delete\n";
  free(memory);
};
// TODO:clang 没有调，gcc 有效。是编译器的差异 的差异：
// https://stackoverflow.com/questions/56368799/operator-delete-with-size-parameter-and-without-size-parameter-which-one-is-c
void operator delete(void *memory, std::size_t size) throw() {
  std::cout << "Freeing delete " << size << " bytes\n";
  s_AAllocationMetrics.TotalFreed += size;
  free(memory);
};

struct Object {
  int x, y, z;
};

static void PrintMemoryUsage() {
  std::cout << "Memory Usage: " << s_AAllocationMetrics.CurrentUsage()
            << " bytes\n";
};
// https://zhuanlan.zhihu.com/p/354046948
void testMemoryAllocations() {
  // 使用 new 在堆上分配内存
  std::string string = "2313"; // new std::string("xx546456x");
  PrintMemoryUsage();
  {
    std::unique_ptr<Object> obj = std::make_unique<Object>();
    PrintMemoryUsage();
  }
  PrintMemoryUsage();
  std::cout << "End \n";
  // 重载后 delete 不能手动调用
};