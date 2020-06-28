#include <iostream>
#include <numeric>
#include <vector>

#include "mylog.h"

int main() {
  mylog::set_format("%l\n");
  mylog::info("INFO LOG");
  std::cout << 1 << std::endl;
}
