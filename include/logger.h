#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "constants.h"

namespace mylog {
class Logger {
 protected:
  int level;
  std::ostream os;

 public:
  Logger(int level) : level(level), os(std::cout.rdbuf()) {}
  Logger(int level, std::string filename)
      : level(level), os(std::ofstream(filename).rdbuf()) {}
  Logger(int level, std::ostream &os) : level(level), os(os.rdbuf()) {}

  ~Logger() { os.flush(); }

  static std::shared_ptr<Logger> get_logger();

  static std::shared_ptr<Logger> create_logger(int level, std::ostream &os);

  static std::shared_ptr<Logger> create_logger(int level, std::ostream &&os);

  static std::shared_ptr<Logger> create_logger(int level) {
    return create_logger(level, std::cout);
  }

  static std::shared_ptr<Logger> create_logger(int level,
                                               std::string filename) {
    return create_logger(level, std::ofstream(filename));
  }

  void log(int level, std::string message);
};
}  // namespace mylog
