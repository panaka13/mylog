#pragma once

#include <iostream>

#include "constants.h"
#include "logger.h"

namespace mylog {

  void set_log(std::ostream os);

  void filter_log(int level);

  void debug(std::string message);

  void info(std::string message);

  void warn(std::string message);

  void error(std::string message);

  void fatal(std::string message);

} // namespace mylog
