#include <iostream>
#include <numeric>
#include <vector>

#include "mylog.h"

int main() {
  mylog::set_format("%l\n");
  mylog::daily_log("./", "%Y_%m_%d.log");
  mylog::info("INFO LOG");
}
