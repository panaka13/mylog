#include <iostream>
#include <numeric>
#include <vector>

#include "api.h"
#include "configure.h"

int main() {
  mylog::log(DEBUG) << "DEBUG" << std::endl;
  mylog::filter_log(DEBUG);
  std::cout << 1 << std::endl;
}
