#include "common.h"
#include <iostream>

// #ifdef PR_DEBUG
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

void testMacro() { LOG(111); }