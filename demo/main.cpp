#include <iostream>
#include <numeric>
#include <vector>

#include "mylog.h"

int main() {
  mylog::daily_log("./");
  mylog::info("INFO LOG");
}
