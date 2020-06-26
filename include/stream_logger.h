#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "base_logger.h"
#include "constants.h"

namespace mylog {
class StreamLogger : public BaseLogger {
 protected:
  std::ostream os;

 public:
  StreamLogger(int level = ALL) : BaseLogger(level), os(std::cout.rdbuf()) {}
  StreamLogger(int level, std::ostream& other_os)
      : BaseLogger(level), os(other_os.rdbuf()) {}

  void log(int, std::string);
};
}  // namespace mylog
