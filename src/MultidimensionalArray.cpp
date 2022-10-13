#include <iostream>
#include <ostream>
void testMultiArray() {
  // 一维 array 是指针 int [50] 设置分配内存的大小，数组是一个内存块 4 * 50
  // bytes
  int *array = new int[50];

  // 二维 a2d 是指针，指向指针数组，每个指针指向一个数组，就是二维数组
  // a2d 有 50 个指针占用 4 * 50 bytes，每个指针指向一个数组。合计 50 * 4 * 50
  int **a2d = new int *[50];
  for (int i; i < 50; i++) {
    a2d[i] = new int[50]; //  = &a; 一样不会报错 int a = 1;
  }
  // 三维数组，指针指向指针数组的数组，每个指针指向指针数组
  int ***a3d = new int **[50];
  for (int i; i < 50; i++) {
    a3d[i] = new int *[50];
    for (int j; j < 50; j++) {
      // a3d 是一个指向【指针的指针】的指针 a3d[i] 对第一部分解引用
      // [j] 对第二部分解引用
      a3d[i][j] = new int[50]; //  = &a; 一样不会报错 int a = 1;
      // 和下面等效
      int **ptr = a3d[i];
      ptr[j] = new int[50];
    }
  }
  // 如果是在堆上分配的数组，需要遍历每个删除
  // 下面这样智能释放 200 字节内存。a2d只是保存50个 int 数组的指针【内存泄漏】
  // delete[] a2d;
  // 正确的删除
  for (int i; i < 50; i++) {
    delete[] a2d[i];
  }
  delete[] a2d;

  // 这样处理数组的数组，会造成内存碎片问题。多维数组被分配到连续内存上的概率很低
  // 优化策略，可以用一维数组处理。一维数组比多维数组更快。模拟二维数组
  int row = 5;
  int col = 5;
  int *arr = new int[row * col];
  for (int y; y < 5; y++) {
    for (int x = 1; x < row; x++) {
      arr[y * row + x] = 1;
    }
  }
}