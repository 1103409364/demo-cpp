#pragma once
// 井号开头的语句都被称为一个预处理命令，意味着他将在这个文件被编译之前被c++的pre
// processor评估。pragma其实是一个被输入到编译器或者说预处理器的指令。pragma
// once其实意思就是说只 include
// 这个文件一次。防止我们把单个头文件多次include到一个单一翻译单元（一个cpp文件）里

// 另一种方式使用条件编译。没有 #pragma once 简洁
// #ifndef _LOG_H // if not define 头文件保护符
// #define _LOG_H
#define PR_DEBUG 1 // 定义环境变量。1 开启 debug
void Log(const char *message);
void testPointer();
void testReference();
void testStatic();
void testClass();
void testEnum();
void testConstructor();
void testInheritance();
void testVirtualFun();
void testString();
void testConst();
void testOperatorOverloading();
void testThis();
void testScopePointer();
void testSmartPointer();
void testCopy();
void testArrowOperator();
void testVector();
void testUsingLibraries();
void testTemplate();
void testMacro();
void testAuto();
void testArray();
void testFunctionPointer();
void testThread();
void testTimer();
void testMultiArray();
// #endif